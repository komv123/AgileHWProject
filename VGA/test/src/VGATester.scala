package vga

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

import java.awt.image.BufferedImage
import java.awt.Color
import javax.imageio.ImageIO

class VGATester extends AnyFlatSpec with Matchers with ChiselSim {
  "VGA" should "pass" in {
    val clockFrequency = 50000000
    val config = VGAConfig.vga640x480at60Hz
    simulate(new VGAController(config, clockFrequency)) { dut =>

      def testHorizontalPeriod(pixels: Int, blank: Boolean, syncPulse: Boolean) = {
        for (i <- 0 until pixels) {
          dut.io.horizontal.blank.expect(blank.B)
          dut.io.horizontal.syncPulse.expect(syncPulse.B)
          dut.clock.step(clockFrequency / config.pixelFrequency)
        }
      }

      def testVerticalPeriod(lines: Int, blank: Boolean, syncPulse: Boolean) = {
        for (i <- 0 until lines) {
          dut.io.vertical.blank.expect(blank.B)
          dut.io.vertical.syncPulse.expect(syncPulse.B)
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
    // create an image
    val canvas = new BufferedImage(config.horizontal.pixels, config.vertical.pixels, BufferedImage.TYPE_INT_ARGB)
    for (i <- 0 until canvas.getWidth()) {
      for (j <- 0 until canvas.getHeight()) {
        canvas.setRGB(i, j, 0xFF0000FF)
      }
    }
    javax.imageio.ImageIO.write(canvas, "png", new java.io.File("drawing.png"))
  }
}
