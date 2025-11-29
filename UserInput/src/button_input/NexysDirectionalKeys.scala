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
  val zoomReg = RegInit(startZoom.U(32.W))

  when(tickWrap) {
    when(io.midButton) {
      // Zoom mode
      when(io.upButton) {
        zoomReg := zoomReg - zoomMultiplier.U
      }.elsewhen(io.downButton) {
        zoomReg := zoomReg + zoomMultiplier.U
      }

      when(io.leftButton) {
        zoomReg := zoomReg - (zoomMultiplier * 10).U
      }.elsewhen(io.rightButton) {
        zoomReg := zoomReg + (zoomMultiplier * 10).U
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
