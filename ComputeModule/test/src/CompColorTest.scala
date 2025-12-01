import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._

class CMColorSpec extends AnyFlatSpec with ChiselSim {
    "FullTest" should "pass" in {
        val n = 1

        val width = 64
        val height = 64
        val frame_height = height / n
        
        simulate(new CompColorWrapper(width, height, n)) { dut =>
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
            
            for (i <- 0 until 4){
                dut.clock.step(1100000)

                dut.io.tilelink_out.a.ready.poke(true.B)
                



            }

            breakable 
            {for (i <- 0 until 1000000) {
                val valid = dut.io.valid_out.peek().litToBoolean
                val yrow = dut.io.j_out.peek().litValue.toInt
                if (y_prev > yrow) {break()}
                if (!valid_prev && valid) {
                    val k_out = dut.io.k_out.peek().litValue.toInt
                    val rgb = dut.io.rgb_out.peek().litValue
                    println(f"${yrow} k: ${k_out}, RGB: ${rgb}%03X")

                    val r = (rgb >> 8) & 0xF
                    val g = (rgb >> 4) & 0xF
                    val b = rgb & 0xF
                    
                    writer.println(s"$r $g $b")
                }
                y_prev = dut.io.j_out.peek().litValue.toInt
                valid_prev = dut.io.valid_out.peek().litToBoolean
                dut.clock.step(1)
            }}
            writer.close()
            println("PPM image written to outputFull1.ppm")
        }
    }
}