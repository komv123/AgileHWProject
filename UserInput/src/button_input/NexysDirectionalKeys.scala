package UserInput

import chisel3._
import chisel3.util._

class NexysDirectionalKeys(
    startCenterX: Int = 0,
    startCenterY: Int = 0,
    startZoom: Int = 21474836,
    moveMultiplier: Int = 10,
    zoomMultiplier: Int = 1000,
    val tickDelay: Int = 1600000
) extends Module {
  val io = IO(new Bundle {
    val upButton = Input(Bool())
    val downButton = Input(Bool())
    val rightButton = Input(Bool())
    val leftButton = Input(Bool())
    val midButton = Input(Bool())
    val userInput = Valid(new UserInputPosition(32))
  })

  val (tickValue, tickWrap) = Counter(true.B, tickDelay)
  val centerXReg = RegInit(startCenterX.S(32.W))
  val centerYReg = RegInit(startCenterY.S(32.W))
  val zoomReg = RegInit(startZoom.S(32.W))

  when(tickWrap) {
    when(io.midButton) {
      // Zoom mode
      when(io.upButton) {
        zoomReg := zoomReg - zoomMultiplier.S
      }.elsewhen(io.downButton) {
        zoomReg := zoomReg + zoomMultiplier.S
      }

      when(io.leftButton) {
        zoomReg := zoomReg - (zoomMultiplier * 10).S
      }.elsewhen(io.rightButton) {
        zoomReg := zoomReg + (zoomMultiplier * 10).S
      }
    }.otherwise {
      // Move mode
      when(io.upButton) {
        centerYReg := centerYReg - moveMultiplier.S
      }.elsewhen(io.downButton) {
        centerYReg := centerYReg + moveMultiplier.S
      }

      when(io.leftButton) {
        centerXReg := centerXReg - moveMultiplier.S
      }.elsewhen(io.rightButton) {
        centerXReg := centerXReg + moveMultiplier.S
      }
    }
  }

  io.userInput.valid := true.B // Always output valid data
  io.userInput.bits.xmid := centerXReg
  io.userInput.bits.ymid := centerYReg
  io.userInput.bits.zoom := zoomReg
}
