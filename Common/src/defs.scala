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
