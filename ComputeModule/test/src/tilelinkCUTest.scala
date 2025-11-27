import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._
import ComputeModule._

class TLCUSpec extends AnyFlatSpec with ChiselSim {
    
    "TLCUTest" should "render 32 x 32 " in {
        simulate(new CompColorWrapper(32, 64, 2)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"32 32")
            writer.println("15")

            dut.io.xmid.poke(-3193384776L.S)
            dut.io.ymid.poke(545867056L.S)
            dut.io.zoom.poke(21474836L.S)
            dut.io.maxiter.poke(1000.U)
            dut.io.start_address.poke(0.U)
            dut.io.new_params.poke(1.B)
            dut.clock.step(5)
            dut.io.new_params.poke(0.B)
            breakable{for (i <- 0 until 500000) {
                if(dut.io.tilelink_out.a.valid.peek().litToBoolean){break()}
                dut.clock.step(1)
            }}
            dut.io.tilelink_out.a.valid.expect(1.B)
            dut.io.tilelink_out.a.ready.poke(true.B)
            dut.io.tilelink_out.a.bits.size.expect(1023.U)
            dut.io.tilelink_out.a.bits.address.expect(0.U)

            for (i <- 0 until 1024){
                val rgb = dut.io.tilelink_out.a.bits.data.peek().litValue
                val r = (rgb >> 8) & 0xF
                val g = (rgb >> 4) & 0xF
                val b = rgb & 0xF

                writer.println(s"$r $g $b")
                dut.clock.step(1)
            }

            dut.io.tilelink_out.a.ready.poke(false.B)
            dut.io.tilelink_out.a.valid.expect(false.B)

            dut.clock.step(1)

            dut.io.tilelink_out.d.ready.expect(true.B)
            dut.io.tilelink_out.d.bits.opcode.poke(0.U)
            dut.io.tilelink_out.d.valid.poke(true.B)

            dut.clock.step(1)

            dut.io.tilelink_out.d.valid.poke(false.B)

            writer.close()
        }
    }

    /*
    "TLCUTest" should "render 64 x 64" in {
        simulate(new CompColorWrapper(64, 64, 1)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"64 64")
            writer.println("15")

            dut.io.xmid.poke(-3193384776L.S)
            dut.io.ymid.poke(545867056L.S)
            dut.io.zoom.poke(21474836L.S)
            dut.io.maxiter.poke(1000.U)
            dut.io.new_params.poke(1.B)
            dut.clock.step(5)
            dut.io.new_params.poke(0.B)

            var addr = 0

            for(i <- 0 until 4) {

                breakable{for (i <- 0 until 1000000) {
                    if(dut.io.tilelink_out.a.valid.peek().litToBoolean){break()}
                    dut.clock.step(1)
                }}


                dut.io.tilelink_out.a.valid.expect(1.B)
                dut.io.tilelink_out.a.ready.poke(true.B)
                dut.io.tilelink_out.a.bits.size.expect(1023.U)
                dut.io.tilelink_out.a.bits.address.expect(addr.U)

                addr += 1024

                for (i <- 0 until 1024){
                    val rgb = dut.io.tilelink_out.a.bits.data.peek().litValue
                    val r = (rgb >> 8) & 0xF
                    val g = (rgb >> 4) & 0xF
                    val b = rgb & 0xF

                    writer.println(s"$r $g $b")
                    dut.clock.step(1)
                }

                dut.io.tilelink_out.a.ready.poke(false.B)
                dut.io.tilelink_out.a.valid.expect(false.B)

                dut.clock.step(1)

                dut.io.tilelink_out.d.ready.expect(true.B)
                dut.io.tilelink_out.d.bits.opcode.poke(0.U)
                dut.io.tilelink_out.d.valid.poke(true.B)

                dut.clock.step(1)

                dut.io.tilelink_out.d.valid.poke(false.B)
            }


            writer.close()
        }
    }
    */
    /*
    "TLCUTest" should "render 96 x 96" in {
        simulate(new CompColorWrapper(96, 96, 1)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"96 96")
            writer.println("15")

            dut.io.xmid.poke(-3193384776L.S)
            dut.io.ymid.poke(545867056L.S)
            dut.io.zoom.poke(21474836L.S)
            dut.io.maxiter.poke(1000.U)
            dut.io.new_params.poke(1.B)
            dut.clock.step(5)
            dut.io.new_params.poke(0.B)

            var addr = 0

            for(i <- 0 until 9) {

                breakable{for (i <- 0 until 1000000) {
                    if(dut.io.tilelink_out.a.valid.peek().litToBoolean){break()}
                    dut.clock.step(1)
                }}


                dut.io.tilelink_out.a.valid.expect(1.B)
                dut.io.tilelink_out.a.ready.poke(true.B)
                dut.io.tilelink_out.a.bits.size.expect(1023.U)
                dut.io.tilelink_out.a.bits.address.expect(addr.U)

                addr += 1024

                for (i <- 0 until 1024){
                    val rgb = dut.io.tilelink_out.a.bits.data.peek().litValue
                    val r = (rgb >> 8) & 0xF
                    val g = (rgb >> 4) & 0xF
                    val b = rgb & 0xF

                    writer.println(s"$r $g $b")
                    dut.clock.step(1)
                }

                dut.io.tilelink_out.a.ready.poke(false.B)
                dut.io.tilelink_out.a.valid.expect(false.B)

                dut.clock.step(1)

                dut.io.tilelink_out.d.ready.expect(true.B)
                dut.io.tilelink_out.d.bits.opcode.poke(0.U)
                dut.io.tilelink_out.d.valid.poke(true.B)

                dut.clock.step(1)

                dut.io.tilelink_out.d.valid.poke(false.B)
            }


            writer.close()
        }
    }
    */
}
