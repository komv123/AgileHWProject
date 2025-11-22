// import chisel3._
// import chisel3.simulator.EphemeralSimulator._
// import chisel3.simulator.scalatest.ChiselSim
// import org.scalatest.flatspec.AnyFlatSpec

// class CompModSpec extends AnyFlatSpec with ChiselSim {
//   "ComputeModule" should "pass" in {
//     simulate(new CompMod(20, 15)) { dut =>
//       println("Start set")
//       // for (i <- 0 until 1) {
//       dut.io.xmid.poke(-5755256176L.S)
//       dut.io.ymid.poke(0L.S)
//       dut.io.zoom.poke(8589934592L.S)
//       dut.io.maxiter.poke(1000.U)
//       dut.io.new_params.poke(1.B)
//       dut.io.ready.poke(1.B)
//       dut.clock.step(1)
//       dut.io.new_params.poke(0.B)
//       var valid_prev = false
//       for (i <- 0 until 60000) {
//         val valid = dut.io.valid.peek()
//         val xrow = dut.io.i_out.peek().litValue
//         val yrow = dut.io.j_out.peek().litValue
//         if (xrow == 0 && yrow != 0){System.out.println("")} 
//         if (!valid_prev && valid.litToBoolean) {
//           val k_out = dut.io.k_out.peek().litValue.toInt
//           System.out.print(s"${k_out} ")
//         }
//         valid_prev = dut.io.valid.peek().litToBoolean
//         dut.clock.step(1)
//       }

//       // dut.io.xmid.poke(-3193384776L.S)
//       // dut.io.ymid.poke(545867056L.S)
//       // dut.io.zoom.poke(21474836L.S)
//       // dut.io.maxiter.poke(1000.U)
//       // dut.io.new_params.poke(1.B)
//       // dut.io.ready.poke(1.B)
//       // dut.clock.step(1)
//       // dut.io.new_params.poke(0.B)
//       // for (i <- 0 until 100000) {
//       //   val valid = dut.io.valid.peek()
//       //   val xrow = dut.io.i_out.peek().litValue
//       //   val yrow = dut.io.j_out.peek().litValue
//       //   if (xrow == 0 && yrow != 0){System.out.println("")} 
//       //   if (valid.litToBoolean) {
//       //     val k_out = dut.io.k_out.peek().litValue.toInt
//       //     System.out.print(s"${k_out} ")
//       //   }
//       //   dut.clock.step(1)
//       // }
//       println("\nEnd set")
//     }
//   }
// }

