package VideoBuffer 

import chisel3._
import chisel3.util._

import Common._


//class VideoBuffer(implicit c: Configuration) extends Module{
class VideoBuffer(config: Configuration) extends Module{
  implicit val c: Configuration = config

  val pointerwidth = log2Ceil(c.bufferSize)

  val io = IO(new Bundle{
    val ReadData = Flipped(new Readport(UInt(12.W), pointerwidth))
    val tilelink = Flipped(new Tilelink()(c))
    val bufferPointer = Output(UInt(log2Ceil(c.bufferSize).W))
  })

  val Tail = RegInit(0.U(log2Ceil(c.bufferSize).W))
  val TailFlip = RegInit(0.U(1.W))
  val Mem = Module(new DualPortRAM(c.bufferSize, UInt(12.W)))
  
  val empty = Wire(Bool())
  empty := false.B  // For now, simplified - VideoBuffer doesn't track empty state like FIFO
  val size = c.bufferSize

  val stateReg = RegInit(0.U(4.W))
  val burstCounter = RegInit(0.U(24.W)) // Counts to a.size
  val sourceReg = RegInit(0.U(c.sourceWidth.W))

  io.bufferPointer := Tail

  //io.tilelink.a.ready := true.B 
  io.tilelink.a.ready := false.B 
  io.tilelink.d.valid := false.B

  io.tilelink.d.bits := DontCare

  Mem.io.Read.addr := Tail 

  Mem.io.Write.valid := false.B
  Mem.io.Write.bits.addr := 0.U 
  Mem.io.Write.bits.data := 0.U 


  io.ReadData.response.bits.readData := Mem.io.Read.data 
  io.ReadData.response.valid := false.B

  io.ReadData.request.ready := !empty

  Mem.io.Read.addr := Tail
  
  when(io.ReadData.request.valid){

    when(Tail === (size.U - 1.U)){
      Tail := 0.U
      Mem.io.Read.addr := 0.U
      TailFlip := ~TailFlip
    }.otherwise{
      Tail := Tail + 1.U
      Mem.io.Read.addr := Tail + 1.U // FIXME: Might be a little dangerous in terms of combinational delays 
    }

    io.ReadData.response.valid := true.B
  }

  switch(stateReg){ // Start write transaction  
    is(0.U){
      io.tilelink.a.ready := true.B 

      when(io.tilelink.a.valid && io.tilelink.a.bits.opcode === 0.U){ // Write

        sourceReg := io.tilelink.a.bits.source

        Mem.io.Write.valid := true.B
        Mem.io.Write.bits.addr := io.tilelink.a.bits.address
        Mem.io.Write.bits.data := io.tilelink.a.bits.data

        when(io.tilelink.a.bits.size =/= 0.U){
          stateReg := 1.U 
          burstCounter := 1.U
        } .otherwise {
          stateReg := 2.U 
        }
      }
    }
    is(1.U){ // Continue burst
      io.tilelink.a.ready := true.B 

      when(io.tilelink.a.valid){ // Write
        Mem.io.Write.valid := true.B
        Mem.io.Write.bits.addr := io.tilelink.a.bits.address + burstCounter
        Mem.io.Write.bits.data := io.tilelink.a.bits.data

        when(burstCounter < io.tilelink.a.bits.size){
          burstCounter := burstCounter + 1.U
          stateReg := 1.U
        } .otherwise {
          stateReg := 2.U // Return ack
        }
      }
    }
    is(2.U){ // Send ack
      io.tilelink.d.valid := true.B 


      io.tilelink.d.bits.opcode := 0.U //AccessAck
      io.tilelink.d.bits.size := 0.U // Max burst = 2 ^ 24 words = 16777216
      io.tilelink.d.bits.source := sourceReg
        
      when(io.tilelink.d.ready){ // Send AccessAck
        stateReg := 0.U
      }
    }
  }
}
