package Compression  

import chisel3._
import chisel3.util._
import Compression.Golomb.HeadDiff
import Compression.Golomb.TailDiff

object Golomb {

  private def MuxStatement(a: MixedVec[UInt], b: MixedVec[UInt]): MixedVec[UInt] = {
    val aValid = a(0)
    val bValid = b(0)
    val aValue = a(1)
    val bValue = b(1)
    
    val outValid = Mux(aValid.asBool && bValid.asBool,
      Mux(aValue < bValue, aValid, bValid),
      Mux(aValid.asBool, aValid, Mux(bValid.asBool, bValid, 0.U(1.W)))
    )
    
    val outValue = Mux(aValid.asBool && bValid.asBool,
      Mux(aValue < bValue, aValue, bValue),
      Mux(aValid.asBool, aValue, Mux(bValid.asBool, bValue, 0.U(4.W)))
    )
    
    MixedVecInit(Seq(outValid, outValue))
  }


 def CalcGolomb(quotiant: UInt): (UInt, UInt, Bool) = {
  
    val length = 12 
    val quotiantVec = VecInit((0 until length).map(i => i.U < quotiant))
    //val cat = quotiantVec.reduceTree((x, y) => Cat(x,y))
    val cat = quotiantVec.asUInt

    val zerovalidVec = VecInit((0 until length).map(i => i.U >= quotiant))
  
    val scalaVector = zerovalidVec.zipWithIndex
    .map {case (valid, i) => MixedVecInit(valid, i.U(4.W)) }
  
    val indexRes = VecInit(scalaVector).reduceTree ((x, y) => MuxStatement(x,y))
  
    val indexValid = indexRes(0).asBool
    val index = indexRes(1) 
  
    return (cat, index, indexValid)
  }

  def GenWriteString(quotient: UInt, remainder: UInt, k: UInt, offset: UInt): (UInt, UInt, Bool, UInt) = {

    val writeString = Wire(UInt(36.W))
    val writeMask = Wire(UInt(36.W))

    val (cat, index, done) = CalcGolomb(quotient)

    when(done) {
      // Mask remainder to keep only k bits
      val remainderMask = (1.U << (k + 1.U)) - 1.U
      val maskedRemainder = remainder & remainderMask
      
      // Combine: shift quotient left by k bits, then OR with masked remainder
      val combined = (cat << (k + 1.U)) | maskedRemainder
      
      writeString := combined << offset
    }.otherwise {
      // Only use cat value without remainder concatenation, accounting for offset
      writeString := cat << offset
    }

    //val fillLength = index + k + 1.U
    val fillLength = Mux(done, index + k, 11.U)
    
    // Create mask with fillLength number of 1's using right shift
    //writeMask := ~((~0.U(36.W)) << fillLength)
    writeMask := ((1.U << (fillLength + 1.U)) - 1.U) << offset

  
    return (writeString, writeMask, done, fillLength)
  }


  def SignedMap(signed: SInt): UInt = {

    val unsignedDiff = Wire(UInt(12.W))

    when(signed >= 0.S){
      unsignedDiff := (signed << 1).asUInt
    }.otherwise{
      unsignedDiff := (((-signed).asUInt << 1) - 1.U).asUInt         // negative: -n -> 2n-1
    } 

    return unsignedDiff
  }


  def HeadDiff(implicit headReg: UInt, headFlip: Bool, tailReg: UInt, tailFlip: Bool): UInt = {
    val diff = Mux(headFlip === tailFlip,
      headReg - tailReg,  // Normal case: head > tail
      (headReg + (1.U << headReg.getWidth) - tailReg)  // Wrapped case: head < tail due to overflow
    )
    diff
  }


  def TailDiff(implicit headReg: UInt, headFlip: Bool, tailReg: UInt, tailFlip: Bool): UInt = {
    val diff = Mux(headFlip === tailFlip,
      tailReg - headReg,  // Normal case: tail - head (reverse of HeadDiff)
      (tailReg + (1.U << tailReg.getWidth) - headReg)  // Wrapped case: tail - head with overflow consideration
    )
    diff
  }
}

class GolombEncode(implicit c: Configuration) extends Module {
  val io = IO(new Bundle {
    val request = Flipped(Decoupled(new Bundle {
      val diff = SInt(12.W) 
    }))
    val k_override = Flipped(Valid(UInt(4.W)))
    val out = new SimplePort(UInt(12.W), 8)
  })

  val stateReg = RegInit(0.U(2.W))
  val diffReg = RegInit(0.S(12.W))
  val kReg = RegInit(3.U(4.W))

  val headReg = RegInit(0.U(5.W))
  val headFlip = RegInit(0.U(1.W))

  val tailReg = RegInit(0.U(5.W))
  val tailFlip = RegInit(0.U(1.W))

  // Registers to save values for wait state 2.U
  val writeStringReg = RegInit(0.U(36.W))
  val writeMaskReg = RegInit(0.U(36.W))
  val fillReg = RegInit(0.U(4.W))
  val doneReg = RegInit(false.B)

  val bufferCountReg = RegInit(0.U(2.W))
  val buffer = RegInit(0.U(36.W))
  val bufferout = VecInit((0 until 3).map(i => buffer((i * 12 + 11), (i * 12))))

  // Default values
  io.request.ready := false.B
  io.out.request.valid := false.B
  io.out.request.bits.data := 0.U

  switch(stateReg) {
    is(0.U) {
      io.request.ready := true.B

      when(io.request.valid) {
        diffReg := io.request.bits.diff
        stateReg := 1.U
      }
    }
    is(1.U) {
      val unsignedDiff = Golomb.SignedMap(diffReg)
      val quotient = (unsignedDiff >> kReg) 
      val remainder = (unsignedDiff & ((1.U << kReg) - 1.U))

      /*
      when(io.k_override.valid){
        val (writeString, writeMask, done, fill) = Golomb.GenWriteString(quotient, remainder, io.k_override.bits, headReg)
      } .otherwise {
        val (writeString, writeMask, done, fill) = Golomb.GenWriteString(quotient, remainder, kReg, headReg)
      }
      */

      val k = Mux(io.k_override.valid, io.k_override.bits , kReg)

      val (writeString, writeMask, done, fill) = Golomb.GenWriteString(quotient, remainder, k, headReg)



      // Perform write onto buffer
      buffer := (buffer & ~writeMask) | (writeString & writeMask)

      when(TailDiff(headReg, headFlip.asBool, tailReg, tailFlip.asBool) >= fill) {
        when(headReg + fill > 35.U){
          headReg := (headReg + fill) - 35.U
          headFlip := ~headFlip
        } .otherwise {
          headReg := headReg + fill
        }

        when(done) {
          stateReg := 0.U
        } .otherwise { // Continue to fill buffer until write is done  
          stateReg := 1.U
        }
      } .otherwise {
        // Transition to wait state 2.U, and wait until diff is low enough
        // Save Golomb string values in registers
        writeStringReg := writeString
        writeMaskReg := writeMask
        fillReg := fill
        doneReg := done
        stateReg := 2.U
      }

    }
    is(2.U) {
      // Wait state: check if there's enough buffer space using saved values
      when(TailDiff(headReg, headFlip.asBool, tailReg, tailFlip.asBool) >= fillReg) {
        // Perform write onto buffer using saved values
        buffer := (buffer & ~writeMaskReg) | (writeStringReg & writeMaskReg)

        // Update head pointer
        when(headReg + fillReg > 35.U){
          headReg := (headReg + fillReg) - 35.U
          headFlip := ~headFlip
        } .otherwise {
          headReg := headReg + fillReg
        }

        // Transition based on saved done flag
        when(doneReg) {
          stateReg := 0.U
        } .otherwise { 
          stateReg := 1.U
        }
      }
    }
  }

  //when(offset > (bufferCountReg * 12)) {
  when(HeadDiff(headReg, headFlip.asBool, tailReg, tailFlip.asBool) >= 12.U) {
    when(io.out.request.ready) {
      io.out.request.valid := true.B
      io.out.request.bits.data := bufferout(bufferCountReg) 


      when(tailReg + 12.U >= 35.U){
        tailReg := tailReg + 12.U - 35.U
        tailFlip := ~tailFlip
        bufferCountReg := 0.U
      } .otherwise {
        tailReg := tailReg + 12.U
        bufferCountReg := bufferCountReg + 1.U
      }
    }
  }
}
