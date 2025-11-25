// import chisel3._
// import chisel3.simulator.EphemeralSimulator._
// import chisel3.simulator.scalatest.ChiselSim
// import org.scalatest.flatspec.AnyFlatSpec
// import java.io.PrintWriter
// import scala.util.control.Breaks._

// class CMColorSpec extends AnyFlatSpec with ChiselSim {
//     "FullTest" should "pass" in {
//         val width = 64
//         val height = 48
//         simulate(new CompColorWrapper(width, height, 1)) { dut =>
//             println("Generating output.ppm")
//             val writer = new PrintWriter("outputFull1.ppm")

//             // PPM header
//             writer.println("P3")
//             writer.println(s"$width $height")
//             writer.println("15")

//             println("Start full test")

//             // dut.io.xmid.poke(-5755256176L.S)
//             // dut.io.ymid.poke(0L.S)
//             // dut.io.zoom.poke(8589934592L.S)
//             dut.io.xmid.poke(-3193384776L.S)
//             dut.io.ymid.poke(545867056L.S)
//             dut.io.zoom.poke(21474836L.S)
//             dut.io.maxiter.poke(1000.U)
//             dut.io.new_params.poke(1.B)
//             dut.clock.step(5)
//             dut.io.new_params.poke(0.B)
//             var valid_prev = false
//             var y_prev = 0
//             breakable 
//             {for (i <- 0 until 1000000) {
//                 val valid = dut.io.valid_out.peek().litToBoolean
//                 val yrow = dut.io.j_out.peek().litValue.toInt
//                 if (y_prev > yrow) {break()}
//                 if (!valid_prev && valid) {
//                     val k_out = dut.io.k_out.peek().litValue.toInt
//                     val rgb = dut.io.rgb_out.peek().litValue
//                     println(f"${yrow} k: ${k_out}, RGB: ${rgb}%03X")

//                     val r = (rgb >> 8) & 0xF
//                     val g = (rgb >> 4) & 0xF
//                     val b = rgb & 0xF
                    
//                     writer.println(s"$r $g $b")
//                 }
//                 y_prev = dut.io.j_out.peek().litValue.toInt
//                 valid_prev = dut.io.valid_out.peek().litToBoolean
//                 dut.clock.step(1)
//             }}
//             writer.close()
//             println("PPM image written to outputFull1.ppm")
//         }
//     }
// }