import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._

class PipelineTest extends AnyFlatSpec with ChiselSim {
    "TLCUTest" should "render 32 x 32 " in {
        simulate(new Pipeline(32, 32)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"32 32")
            writer.println("15")

            dut.io.xmid.poke(-3193384776L.S)
            dut.io.ymid.poke(545867056L.S)
            dut.io.zoom.poke(21474836L.S)
            dut.io.maxiter.poke(1000.U)

            dut.io.framePointer.poke(0.U)
            dut.io.bufferPointer.poke(0.U)

            dut.io.new_params.poke(1.B)

            dut.clock.step(5)
            dut.io.new_params.poke(0.B)
            breakable{for (i <- 0 until 1000000) {
                dut.clock.step(1)
            }}

            for (i <- 0 until 1024){
                dut.io.ReadData.request.valid.poke(true.B)

                val rgb = dut.io.ReadData.response.bits.readData.peek().litValue
                println(f"RGB: ${rgb}%03X")
                val r = (rgb >> 8) & 0xF
                val g = (rgb >> 4) & 0xF
                val b = rgb & 0xF

                writer.println(s"$r $g $b")
                dut.clock.step(1)
            }

            writer.close()
        }
    }
}