package UserInput

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

class NexysDirectionalKeysTester
    extends AnyFlatSpec
    with Matchers
    with ChiselSim {
  behavior of "NexysDirectionalKeys"

  it should "initialize to start values" in {
    simulate(
      new NexysDirectionalKeys(
        startCenterX = 100,
        startCenterY = 100,
        startZoom = 5000,
        tickDelay = 1
      )
    ) { dut =>
      dut.io.userInput.bits.xmid.expect(100.S)
      dut.io.userInput.bits.ymid.expect(100.S)
      dut.io.userInput.bits.zoom.expect(5000.S)
    }
  }

  it should "move X and Y correctly in Move Mode (dependent on Zoom)" in {
    simulate(
      new NexysDirectionalKeys(
        startCenterX = 0,
        startCenterY = 0,
        startZoom = 3200, // Zoom >> 5 = 100 step size
        tickDelay = 1
      )
    ) { dut =>
      // test right
      dut.io.midButton.poke(false.B)
      dut.io.rightButton.poke(true.B)
      dut.clock.step(1) // Instant update because tickDelay = 1
      // Step size is calculated as zoomReg >> 5
      // 3200 >> 5 = 100
      dut.io.userInput.bits.xmid.expect(100.S)

      // test down
      dut.io.rightButton.poke(false.B)
      dut.io.downButton.poke(true.B)
      dut.clock.step(1)
      dut.io.userInput.bits.ymid.expect(100.S)
    }
  }

  it should "change Zoom correctly in Zoom Mode" in {
    simulate(new NexysDirectionalKeys(startZoom = 20000, tickDelay = 1)) {
      dut =>
        dut.io.midButton.poke(true.B)
        dut.io.downButton.poke(true.B)
        dut.clock.step(1)
        dut.io.userInput.bits.zoom.expect(21000.S)
    }
  }

  it should "clamp Zoom at 640 (Zoom In Limit)" in {
    // Start at 1000. Zooming in (Up button) subtracts 1000.
    // Result 0 should be clamped to 640.
    simulate(new NexysDirectionalKeys(startZoom = 1000, tickDelay = 1)) {
      dut =>
        dut.io.midButton.poke(true.B)
        dut.io.upButton.poke(true.B)
        dut.clock.step(1)
        dut.io.userInput.bits.zoom.expect(640.S)
    }
  }

  it should "prioritize Up over Down" in {
    simulate(new NexysDirectionalKeys(startCenterY = 100, startZoom = 3200, tickDelay = 1)) {
      dut =>
        dut.io.upButton.poke(true.B)
        dut.io.downButton.poke(true.B)
        dut.clock.step(1)
        // Step size = 3200 >> 5 = 100
        // Up is subtract: 100 - 100 = 0
        dut.io.userInput.bits.ymid.expect(0.S) 
    }
  }
}
