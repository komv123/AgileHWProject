import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import java.io.PrintWriter
import scala.util.control.Breaks._
import ComputeModule._

class TLCUSpec extends AnyFlatSpec with ChiselSim {

    "TLCUTest" should "render 32 x 32 " in {
        // Create compute config inline
        val computeConfig = ComputeConfig(
            width = 32,
            height = 32,
            maxiter = 1000
        )

        simulate(new CompColorWrapper(computeConfig)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"32 32")
            writer.println("15")

            // Q16.16 fixed-point values (converted from Q32.32 by >> 16)
            dut.io.xmid.poke(-48729.S)  // -3193384776 >> 16
            dut.io.ymid.poke(8329.S)    // 545867056 >> 16
            dut.io.zoom.poke(328.S)     // 21474836 >> 16
            //dut.io.maxiter.poke(1000.U)
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
                //println(f"RGB: ${rgb}%03X")
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
        val computeConfig = ComputeConfig(
            width = 64,
            height = 64,
            maxiter = 1000
        )

        simulate(new CompColorWrapper(computeConfig, n = 1, start_address = 0)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"64 64")
            writer.println("15")

            // Q16.16 fixed-point values (converted from Q32.32 by >> 16)
            dut.io.xmid.poke(-48729.S)  // -3193384776 >> 16
            dut.io.ymid.poke(8329.S)    // 545867056 >> 16
            dut.io.zoom.poke(328.S)     // 21474836 >> 16
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
        val computeConfig = ComputeConfig(
            width = 96,
            height = 96,
            maxiter = 1000
        )

        simulate(new CompColorWrapper(computeConfig, n = 1, start_address = 0)) { dut =>
            val writer = new PrintWriter("output.ppm")

            // PPM header
            writer.println("P3")
            writer.println(s"96 96")
            writer.println("15")

            // Q16.16 fixed-point values (converted from Q32.32 by >> 16)
            dut.io.xmid.poke(-48729.S)  // -3193384776 >> 16
            dut.io.ymid.poke(8329.S)    // 545867056 >> 16
            dut.io.zoom.poke(328.S)     // 21474836 >> 16
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
                    //println(f"RGB: ${rgb}%03X")
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
