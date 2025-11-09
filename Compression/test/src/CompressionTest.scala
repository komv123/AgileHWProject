package Compression

import chisel3._
import chisel3.util._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers
import chisel3.simulator.scalatest.HasCliOptions.CliOption

import scala.util.Random

class CompressionTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "Compression"


  it should "Encode Unary" in {
    simulate(new Module {
      val io = IO(new Bundle {
        val quotient = Input(UInt(8.W))
        val remainder = Input(UInt(8.W))
        val k = Input(UInt(4.W))
        val cat = Output(UInt(12.W))
        //val index = Output(UInt(4.W))
        //val valid = Output(Bool())
        val index = Output(Valid(UInt(12.W)))

      })
      
      val (cat, index, valid) = Golomb.CalcGolomb(io.quotient, io.remainder, io.k)
      io.cat := cat
      io.index.bits := index
      io.index.valid := valid 
    }){ dut =>
      
      // Test case 1: Basic functionality
      dut.io.quotient.poke(3.U)
      dut.io.remainder.poke(2.U)
      dut.io.k.poke(2.U)
      dut.io.cat.expect("b00000000111".U)
      dut.io.index.valid.expect(true.B)
      dut.io.index.bits.expect(3.U)
      dut.clock.step()
      
      // TODO: Implement verification logic for cat and index outputs
      // Expected behavior: cat should contain the concatenated bits, index should indicate position
      
      // Test case 2: Edge case - quotient=0
      dut.io.quotient.poke(0.U)
      dut.io.remainder.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.cat.expect("b00000000000".U)
      dut.io.index.valid.expect(true.B)
      dut.io.index.bits.expect(0.U)
      dut.clock.step()
      
      // TODO: Verify edge case behavior
      
      // Test case 3: Larger quotient
      dut.io.quotient.poke(12.U)
      dut.io.remainder.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.cat.expect("b111111111111".U)
      dut.io.index.valid.expect(false.B)
      dut.io.index.bits.expect(0.U)
      dut.clock.step()
      
      // TODO: Verify larger quotient case
      
      // Test case 3: Larger quotient
      dut.io.quotient.poke(11.U)
      dut.io.remainder.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.cat.expect("b011111111111".U)
      dut.io.index.valid.expect(true.B)
      dut.io.index.bits.expect(11.U)
      dut.clock.step()
      
    }
  }
}
