package UserInput

import chisel3._
import chisel3.util._

class AmplitudeInputMapper(
    val threshold: UInt = 10.U,
    startCenterX: Int = -49152,
    startCenterY: Int = 0,
    startZoom: Int = 196608,
    val tickDelay: Int = 20000000
) extends Module {
  val io = IO(new Bundle {
    val micIO = Flipped(new SoundInputSignalIO())

    val userInput = Valid(new UserInputPosition(32))
  })

  // Default state
  val centerXReg = RegInit(startCenterX.S(32.W))
  val centerYReg = RegInit(startCenterY.S(32.W))
  val zoomReg = RegInit(startZoom.S(32.W))

  val (tickValue, tickWrap) = Counter(true.B, tickDelay)

  when(tickWrap) {
    when(io.micIO.amplitude > threshold) {
      zoomReg := zoomReg + (io.micIO.amplitude * 100.S)
    }.otherwise {
      val nextZoom = zoomReg - 100.S
      when(zoomReg > 640.S) {
        zoomReg := Mux(nextZoom < 640.S, 640.S, nextZoom)
      }
    }
  }

  io.userInput.valid := true.B
  io.userInput.bits.ymid := centerXReg
  io.userInput.bits.xmid := centerYReg
  io.userInput.bits.zoom := zoomReg
}
