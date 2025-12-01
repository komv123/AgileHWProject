import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._

import ComputeModule._

class CMColorSpec extends AnyFlatSpec with ChiselSim {
    val n = 2

    val width = 128
    val height = 128
    val frame_height = height / n
    val start_address = 0
    val fills = (width * frame_height) / 1024

    val computeConfig = ComputeConfig(
        width = width,
        height = frame_height,
        maxiter = 1000
    )
    
    "CMTest" should s"render $width x $height" in {
        
        simulate(new CompColorWrapper(computeConfig, n, start_address)) { dut =>
            println("Generating output.ppm")
            val writer = new PrintWriter("outputFull1.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"$width $frame_height")
            writer.println("15")

            println("Start partial frame test")

            dut.io.xmid.poke(-48729.S)  // -3193384776 >> 16
            dut.io.ymid.poke(8329.S)    // 545867056 >> 16
            dut.io.zoom.poke(328.S)     // 21474836 >> 16
            dut.io.id.poke(1.U)
            
            for (i <- 0 until fills){
                dut.clock.step(1000000)

                dut.io.tilelink_out.a.ready.poke(true.B)

                for (i <- 0 until 1024){    
                    val rgb = dut.io.tilelink_out.a.bits.data.peek().litValue
                    //println(f"RGB: ${rgb}%03X")
                    val r = (rgb >> 8) & 0xF
                    val g = (rgb >> 4) & 0xF
                    val b = rgb & 0xF

                    writer.println(s"$r $g $b")
                    dut.clock.step(1)
                }

                dut.io.tilelink_out.a.ready.poke(false.B)
                dut.io.tilelink_out.d.valid.poke(true.B)
                dut.io.tilelink_out.d.ready.expect(true.B)
                dut.clock.step(1)
                dut.io.tilelink_out.d.valid.poke(false.B)
            }

            writer.close()
            println("PPM image written to outputFull1.ppm")
        }
    }
}