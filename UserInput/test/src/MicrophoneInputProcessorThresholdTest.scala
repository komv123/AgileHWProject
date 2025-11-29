package UserInput

import chisel3._
import chisel3.util._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

class MockMicrophone extends Module with SoundInput {
  val signal = IO(new SoundInputSignalIO())
  val simAmplitude = IO(Input(UInt(8.W)))
  val simValid = IO(Input(Bool()))

  signal.amplitude := simAmplitude
  signal.valid := simValid
  signal.waveform := 0.U
}

class ThresholdTestWrapper extends Module {
  val mockMic = Module(new MockMicrophone())

  val amplitudeIn = IO(Input(UInt(8.W)))
  val validIn = IO(Input(Bool()))

  mockMic.simAmplitude := amplitudeIn
  mockMic.simValid := validIn

  val dut = Module(
    new AmplitudeInputMapper(
      threshold = 10.U,
      startZoom = 5000
    )
  )

  dut.io.micIO <> mockMic.signal

  val io = IO(new Bundle {
    val userInput = Valid(new UserInputPosition(32))
  })

  io.userInput <> dut.io.userInput
}

class MicrophoneInputProcessorThresholdTester
    extends AnyFlatSpec
    with Matchers
    with ChiselSim {
  behavior of "MicrophoneInputThreshold"

  it should "initialize with correct default values" in {
    simulate(new ThresholdTestWrapper) { dut =>
      dut.amplitudeIn.poke(0.U)
      dut.validIn.poke(false.B)
      dut.clock.step(1)
      dut.io.userInput.bits.zoom.expect(5000.U)
    }
  }

  it should "increase zoom when amplitude is above threshold" in {
    simulate(new ThresholdTestWrapper) { dut =>
      dut.amplitudeIn.poke(20.U) // Above 10
      dut.validIn.poke(true.B)
      dut.clock.step(1)
      // 5000 + (20 * 100) = 7000
      dut.io.userInput.bits.zoom.expect(7000.U)
    }
  }

  it should "decrease zoom when amplitude is below threshold" in {
    simulate(new ThresholdTestWrapper) { dut =>
      dut.amplitudeIn.poke(5.U) // Below 10
      dut.validIn.poke(true.B)
      dut.clock.step(1)
      // 5000 - 100 = 4900
      dut.io.userInput.bits.zoom.expect(4900.U)
    }
  }

  it should "clamp zoom decrease at 1000" in {
    simulate(new ThresholdTestWrapper) { dut =>
      dut.amplitudeIn.poke(0.U)
      dut.validIn.poke(true.B)
      // Step enough times to force it down (5000 -> 1000 takes 40 steps)
      dut.clock.step(50)
      dut.io.userInput.bits.zoom.expect(1000.U)
    }
  }

  it should "do nothing if mic signal is not valid" in {
    simulate(new ThresholdTestWrapper) { dut =>
      dut.amplitudeIn.poke(50.U)
      dut.validIn.poke(false.B) // Invalid!
      dut.clock.step(1)
      dut.io.userInput.bits.zoom.expect(5000.U)
    }
  }
}
