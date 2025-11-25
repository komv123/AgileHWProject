// import chisel3._
// import chisel3.simulator.EphemeralSimulator._
// import chisel3.simulator.scalatest.ChiselSim
// import org.scalatest.flatspec.AnyFlatSpec
// import java.io.PrintWriter

// class ColorSpec extends AnyFlatSpec with ChiselSim {
//   "ColorMatch" should "pass" in {
//     simulate(new ColorMatch()) { dut =>
//       val width = 100
//       val height = 10
//       val maxiter = 1000
//       val writer = new PrintWriter("output.ppm")

//       // PPM header
//       writer.println("P3")
//       writer.println(s"$width $height")
//       writer.println("15")


//       val dataSet = Seq.tabulate(1000)(i => (i + 1).U)
//       println("Start color matching")
//       dut.clock.step(3)
//       for (i <- dataSet){
//         dut.io.k_in.poke(i)
//         dut.io.valid_in.poke(1.B)
//         dut.io.maxiter_in.poke(1000)

//         dut.clock.step(3)
//         dut.io.valid_in.poke(0.B)
//         dut.clock.step(5)

//         if(dut.io.valid_out.peek().litToBoolean){
//           val rgb = dut.io.rgb_out.peek().litValue
//           println(f" k: ${i.litValue.toInt}, RGB: ${rgb}%03X")

//           val r = (rgb >> 8) & 0xF
//           val g = (rgb >> 4) & 0xF
//           val b = rgb & 0xF
          
//           writer.println(s"$r $g $b")
//         }
//       }
//       writer.close()
//       println("PPM image written to output.ppm")
//     }
//   }
// }