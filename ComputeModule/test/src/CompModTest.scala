import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import ComputeModule._

class CompModSpec extends AnyFlatSpec with ChiselSim {
  "ComputeModule" should "pass" in {
    val computeConfig = ComputeConfig(width = 4, height = 2, maxiter = 256)
    simulate(new CompMod(computeConfig, n = 1, start_address = 0)) { dut =>
      dut.io.xmid.poke(-49152.S)
      dut.io.ymid.poke(0.S)
      dut.io.zoom.poke(196608.S)
      dut.io.id.poke(1.U)
      dut.io.ready.poke(true.B)

      var seen = 0
      val expected = computeConfig.width * computeConfig.height

      for (_ <- 0 until 10000 if seen < expected) {
        if (dut.io.valid.peek().litToBoolean) {
          val k_out = dut.io.k_out.peek().litValue.toInt
          assert(k_out >= 0 && k_out <= computeConfig.maxiter, s"Unexpected k_out $k_out")
          seen += 1
        }
        dut.clock.step()
      }

      assert(seen == expected, s"Expected $expected pixels, saw $seen")
    }
  }
}