import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec

class CompModSpec extends AnyFlatSpec with ChiselSim {
  "ComputeModule" should "pass" in {
    simulate(new CompMod()) { dut =>
      println("Start set")
      for (i <- 0 until 10) {
        dut.clock.step(1000)
        val valid = dut.io.valid.peek()
        if (valid.litToBoolean) {
          val k_out = dut.io.k_out.peek().litValue.toInt
          System.out.println(k_out)
        }
      }
      println("End set")
    }
  }
}

