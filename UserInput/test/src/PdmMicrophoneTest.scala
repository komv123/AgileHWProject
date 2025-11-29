package UserInput

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers
import sound_input.PdmMicrophone

class PdmMicrophoneTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "PdmMicrophone"

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

    dut.pins.micLrSel.expect(false.B)

    while (captureCount < 2 && cycles < maxCycles) {
      val micClk = dut.pins.micClk.peek() // Updated IO path
      val risingEdge = !lastMicClk.litToBoolean && micClk.litToBoolean

      dut.pins.micData.poke(dataPattern(bitCount).B) // Updated IO path

      if (risingEdge) {
        bitCount += 1
      }

      if (dut.signal.valid.peek().litToBoolean) {
        dut.signal.waveform.expect(expectedWave.U) // Updated IO path
        dut.signal.amplitude.expect(expectedAmp.U) // Updated IO path
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
