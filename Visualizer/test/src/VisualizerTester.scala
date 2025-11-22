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
  "Visulizer" should "pass" in {
    val config = VisualizerConfig.default
    simulate(new Visualizer(config)) { dut =>
      val canvas = new BufferedImage(config.vga.horizontal.pixels, config.vga.vertical.pixels, BufferedImage.TYPE_INT_ARGB)
      for (i <- 0 until canvas.getWidth()) {
        for (j <- 0 until canvas.getHeight()) {
          canvas.setRGB(i, j, 0xFF0000FF)
        }
      }
      javax.imageio.ImageIO.write(canvas, "png", new java.io.File("drawing.png"))
    }
  }
}
