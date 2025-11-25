package MMU

import chisel3._
import chisel3.util._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers
import Common._

import scala.util.Random

class XBarMMUIntegrationTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "XBar + MMU Integration"

  /**
   * Simple architecture: N Masters -> XBar (1 output) -> MMU -> Memory
   */
  class XBarMMUTestHarness(nMasters: Int = 2)(implicit config: Configuration) extends Module {
    val io = IO(new Bundle {
      val masters = Flipped(Vec(nMasters, new Tilelink()(config)))
      val tilelink_out = new Tilelink()(config)
      val bufferPointer = Input(UInt(log2Ceil(config.bufferSize).W))
      val framePointer = Input(UInt(24.W))
    })

    // XBar: N inputs -> 1 output
    val xbarConfig = TLXbarConfig(
      nMasters = nMasters,
      slaves = Seq(
        TLSlaveConfig(Seq((0x0000, 0xFFFF)))  // Full address space
      )
    )(config)

    val xbar = Module(new TLXbar(xbarConfig))
    xbar.io.in <> io.masters

    // MMU after XBar
    val mmu = Module(new MMU()(config))
    mmu.io.tilelink_in <> xbar.io.out(0)
    mmu.io.bufferPointer := io.bufferPointer
    mmu.io.framePointer := io.framePointer

    // MMU output to memory
    mmu.io.tilelink_out <> io.tilelink_out
  }

  it should "route from single master through XBar and MMU to memory" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()

      // Set up MMU
      val bufferPos = 0
      val framePos = 0
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)

      // Master sends request
      val virtualAddr = framePos + 50 
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(0.U) // Single beat
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0xDEAD.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should be ready to accept the transaction
      dut.io.masters(0).a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)
    }
  }
  it should "reject writes to addresses out of scope" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(0.U) // Single beat
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0xDEAD.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.masters(0).a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }

  it should "reject burst writes to addresses out of scope" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      //dut.io.masters(0).a.bits.size.poke(0.U) // Single beat
      dut.io.masters(0).a.bits.size.poke(size.U) // Burst 
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0xDEAD.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.masters(0).a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }

  it should "reject burst writes to wrapped addresses out of scope" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      //dut.io.masters(0).a.bits.size.poke(0.U) // Single beat
      dut.io.masters(0).a.bits.size.poke(size.U) // Burst 
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0xDEAD.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.masters(0).a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }


  it should "reject too large wrapped burst writes" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      //dut.io.masters(0).a.bits.size.poke(0.U) // Single beat
      dut.io.masters(0).a.bits.size.poke(size.U) // Burst 
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0xDEAD.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should reject the transaction (not ready)
      dut.io.masters(0).a.ready.expect(false.B)
      dut.io.tilelink_out.a.valid.expect(false.B)
    }
  }



  it should "handle burst writes correctly" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(burstSize.U)
      dut.io.masters(0).a.bits.source.poke(2.U)
      dut.io.masters(0).a.bits.data.poke(0xCAFE.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should accept the transaction
      dut.io.masters(0).a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)
    }
  }

  it should "handle burst writes correctly with frame wrap" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(burstSize.U)
      dut.io.masters(0).a.bits.source.poke(2.U)
      dut.io.masters(0).a.bits.data.poke(0xCAFE.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should accept the transaction
      dut.io.masters(0).a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)
    }
  }


  it should "correctly translate virtual addresses to physical addresses" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      val bufferPos = 200
      val framePos = 1228 
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      val virtualAddr = framePos + 50
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U)
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(0.U)
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0x1234.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Check that the output address is correctly translated
      // Expected physical address based on translateAddress function
      val expectedAddr = bufferPos + (virtualAddr - framePos)
      dut.io.tilelink_out.a.bits.address.expect(expectedAddr.U)
    }
  }

  it should "correctly translate virtual addresses to physical addresses with buffer wrap" in {
    implicit val c = Configuration.default()

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)
      dut.clock.step()
      
      val bufferPos = c.bufferSize - 100 
      val framePos = c.bufferSize - 100 
      dut.io.bufferPointer.poke(bufferPos.U)
      dut.io.framePointer.poke(framePos.U)
      
      val virtualAddr = framePos + 200 
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U)
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(0.U)
      dut.io.masters(0).a.bits.source.poke(1.U)
      dut.io.masters(0).a.bits.data.poke(0x1234.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.masters(0).d.ready.poke(true.B)
      
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

    simulate(new XBarMMUTestHarness(nMasters = 1)(c)) { dut =>
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
      dut.io.masters(0).a.valid.poke(true.B)
      dut.io.masters(0).a.bits.opcode.poke(0.U) // Write
      dut.io.masters(0).a.bits.address.poke(virtualAddr.U)
      dut.io.masters(0).a.bits.size.poke(burstSize.U)
      dut.io.masters(0).a.bits.source.poke(2.U)
      dut.io.masters(0).a.bits.data.poke(0xCAFE.U)
      //dut.io.masters(0).a.bits.mask.poke(0x7.U)
      dut.io.masters(0).a.bits.mask.poke(0x0.U)
      dut.io.masters(0).a.bits.param.poke(0.U)
      dut.io.masters(0).a.bits.corrupt.poke(false.B)
      
      dut.io.tilelink_out.a.ready.poke(true.B)
      dut.io.masters(0).d.ready.poke(true.B)
      
      dut.clock.step()
      
      // Should accept the transaction
      dut.io.masters(0).a.ready.expect(true.B)
      dut.io.tilelink_out.a.valid.expect(true.B)

      // ((framePointer + virtualAddr) - config.frameSize.U))
      val expectedAddr = 50 
      dut.io.tilelink_out.a.bits.address.expect(expectedAddr.U)
    }
  }
}
