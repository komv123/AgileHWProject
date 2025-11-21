package MMU 

import chisel3._
import chisel3.util._
import Common._

object MMU {
    // Address translation logic
  /*
  def isInScope(virtualAddr: UInt, bufferPos: UInt): Bool = {
    //val bufferEnd = (bufferPos + c.bufferSize.U) % (1.U << c.addrWidth)
    val bufferEnd = (bufferPos + c.bufferSize.U)
    Mux(bufferPos < bufferEnd, 
        virtualAddr >= bufferPos && virtualAddr < bufferEnd,
        virtualAddr >= bufferPos || virtualAddr < bufferEnd)
  }
  */
  
  def xor(a: Bool, b: Bool): Bool = {
    (a && !b) || (!a && b)
  }
  
  //def loRange(virtualAddr: UInt, framePointer: UInt, bufferSize: Int): Bool = {
  def loRange(virtualAddr: UInt, framePointer: UInt)(implicit config: Configuration): Bool = {
    val out = Wire(Bool())
    when((framePointer + config.bufferSize.U) < config.frameSize.U) {
      out := virtualAddr > framePointer
    } .otherwise {
      out := xor(virtualAddr > framePointer, virtualAddr < ((framePointer + config.bufferSize.U) - config.frameSize.U))
    }
    out
  }
  
  def isInScope(virtualAddr: UInt, writeSize: UInt, framePointer: UInt)(implicit config: Configuration): Bool = {
  
    //val lo = loRange(virtualAddr, framePointer, c.bufferSize) 
    val lo = loRange(virtualAddr, framePointer)(config) 
    val hi = (virtualAddr + writeSize) < (framePointer + config.bufferSize.U) // We ignore overflow here
  
    val inscope = lo && hi
  
    inscope
  }
  
  
  def translateAddress(virtualAddr: UInt, framePointer : UInt, bufferPointer : UInt)(implicit config: Configuration): UInt = {
    val diff = Mux((virtualAddr - framePointer).asSInt >= 0.S, virtualAddr - framePointer, ((virtualAddr + (config.frameSize.U - framePointer)))) 
    val addr = Mux(bufferPointer + diff > config.bufferSize.U, bufferPointer + diff - config.bufferSize.U, bufferPointer + diff)
    addr
  }
}
  

class MMU(implicit config: Configuration) extends Module{
  val io = IO(new Bundle{
    val tilelink_in = Flipped(new Tilelink()(config))
    val tilelink_out = new Tilelink()(config)
    val bufferPointer = Input(UInt(log2Ceil(config.bufferSize).W))
    val framePointer = Input(UInt(24.W))
  })

  // Direct connection of tilelink interfaces
  io.tilelink_out <> io.tilelink_in

  io.tilelink_out.a.valid := false.B

  //val inScope = isInScope(io.tilelink_in.a.bits.address, io.tilelink_in.a.bits.size, io.framePointer, bufferSize)
  val inScope = MMU.isInScope(io.tilelink_in.a.bits.address, io.tilelink_in.a.bits.size, io.framePointer)(config)

  io.tilelink_in.a.ready := io.tilelink_out.a.ready && inScope

  // Address override with higher priority (placed after the <> connection)
  when(io.tilelink_in.a.valid && io.tilelink_in.a.ready) {
    io.tilelink_out.a.valid := io.tilelink_in.a.valid

    io.tilelink_out.a.bits.address := MMU.translateAddress(io.tilelink_in.a.bits.address, io.framePointer, io.bufferPointer)(config)
  }
}

