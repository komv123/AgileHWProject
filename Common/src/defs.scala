package Common 

import chisel3._
import chisel3.util._

class Readport[T <: Data](private val dataType: T, val addrWidth: Int) extends Bundle {
  val request = Decoupled(new Bundle {
    val addr = UInt(addrWidth.W)
  })
  val response = Flipped(Valid(new Bundle {
    val readData = dataType.cloneType
  }))
}

class interfaceVGA(implicit c: Configuration) extends Bundle {
  //val Rin, Gin, Bin = UInt(4.W)
  val RGB = UInt(12.W)
  val hSync, vSync = Flipped(Bool())
  val R, G, B = Flipped(UInt(4.W))
  //val RGB = Flipped(UInt(12.W))
  val horCntr, verCntr = Flipped(UInt(10.W))
}

