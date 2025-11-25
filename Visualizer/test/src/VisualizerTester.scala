package visualizer

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

import java.awt.image.BufferedImage
import java.awt.Color
import javax.imageio.ImageIO

class VisualizerTester extends AnyFlatSpec with Matchers with ChiselSim {
  "Visualizer" should "pass" in {
    val config = VisualizerConfig.default
    simulate(new Visualizer(config)) { dut =>
      val canvas = new BufferedImage(config.vga.horizontal.pixels, config.vga.vertical.pixels, BufferedImage.TYPE_INT_ARGB)

      def stepPixelClock(n: Int) = {
        dut.clock.step(n * (config.clockFrequency / config.vga.pixelFrequency))
      }

      def testHorizontalPeriod(line: Int) = {
        for (pixel <- 0 until config.vga.horizontal.pixels) {
          if (line < config.vga.vertical.pixels) {
            val red = (dut.io.colors.red.peek().litValue.toInt << (8 - config.vga.colorDepth)) | ((1 << (8 - config.vga.colorDepth)) - 1)
            val green = (dut.io.colors.green.peek().litValue.toInt << (8 - config.vga.colorDepth)) | ((1 << (8 - config.vga.colorDepth)) - 1)
            val blue = (dut.io.colors.blue.peek().litValue.toInt << (8 - config.vga.colorDepth)) | ((1 << (8 - config.vga.colorDepth)) - 1)
            canvas.setRGB(pixel, line, (0xFF << 24) + (red << 16) + (green << 8) + blue)
          }
          stepPixelClock(1)
        }
        for (i <- 0 until config.vga.horizontal.frontPorch + config.vga.horizontal.syncPulse + config.vga.horizontal.backPorch) {
          stepPixelClock(1)
        }
      }

      def testVerticalPeriod() = {
        for (line <- 0 until config.vga.vertical.pixels + config.vga.vertical.frontPorch + config.vga.vertical.syncPulse + config.vga.vertical.backPorch) {
          testHorizontalPeriod(line)
        }
      }

      testVerticalPeriod()
      javax.imageio.ImageIO.write(canvas, "png", new java.io.File("drawing.png"))
    }
  }
}
