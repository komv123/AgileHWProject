package UserInput

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

class PdmMicrophoneTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "PdmMicrophone"

  // Helper function for some of the stuff repeated
  def runTest(
      dut: PdmMicrophone,
      dataPattern: Int => Boolean,
      expectedWave: Int,
      expectedAmp: Int
  ): Unit = {
    var bitCount = 0
    var lastMicClk = false.B
    var captureCount = 0

    val maxCycles = 20000
    var cycles = 0

    dut.io.micLrSel.expect(false.B) // Should always be Left (Low)

    while (captureCount < 2 && cycles < maxCycles) {
      val micClk = dut.io.micClk.peek()
      val risingEdge = !lastMicClk.litToBoolean && micClk.litToBoolean
      dut.io.micData.poke(dataPattern(bitCount).B)

      if (risingEdge) {
        bitCount += 1
      }

      if (dut.io.valid.peek().litToBoolean) {
        // Check outputs when valid is high
        dut.io.waveform.expect(expectedWave.U)
        // Amplitude is the absolute value of (waveform - 64)
        dut.io.amplitude.expect(expectedAmp.U)
        captureCount += 1
      }

      lastMicClk = micClk
      dut.clock.step(1)
      cycles += 1
    }

    assert(
      captureCount >= 1,
      "Did not receive a valid output signal within timeout"
    )
  }

  it should "detect Silence (Alternating 1/0)" in {
    simulate(new PdmMicrophone()) { dut =>
      runTest(dut, i => i % 2 == 0, expectedWave = 64, expectedAmp = 0)
    }
  }

  it should "detect Max Positive Volume (All 1s)" in {
    simulate(new PdmMicrophone()) { dut =>
      runTest(dut, _ => true, expectedWave = 128, expectedAmp = 64)
    }
  }

  it should "detect Max Negative Volume (All 0s)" in {
    simulate(new PdmMicrophone()) { dut =>
      runTest(dut, _ => false, expectedWave = 0, expectedAmp = 64)
    }
  }
}
