package MMU 

import chisel3._
import chisel3.util._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers
import chisel3.simulator.scalatest.HasCliOptions.CliOption
import Common._

import scala.util.Random

class MMUTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "MMU"

  it should "accept writes to addresses in scope" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = 0 
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test write to address within scope
      val virtualAddr = framePos + 50  // Within frame
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(0.U) // Single beat
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0xDEAD.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should be ready to accept the transaction
      dut.io.tilelink_in.a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)
    }
  }

  it should "reject writes to addresses out of scope" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = 0 
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test write to address outside scope
      val virtualAddr = framePos + c.bufferSize + 10  // Outside frame buffer
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(0.U) // Single beat
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0xDEAD.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.tilelink_in.a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }

  it should "reject burst writes to addresses out of scope" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = 0 
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test write to address outside scope
      val virtualAddr = framePos // In scope 
      val size = c.bufferSize + 10  // Outside frame buffer
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      //dut.io.tilelink_in.a.bits.size.poke(0.U) // Single beat
      dut.io.tilelink_in.a.bits.size.poke(size.U) // Burst 
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0xDEAD.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.tilelink_in.a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }

  it should "reject burst writes to wrapped addresses out of scope" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = 0 
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test write to address outside scope
      val virtualAddr = framePos + c.bufferSize + 100 // In scope 
      val size = c.bufferSize + 10  // Outside frame buffer
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      //dut.io.tilelink_in.a.bits.size.poke(0.U) // Single beat
      dut.io.tilelink_in.a.bits.size.poke(size.U) // Burst 
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0xDEAD.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.tilelink_in.a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }


  it should "reject too large wrapped burst writes" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = 928 
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test write to address outside scope
      val virtualAddr = framePos // In scope 
      val size = c.bufferSize + 10  // Outside frame buffer
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      //dut.io.tilelink_in.a.bits.size.poke(0.U) // Single beat
      dut.io.tilelink_in.a.bits.size.poke(size.U) // Burst 
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0xDEAD.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.tilelink_in.a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }



  it should "handle burst writes correctly" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = 100
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test burst write within scope
      val virtualAddr = framePos + 10
      val burstSize = 4
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(burstSize.U)
      dut.io.tilelink_in.a.bits.source.poke(2.U)
      dut.io.tilelink_in.a.bits.data.poke(0xCAFE.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should accept the transaction
      dut.io.tilelink_in.a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)
    }
  }

  it should "handle burst writes correctly with frame wrap" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = c.bufferSize - 100
      val framePos = c.frameSize - 50 
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test burst write within scope
      val virtualAddr = 0  
      val burstSize = 10 
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(burstSize.U)
      dut.io.tilelink_in.a.bits.source.poke(2.U)
      dut.io.tilelink_in.a.bits.data.poke(0xCAFE.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should accept the transaction
      dut.io.tilelink_in.a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)
    }
  }


  it should "correctly translate virtual addresses to physical addresses" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      val bufferPos = 200
      val framePos = 1228 
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      val virtualAddr = framePos + 50
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U)
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(0.U)
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0x1234.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Check that the output address is correctly translated
      // Expected physical address based on translateAddress function
      val expectedAddr = bufferPos + (virtualAddr - framePos)
      dut.io.tilelink_out.a.bits.address.expect(expectedAddr.U)
    }
  }

  it should "correctly translate virtual addresses to physical addresses with buffer wrap" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      val bufferPos = 928
      val framePos = 928 
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      val virtualAddr = framePos + 200 
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U)
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(0.U)
      dut.io.tilelink_in.a.bits.source.poke(1.U)
      dut.io.tilelink_in.a.bits.data.poke(0x1234.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Check that the output address is correctly translated
      // Expected physical address based on translateAddress function
      //val expectedAddr = bufferPos + (virtualAddr - framePos)
      val expectedAddr = 100 
      dut.io.tilelink_out.a.bits.address.expect(expectedAddr.U)
    }
  }


  it should "correctly translate virtual addresses to physical addresses with frame wrap" in {
    implicit val c = Configuration.default()
    
    simulate(new MMU()(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      // Set buffer and frame pointers
      val bufferPos = c.bufferSize - 50 
      val framePos = c.frameSize - 100 
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      // Test burst write within scope
      val virtualAddr = 0  
      val burstSize = 100 
      dut.io.tilelink_in.a.valid.poke(true.B)
      dut.io.tilelink_in.a.bits.opcode.poke(0.U) // Write
      dut.io.tilelink_in.a.bits.address.poke(virtualAddr.U)
      dut.io.tilelink_in.a.bits.size.poke(burstSize.U)
      dut.io.tilelink_in.a.bits.source.poke(2.U)
      dut.io.tilelink_in.a.bits.data.poke(0xCAFE.U)
      //dut.io.tilelink_in.a.bits.mask.poke(0x7.U)
      dut.io.tilelink_in.a.bits.mask.poke(0x0.U)
      dut.io.tilelink_in.a.bits.param.poke(0.U)
      dut.io.tilelink_in.a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.tilelink_in.d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should accept the transaction
      dut.io.tilelink_in.a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)

      // ((framePointer + virtualAddr) - config.frameSize.U))
      val expectedAddr = 50 
      dut.io.tilelink_out.a.bits.address.expect(expectedAddr.U)
    }
  }


}
