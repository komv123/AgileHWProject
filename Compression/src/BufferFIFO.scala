package Compression 

import chisel3._
import chisel3.util._

class RegisterMem[T <: Data](val size: Int, val dataType: T) extends Module {

  var pointerwidth = log2Ceil(size - 1)

  val io = IO(new Bundle {
    val Write = Flipped(Valid(new Bundle{val addr = UInt(pointerwidth.W); val data = dataType.cloneType})) 
    val Read = Flipped(new Bundle{val addr = Output(UInt(pointerwidth.W)); val data = Input(dataType)})
  })

  val mem = Reg(Vec(size, dataType))

  val outReg = Reg(dataType)

  when(io.Write.valid){
    mem(io.Write.bits.addr) := io.Write.bits.data
  }

  outReg := mem(io.Read.addr)
  io.Read.data := outReg
}


//class BufferFIFO[T <: Data](val size: Int, val dataType: T, val regOnly: Option[Boolean]) extends Module {
class BufferFIFO[T <: Data](val size: Int, val dataType: T) extends Module {
  
  val pointerwidth = log2Ceil(size)
  
  val io = IO(new Bundle {
    val WriteData = Flipped(Decoupled(dataType))  // updated line
    val ReadData = Flipped(new Readport(dataType,0))  // updated line
  })

  val Head = RegInit(0.U(pointerwidth.W))
  val Tail = RegInit(0.U(pointerwidth.W))

  val HeadFlip = RegInit(0.U(1.W))
  val TailFlip = RegInit(0.U(1.W))

  val Full = Wire(Bool())
  Full := (Head === Tail) && !(HeadFlip === TailFlip)
  val empty = Wire(Bool())
  empty := (Head === Tail) && (HeadFlip === TailFlip)

  /*
  if(regOnly.isDefined && regOnly == true){
    val Mem = Module(new RegisterMem(size, dataType))
  } else {
    val Mem = Module(new DualPortRAM(size, dataType))
  }
  */

  val Mem = Module(new DualPortRAM(size, dataType))

  //val Mem = if(regOnly.isDefined && regOnly == true) Module(new RegisterMem(size, dataType)) else Module(new DualPortRAM(size, dataType))

  io.ReadData.response.bits.readData := Mem.io.Read.data 
  io.ReadData.response.valid := false.B

  Mem.io.Write.valid := false.B
  Mem.io.Write.bits := DontCare

  Mem.io.Read := DontCare

  when(io.WriteData.valid){
    Mem.io.Write.valid := true.B
    Mem.io.Write.bits.addr := Head
    Mem.io.Write.bits.data := io.WriteData.bits  // updated line
    
    Head := Head + 1.U

    when(Head === (size.U - 1.U)){
      Head := 0.U
      HeadFlip := ~HeadFlip
    }.otherwise{
      Head := Head + 1.U
    }
  }

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

  io.WriteData.ready := !Full

}

//TODO: change port names to camelcase
