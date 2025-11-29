package UserInput

import chisel3._
import chisel3.util._

class PdmMicrophone(
    val clockFreq: Int = 100000000,
    val micClockFreq: Int = 2500000
) extends Module {
  val io = IO(new Bundle {
    val micData = Input(Bool())
    val micClk = Output(Bool())
    val micLrSel = Output(Bool())

    val amplitude = Output(UInt(8.W))
    val waveform = Output(UInt(8.W))
    val valid = Output(Bool())
  })

  val toggleCount = clockFreq / (2 * micClockFreq)
  val (clkCount, clkWrap) = Counter(true.B, toggleCount)

  val micClkReg = RegInit(false.B)
  val risingEdge = Wire(Bool())

  when(clkWrap) {
    micClkReg := ~micClkReg
  }

  risingEdge := clkWrap && !micClkReg

  io.micLrSel := false.B
  io.micClk := micClkReg

  val (bitCount, bitWrap) = Counter(risingEdge, 128)

  val onesCounter = RegInit(0.U(8.W))

  val amplitudeReg = RegInit(0.U(8.W))
  val waveformReg = RegInit(64.U(8.W))
  val validReg = RegInit(false.B)

  io.amplitude := amplitudeReg
  io.waveform := waveformReg
  io.valid := validReg

  validReg := false.B

  when(risingEdge) {
    when(bitWrap) {
      val totalSum = onesCounter + io.micData.asUInt
      val centered = totalSum.zext - 64.S

      amplitudeReg := centered.abs.asUInt
      waveformReg := totalSum
      validReg := true.B

      onesCounter := 0.U
    }.otherwise {
      onesCounter := onesCounter + io.micData.asUInt
    }
  }
}
