package UserInput

import chisel3._
import chisel3.util._
import Common._

// Basic class for user input to output, for example the nexys a7 microphone
// and or buttons
class UserInputPosition(val dataWidth: Int = 64) extends Bundle {
  val ymid = SInt(dataWidth.W)
  val xmid = SInt(dataWidth.W)
  val zoom = UInt(dataWidth.W)
}
