import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._

import Pipeline._

class PipelineTest extends AnyFlatSpec with ChiselSim {
    "Pipeline" should "render 32 x 32 " in {
        simulate(new Pipeline(32, 32)) { dut =>
            val writer = new PrintWriter("output32_32.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"32 32")
            writer.println("15")

            dut.io.xmid.poke(-5755256176L.S)
            dut.io.ymid.poke(0L.S)
            dut.io.zoom.poke(8589934592L.S)
            dut.io.maxiter.poke(1000.U)

            dut.io.framePointer.poke(0.U)
            //dut.io.bufferPointer.poke(0.U)

            dut.io.new_params.poke(1.B)

            dut.clock.step(5)
            dut.io.new_params.poke(0.B)
            breakable{for (i <- 0 until 1000000) {
                dut.clock.step(1)
            }}

            dut.io.ReadData.request.valid.poke(true.B)

            dut.clock.step(1)

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

            writer.close()
        }
    }
    "Pipeline" should "render 64 x 64 " in {
        simulate(new Pipeline(64, 64)) { dut =>
            val writer = new PrintWriter("output64_64.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"64 64")
            writer.println("15")

            dut.io.xmid.poke(-5755256176L.S)
            dut.io.ymid.poke(0L.S)
            dut.io.zoom.poke(8589934592L.S)
            dut.io.maxiter.poke(1000.U)

            var framePointer = 0 

            dut.io.new_params.poke(1.B)

            dut.clock.step(5)
            dut.io.new_params.poke(0.B)

            for(i <- 0 until 4){ 
              dut.io.framePointer.poke(framePointer.U)
              //dut.io.bufferPointer.poke(bufferPointer.U)

              breakable{for (i <- 0 until 1000000) {
                  dut.clock.step(1)
              }}

              //if(i == 0){
              //  dut.io.ReadData.request.valid.poke(true.B)
              //  dut.clock.step(1)
              //}

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
    "Pipeline" should "render 128 x 128 " in {
        simulate(new Pipeline(128, 128)) { dut =>
            val writer = new PrintWriter("output128_128.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"128 128")
            writer.println("15")

            dut.io.xmid.poke(-5755256176L.S)
            dut.io.ymid.poke(0L.S)
            dut.io.zoom.poke(8589934592L.S)
            dut.io.maxiter.poke(1000.U)

            var framePointer = 0 

            dut.io.new_params.poke(1.B)

            dut.clock.step(5)
            dut.io.new_params.poke(0.B)

            for(i <- 0 until 16){ 
              dut.io.framePointer.poke(framePointer.U)
              //dut.io.bufferPointer.poke(bufferPointer.U)

              breakable{for (i <- 0 until 1000000) {
                  dut.clock.step(1)
              }}

              //if(i == 0){
              //  dut.io.ReadData.request.valid.poke(true.B)
              //  dut.clock.step(1)
              //}

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
