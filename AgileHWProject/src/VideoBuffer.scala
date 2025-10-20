package SYS

import chisel3._
import chisel3.util._

//class VideoBuffer(implicit c: Configuration) extends Module{
class VideoBuffer(config: Configuration) extends Module{
  implicit val c = config

  val io = IO(new Bundle{
    val VGA = new interfaceVGA
    val request = Input(Bool())
    val tilelink = Flipped(new Tilelink)
  })

  val pointerwidth = log2Ceil(c.bufferSize)

  val Tail = RegInit(0.U(pointerwidth.W))
  val Mem = Module(new DualPortRAM(c.bufferSize, UInt(12.W)))  // updated line


  val stateReg = RegInit(0.U(4.W))
  val burstCounter = RegInit(0.U(24.W)) // Counts to a.size
  val sourceReg = RegInit(0.U(log2Ceil(c.sourceCount).W))


  io.tilelink.a.ready := true.B 
  io.tilelink.d.valid := false.B

  io.tilelink.d.bits := DontCare

  Mem.io.Read.addr := Tail
  io.VGA.RGB := Mem.io.Read.data 

  Mem.io.Write.valid := false.B
  Mem.io.Write.bits.addr := 0.U 
  Mem.io.Write.bits.data := 0.U 


  when(io.request){
    when(Tail === (c.bufferSize.U - 1.U)){
      Tail := 0.U
      Mem.io.Read.addr := 0.U
      //TailFlip := ~TailFlip
    }.otherwise{
      Tail := Tail + 1.U
      Mem.io.Read.addr := Tail + 1.U // FIXME: Might be a little dangerous in terms of combinational delays 
    }
  }

  switch(stateReg){ // Start write transaction  
    is(0.U){

      when(io.tilelink.a.valid && io.tilelink.a.bits.opcode === 0.U){ // Write

        sourceReg := io.tilelink.a.bits.source

        Mem.io.Write.valid := true.B
        Mem.io.Write.bits.addr := io.tilelink.a.bits.address
        Mem.io.Write.bits.data := io.tilelink.a.bits.data

        when(io.tilelink.a.bits.size =/= 0.U){
          stateReg := 1.U 
          burstCounter := 1.U
        } .otherwise {
          stateReg := 0.U 
        }
      }
    }
    is(1.U){ // Continue burst

      Mem.io.Write.valid := true.B
      Mem.io.Write.bits.addr := io.tilelink.a.bits.address + burstCounter
      Mem.io.Write.bits.data := io.tilelink.a.bits.data

      when(burstCounter < io.tilelink.a.bits.address){
        burstCounter := burstCounter + 1.U
      } .otherwise {
        stateReg := 2.U // Return ack
      }
    }
    is(2.U){ // Send ack

      io.tilelink.a.ready := 0.U
      io.tilelink.d.valid := 1.U

      when(io.tilelink.d.ready){ // Send AccessAck
        io.tilelink.d.bits.opcode := 0.U //AccessAck
        //io.tilelink.d.bits.param := Dontcare 
        io.tilelink.d.bits.size := 0.U // Max burst = 2 ^ 24 words = 16777216
        io.tilelink.d.bits.source := sourceReg
        //io.tilelink.d.bits.sink := UInt(log2ceil(c.sourceCount).W)
        //io.tilelink.d.bits.denied := UInt(1.W)
        //io.tilelink.d.bits.data := UInt(c.busWidth.W)
        //io.tilelink.d.bits.corrupt := UInt(1.W)
      }
    }
  }
}

object VideoMain extends App {
  emitVerilog(new VideoBuffer(Configuration.default()))
}
