package SYS 

import chisel3._
import chisel3.util._

class Tilelink_A(implicit c: Configuration) extends Bundle {
  val opcode = UInt(3.W)
  val param = UInt(3.W)
  val size = UInt(24.W) // Max burst = 2 ^ 24 words = 16777216
  val source = UInt(log2Ceil(c.sourceCount).W)
  val address = UInt(c.addrWidth.W)
  val mask = UInt(c.maskWidth.W)
  val data = UInt(c.busWidth.W)
  val corrupt = UInt(1.W)
}

class Tilelink_D(implicit c: Configuration) extends Bundle {
  val opcode = UInt(3.W)
  val param = UInt(2.W)
  val size = UInt(24.W) // Max burst = 2 ^ 24 words = 16777216
  val source = UInt(log2Ceil(c.sourceCount).W)
  val sink = UInt(log2Ceil(c.sourceCount).W)
  val denied = UInt(1.W)
  val data = UInt(c.busWidth.W)
  val corrupt = UInt(1.W)
}

class Tilelink(implicit c: Configuration) extends Bundle {
  val a = Decoupled(new Tilelink_A)
  val d = Flipped(Decoupled(new Tilelink_D))
}

