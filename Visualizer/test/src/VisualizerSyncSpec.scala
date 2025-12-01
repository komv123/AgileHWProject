package visualizer

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

class VisualizerSyncSpec extends AnyFlatSpec with Matchers with ChiselSim {
  "Visualizer" should "gate color output during blanking and drive horizontal sync pulses" in {
    val config = VisualizerConfig.default
    val cyclesPerPixel = config.clockFrequency / config.vga.pixelFrequency

    simulate(new Visualizer(config)) { dut =>
      def stepPixels(n: Int): Unit = dut.clock.step(n * cyclesPerPixel)

      // At reset both sync pulses are asserted
      dut.io.horizontalSyncPulse.peek().litToBoolean mustBe true
      dut.io.verticalSyncPulse.peek().litToBoolean mustBe true

      // After the active display region, color outputs should be blanked
      stepPixels(config.vga.horizontal.pixels)
      dut.io.horizontalSyncPulse.peek().litToBoolean mustBe true
      dut.io.verticalSyncPulse.peek().litToBoolean mustBe true
      dut.io.colors.red.peek().litValue mustBe 0
      dut.io.colors.green.peek().litValue mustBe 0
      dut.io.colors.blue.peek().litValue mustBe 0

      // Advance through the front porch to the start of the sync pulse
      stepPixels(config.vga.horizontal.frontPorch)
      dut.io.horizontalSyncPulse.peek().litToBoolean mustBe false

      // Horizontal sync pulse stays low for the expected duration
      for (_ <- 0 until config.vga.horizontal.syncPulse) {
        dut.io.horizontalSyncPulse.peek().litToBoolean mustBe false
        stepPixels(1)
      }

      // After the pulse the line is in the back porch with sync deasserted
      dut.io.horizontalSyncPulse.peek().litToBoolean mustBe true
    }
  }
}