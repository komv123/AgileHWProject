package UserInput

import chisel3._
import chisel3.util._

class AmplitudeInputMapper(
    val threshold: UInt = 10.U,
    startCenterX: Int = 0,
    startCenterY: Int = 0,
    startZoom: Int = 21474836
) extends Module {
  val io = IO(new Bundle {
    val micIO = Flipped(new SoundInputSignalIO())

    val userInput = Valid(new UserInputPosition(32))
  })

  // Default state
  val centerXReg = RegInit(startCenterX.S(32.W))
  val centerYReg = RegInit(startCenterY.S(32.W))
  val zoomReg = RegInit(startZoom.S(32.W))

  when(io.micIO.valid) {
    when(io.micIO.amplitude > threshold) {
      zoomReg := zoomReg + (io.micIO.amplitude * 100.S)
    }.otherwise {
      when(zoomReg > 1000.S) {
        zoomReg := zoomReg - 100.S
      }
    }
  }

  io.userInput.valid := true.B
  io.userInput.bits.ymid := centerXReg
  io.userInput.bits.xmid := centerYReg
  io.userInput.bits.zoom := zoomReg
}
