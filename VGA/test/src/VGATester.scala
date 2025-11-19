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
          dut.io.horizontalBlank.expect(blank.B)
          dut.io.horizontalSyncPulse.expect(syncPulse.B)
          dut.clock.step(clockFrequency / config.pixelFrequency)
        }
      }

      def testVerticalPeriod(lines: Int, blank: Boolean, syncPulse: Boolean) = {
        for (i <- 0 until lines) {
          dut.io.verticalBlank.expect(blank.B)
          dut.io.verticalSyncPulse.expect(syncPulse.B)
          testHorizontalPeriod(config.horizontalPixels, false, true)
          testHorizontalPeriod(config.horizontalFrontPorch, true, true)
          testHorizontalPeriod(config.horizontalSyncPulse, true, false)
          testHorizontalPeriod(config.horizontalBackPorch, true, true)
        }
      }

      testVerticalPeriod(config.verticalPixels, false, true)
      testVerticalPeriod(config.verticalFrontPorch, true, true)
      testVerticalPeriod(config.verticalSyncPulse, true, false)
      testVerticalPeriod(config.verticalBackPorch, true, true)
    }
    // create an image
    val canvas = new BufferedImage(config.horizontalPixels, config.verticalPixels, BufferedImage.TYPE_INT_ARGB)
    for (i <- 0 until canvas.getWidth()) {
      for (j <- 0 until canvas.getHeight()) {
        canvas.setRGB(i, j, 0xFF0000FF)
      }
    }
    javax.imageio.ImageIO.write(canvas, "png", new java.io.File("drawing.png"))
  }
}
