import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter

class CMColorSpec extends AnyFlatSpec with ChiselSim {
    "FullTest" should "pass" in {
        simulate(new CompColorWrapper()) { dut =>
            println("Generating output.ppm")
            val width = 320
            val height = 240
            val writer = new PrintWriter("outputFull1.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"$width $height")
            writer.println("15")

            println("Start full test")

            dut.io.xmid.poke(-3193384776L.S)
            dut.io.ymid.poke(545867056L.S)
            dut.io.zoom.poke(21474836L.S)
            dut.io.maxiter.poke(1000.U)
            dut.io.new_params.poke(1.B)
            dut.clock.step(5)
            dut.io.new_params.poke(0.B)
            var valid_prev = false
            for (i <- 0 until 20000000) {
                val valid = dut.io.valid_out.peek().litToBoolean
                if (!valid_prev && valid) {
                    val k_out = dut.io.k_out.peek().litValue.toInt
                    val yrow = dut.io.j_out.peek().litValue.toInt
                    val rgb = dut.io.rgb_out.peek().litValue
                    println(f"${yrow} k: ${k_out}, RGB: ${rgb}%03X")

                    val r = (rgb >> 8) & 0xF
                    val g = (rgb >> 4) & 0xF
                    val b = rgb & 0xF
                    
                    writer.println(s"$r $g $b")
                }
                valid_prev = dut.io.valid_out.peek().litToBoolean
                dut.clock.step(1)
            }
            writer.close()
            println("PPM image written to outputFull1.ppm")
        }
    }
}