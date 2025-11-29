package UserInput

import chisel3._
import chisel3.util._

class PdmMicrophone(
    val clockFreq: Int = 100000000,
    val micClockFreq: Int = 2500000
) extends Module
    with SoundInput {

  // Hardware specific pins
  val pins = IO(new Bundle {
    val micData = Input(Bool())
    val micClk = Output(Bool())
    val micLrSel = Output(Bool())
  })

  // Output used for microphone wrapper
  val signal = IO(new SoundInputSignalIO())

  val toggleCount = clockFreq / (2 * micClockFreq)
  val (clkCount, clkWrap) = Counter(true.B, toggleCount)

  val micClkReg = RegInit(false.B)
  val risingEdge = Wire(Bool())

  when(clkWrap) {
    micClkReg := ~micClkReg
  }

  risingEdge := clkWrap && !micClkReg

  pins.micLrSel := false.B
  pins.micClk := micClkReg

  val (bitCount, bitWrap) = Counter(risingEdge, 128)

  val onesCounter = RegInit(0.U(8.W))

  val amplitudeReg = RegInit(0.U(8.W))
  val waveformReg = RegInit(64.U(8.W))
  val validReg = RegInit(false.B)

  // Drive the common interface
  signal.amplitude := amplitudeReg
  signal.waveform := waveformReg
  signal.valid := validReg

  validReg := false.B

  when(risingEdge) {
    when(bitWrap) {
      val totalSum = onesCounter + pins.micData.asUInt
      val centered = totalSum.zext - 64.S

      amplitudeReg := centered.abs.asUInt
      waveformReg := totalSum
      validReg := true.B

      onesCounter := 0.U
    }.otherwise {
      onesCounter := onesCounter + pins.micData.asUInt
    }
  }
}
