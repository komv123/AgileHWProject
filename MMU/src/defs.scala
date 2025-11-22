package MMU 

import chisel3._
import chisel3.util._


class MemoryLookup() extends Bundle {
  val currentAddress = Valid(UInt(20.W)) 
}
