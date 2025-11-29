package UserInput

import chisel3._
import chisel3.util._
import Common._

// Basic class for user input to output, for example the nexys a7 microphone
// and or buttons
class UserInput(val dataWidth: Int = 64) extends Bundle {
  val centerX = SInt(dataWidth.W)
  val centerY = SInt(dataWidth.W)
  val zoom = UInt(dataWidth.W)
}
