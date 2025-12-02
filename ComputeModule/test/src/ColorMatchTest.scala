import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import ComputeModule._

class ColorSpec extends AnyFlatSpec with ChiselSim {
  "ColorMatch" should "pass" in {
    simulate(new ColorMatch(1000)) { dut =>
      dut.io.buffer_ready.poke(true.B)

      def driveSample(k: Int): BigInt = {
        dut.io.k_in.poke(k.U)
        dut.io.valid_in.poke(true.B)
        dut.clock.step()
        dut.io.valid_in.poke(false.B)

        var seen = false
        var rgb: BigInt = 0
        for (_ <- 0 until 5 if !seen) {
          dut.clock.step()
          if (dut.io.valid_out.peek().litToBoolean) {
            rgb = dut.io.rgb_out.peek().litValue
            dut.io.ready.expect(true.B)
            seen = true
          }
        }
        assert(seen, s"ColorMatch did not produce output for k=$k")
        rgb
      }

      val samples = Seq(0, 1, 128, 512, 999).map(driveSample)
      assert(samples.distinct.size >= 3, "Expected varied color outputs across sample ks")
    }
  }
}