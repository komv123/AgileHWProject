package Compression  

import chisel3._
import chisel3.util._

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

  def GenWriteString(quotient: UInt, remainder: UInt, k: UInt, offset: UInt): (UInt, UInt, Bool) = {

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

  
    return (writeString, writeMask, done)
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
}

class Compression(config: Configuration) extends Module{
//class Compression() extends Module{
  implicit val c = config

  val io = IO(new Bundle{
    val in = new SimplePort(UInt(12.W), 8)
    val out = Flipped(new SimplePort(UInt(12.W), 8))
  })

  val InputBuffer = Module(new BufferFIFO(4, UInt(12.W))) // Compensates for the depth of the Diff pipeline in the case of stall
  val Diff = Module(new Diff())


  ////////////////////////////////////////////////////////////////////////////////


  Diff.io.in.valid := io.in.request.valid  
  Diff.io.in.bits := io.in.request.bits.data  

  io.in.request.ready := io.out.request.ready

  InputBuffer.io.WriteData.valid := Diff.io.delta.valid
  InputBuffer.io.WriteData.bits := Diff.io.delta.bits


  ////////////////////////////////////////////////////////////////////////////////

  val Buff = RegInit(0.U(12.W))
  val KReg = RegInit(3.U(4.W))

  // Vector of 2 12-bit integers.
  //val buffer = Reg(Vec(2, UInt(12.W)))
  val buffer = Reg(UInt(36.W)) // Buffers 3 writes 

  // Vector of 8 12-bit integers.
  //val offset = Reg(Vec(8, UInt(4.W)))
  val offset = RegInit(0.U(5.W)) 


  when(InputBuffer.io.ReadData.request.ready){
    InputBuffer.io.ReadData.request.valid := true.B
  }

  val stateReg = RegInit(0.U(4.W))
  val diffReg = RegInit(0.S(12.W))

  switch(stateReg){
    is(0.U){
      when(InputBuffer.io.ReadData.request.ready){
        InputBuffer.io.ReadData.request.valid := true.B
        diffReg := InputBuffer.io.ReadData.response.bits.readData
      }

      stateReg := 1.U
    }
    is(1.U){
      val dividend = Wire(UInt(13.W)) 
      val remainder = Wire(UInt(13.W)) 

      // Transform signed diffReg to unsigned for Golomb-Rice encoding
      // Mapping: 0→0, -1→1, 1→2, -2→3, 2→4, -3→5, 3→6, etc.
      val unsignedDiff = Golomb.SignedMap(diffReg)

      dividend := (unsignedDiff >> KReg) 
      remainder := (unsignedDiff & ((1.U << KReg) - 1.U))

      val totalLength = dividend + KReg

      when(totalLength < 11.U){ // Compressed delta fits in less than one 12 bit word
        //val Write = Cat("b000000",remainder(5,0)).asUInt(12.W)
      } .elsewhen(totalLength === 11.U) { // Compressed delta fits in one 12 bit word

      } .otherwise {

      }


      



    }
  }






  









  





  










  






}
