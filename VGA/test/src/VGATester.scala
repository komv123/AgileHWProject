package vga

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

class VGATester extends AnyFlatSpec with Matchers with ChiselSim {
  "VGA" should "pass" in {
    val clockFrequency = 50000000
    val config = VGAConfig.vga640x480at60Hz
    simulate(new VGAController(config, clockFrequency)) { dut =>

      // Set color signals to something else than 0
      dut.io.colors.input.red.poke(1.U)
      dut.io.colors.input.green.poke(1.U)
      dut.io.colors.input.blue.poke(1.U)

      def testHorizontalPeriod(pixels: Int, blank: Boolean, syncPulse: Boolean) = {
        for (i <- 0 until pixels) {
          dut.io.horizontal.blank.expect(blank.B)
          dut.io.horizontal.syncPulse.expect(syncPulse.B)
          if (blank) {
            dut.io.colors.output.red.expect(0.U)
            dut.io.colors.output.green.expect(0.U)
            dut.io.colors.output.blue.expect(0.U)
          }

          dut.clock.step(clockFrequency / config.pixelFrequency)
        }
      }

      def testVerticalPeriod(lines: Int, blank: Boolean, syncPulse: Boolean) = {
        for (i <- 0 until lines) {
          dut.io.vertical.blank.expect(blank.B)
          dut.io.vertical.syncPulse.expect(syncPulse.B)
          if (blank) {
            dut.io.colors.output.red.expect(0.U)
            dut.io.colors.output.green.expect(0.U)
            dut.io.colors.output.blue.expect(0.U)
          }

          testHorizontalPeriod(config.horizontal.pixels, false, true)
          testHorizontalPeriod(config.horizontal.frontPorch, true, true)
          testHorizontalPeriod(config.horizontal.syncPulse, true, false)
          testHorizontalPeriod(config.horizontal.backPorch, true, true)
        }
      }

      testVerticalPeriod(config.vertical.pixels, false, true)
      testVerticalPeriod(config.vertical.frontPorch, true, true)
      testVerticalPeriod(config.vertical.syncPulse, true, false)
      testVerticalPeriod(config.vertical.backPorch, true, true)
    }
  }
}
