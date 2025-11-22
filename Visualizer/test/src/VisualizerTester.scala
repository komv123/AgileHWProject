package visualizer

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

class VisualizerTester extends AnyFlatSpec with Matchers with ChiselSim {
  "Visulizer" should "pass" in {
    simulate(new Visualizer()) { dut =>
      dut.clock.step(100_000_000)
    }
  }
}
