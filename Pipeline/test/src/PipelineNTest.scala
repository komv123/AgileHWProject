import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._
import chisel3.util.experimental.BoringUtils

import Pipeline._

class PipelineTest extends AnyFlatSpec with ChiselSim {
    "Pipeline" should "render 64 x 64 " in {
        simulate(new Pipeline(64, 64, 2)) { dut =>

            val writer = new PrintWriter("output64_64.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"64 64")
            writer.println("15")

            // Create PPM writers for each compute module

            dut.io.userInput.valid.poke(true.B)
            dut.io.userInput.bits.ymid.poke(0.S)
            dut.io.userInput.bits.xmid.poke(-179851264.S)
            dut.io.userInput.bits.zoom.poke(268435456.S)

            var framePointer = 0 

            for(i <- 0 until 4){ 
              dut.io.framePointer.poke(framePointer.U)

              dut.clock.step(2000000)

              for (i <- 0 until 1024){
                  dut.io.ReadData.request.valid.poke(true.B)

                  val rgb = dut.io.ReadData.response.bits.readData.peek().litValue
                  //println(f"RGB: ${rgb}%03X")
                  val r = (rgb >> 8) & 0xF
                  val g = (rgb >> 4) & 0xF
                  val b = rgb & 0xF

                  writer.println(s"$r $g $b")
                  dut.clock.step(1)
              }

              dut.io.ReadData.request.valid.poke(false.B)

              framePointer += 1024
            }

            writer.close()
        }
    }
}
