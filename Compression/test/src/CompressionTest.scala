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
      
      val (cat, index, valid) = Golomb.CalcGolomb(io.quotient)
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

  it should "Encode Golomb-rice" in {
    simulate(new Module {
      val io = IO(new Bundle {
        val quotient = Input(UInt(12.W))
        val remainder = Input(UInt(12.W))
        val k = Input(UInt(4.W))
        val offset = Input(UInt(5.W))
        val writeString = Output(UInt(36.W))
        val writeMask = Output(UInt(36.W))
        val done = Output(Bool())
      })

      val (writeString, writeMask, done, fill) = Golomb.GenWriteString(io.quotient, io.remainder, io.k, io.offset)
      
      io.writeString := writeString
      io.writeMask := writeMask
      io.done := done 
    }){ dut =>
      
      // Basic functionality
      dut.io.quotient.poke(3.U)
      dut.io.remainder.poke(2.U)
      dut.io.k.poke(2.U)
      dut.io.offset.poke(0.U)
      dut.io.writeString.expect("b111010".U)
      dut.io.writeMask.expect("b111111".U)
      dut.io.done.expect(true.B)
      dut.clock.step()

      // Test offset 
      dut.io.quotient.poke(3.U)
      dut.io.remainder.poke(2.U)
      dut.io.k.poke(2.U)
      dut.io.offset.poke(1.U)
      dut.io.writeString.expect("b1110100".U)
      dut.io.writeMask.expect("b1111110".U)
      dut.io.done.expect(true.B)
      dut.clock.step()


      // Test large quotient 
      dut.io.quotient.poke(12.U)
      dut.io.remainder.poke(2.U)
      dut.io.k.poke(2.U)
      dut.io.offset.poke(0.U)
      //dut.io.writeString.expect("b111111111111010".U)
      //dut.io.writeMask.expect("b111111111111111".U)
      dut.io.writeString.expect("b111111111111".U)
      dut.io.writeMask.expect("b111111111111".U)
      dut.io.done.expect(false.B)
      dut.clock.step()

      // Test larger quotient 
      dut.io.quotient.poke(13.U)
      dut.io.remainder.poke(2.U)
      dut.io.k.poke(2.U)
      dut.io.offset.poke(0.U)
      dut.io.writeString.expect("b111111111111".U)
      dut.io.writeMask.expect("b111111111111".U)
      dut.io.done.expect(false.B)
      dut.clock.step()

      // Test zero quotient 
      dut.io.quotient.poke(0.U)
      dut.io.remainder.poke(2.U)
      dut.io.k.poke(2.U)
      dut.io.offset.poke(0.U)
      dut.io.writeString.expect("b010".U)
      dut.io.writeMask.expect("b111".U)
      dut.io.done.expect(true.B)
      dut.clock.step()

    }
  }

  it should "GolombEncode Module Test" in {
    implicit val c = Configuration.default()
    
    simulate(new GolombEncode()) { dut =>
      
      // Initialize
      dut.clock.step()

      dut.io.k_override.valid.poke(true.B)
      dut.io.k_override.bits.poke(2.U)
      
      // Test case 1: Basic encoding with small positive diff
      dut.io.request.bits.diff.poke(5.S)
      dut.io.request.valid.poke(true.B)
      dut.io.out.request.ready.poke(true.B)
      
      // Should transition to state 1 and accept input
      dut.clock.step()
      dut.io.request.valid.poke(false.B)
      
      // Wait for encoding to complete and output to be available
      var cycles = 0
      while (!dut.io.out.request.valid.peekBoolean() && cycles < 10) {
        dut.clock.step()
        cycles += 1
      }
      
      // Verify output is valid
      if (dut.io.out.request.valid.peekBoolean()) {
        println(s"Encoded output: ${dut.io.out.request.bits.data.peek().litValue}")
      }
      
      // Test case 2: Negative diff
      dut.io.request.bits.diff.poke(-3.S)
      dut.io.request.valid.poke(true.B)
      
      dut.clock.step()
      dut.io.request.valid.poke(false.B)
      
      // Wait for completion
      cycles = 0
      while (!dut.io.out.request.valid.peekBoolean() && cycles < 10) {
        dut.clock.step()
        cycles += 1
      }
      
      if (dut.io.out.request.valid.peekBoolean()) {
        println(s"Negative diff encoded output: ${dut.io.out.request.bits.data.peek().litValue}")
      }
      
      // Test case 3: Zero diff
      dut.io.request.bits.diff.poke(0.S)
      dut.io.request.valid.poke(true.B)
      
      dut.clock.step()
      dut.io.request.valid.poke(false.B)
      
      // Wait for completion
      cycles = 0
      while (!dut.io.out.request.valid.peekBoolean() && cycles < 10) {
        dut.clock.step()
        cycles += 1
      }
      
      if (dut.io.out.request.valid.peekBoolean()) {
        println(s"Zero diff encoded output: ${dut.io.out.request.bits.data.peek().litValue}")
      }
      
      // Test case 4: Large positive diff that might trigger wait state
      dut.io.request.bits.diff.poke(50.S)
      dut.io.request.valid.poke(true.B)
      dut.io.out.request.ready.poke(false.B) // Force backpressure
      
      dut.clock.step()
      dut.io.request.valid.poke(false.B)
      
      // Step a few cycles with output not ready
      for (i <- 0 until 5) {
        dut.clock.step()
      }
      
      // Now allow output
      dut.io.out.request.ready.poke(true.B)
      
      // Wait for completion
      cycles = 0
      while (!dut.io.out.request.valid.peekBoolean() && cycles < 15) {
        dut.clock.step()
        cycles += 1
      }
      
      if (dut.io.out.request.valid.peekBoolean()) {
        println(s"Large diff encoded output: ${dut.io.out.request.bits.data.peek().litValue}")
      }
      
      // Test case 5: Sequence of inputs to test state transitions
      val testSequence = Seq(1.S, -1.S, 2.S, -2.S, 10.S)
      
      for (diff <- testSequence) {
        dut.io.request.bits.diff.poke(diff)
        dut.io.request.valid.poke(true.B)
        
        dut.clock.step()
        dut.io.request.valid.poke(false.B)
        
        // Wait for encoding to complete
        cycles = 0
        while (!dut.io.out.request.valid.peekBoolean() && cycles < 10) {
          dut.clock.step()
          cycles += 1
        }
        
        if (dut.io.out.request.valid.peekBoolean()) {
          println(s"Sequence diff ${diff} encoded output: ${dut.io.out.request.bits.data.peek().litValue}")
        }
      }
      
      dut.clock.step(10)
    }
  }
}
