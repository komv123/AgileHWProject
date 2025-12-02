// import chisel3._
// import chisel3.simulator.EphemeralSimulator._
// import chisel3.simulator.scalatest.ChiselSim
// import org.scalatest.flatspec.AnyFlatSpec
// import ComputeModule._

// class ParamSpec extends AnyFlatSpec with ChiselSim {

//     "Parameters" should "output" in {
//         simulate(new Parameters()) { dut =>
//         dut.io.select.poke(0.U)
//         dut.io.enter.poke(1.B)
//         dut.clock.step(5)
//         dut.io.enter.poke(0.B)

//         dut.clock.step(5)
//         dut.io.select.poke(1.U)
//         dut.io.enter.poke(1.B)
//         dut.clock.step(5)
//         dut.io.enter.poke(0.B)
//         }
//     }
// }