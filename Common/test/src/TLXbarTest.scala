package Common

import chisel3._
import chisel3.util._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

import scala.util.Random
import scala.util.control.Breaks._


class TLXbarTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "TLXbar"

  // Create a test configuration without making it implicit to avoid ambiguity
  def testConfig: Configuration = Configuration.default()

  it should "route single master to single slave" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 1,
      slaves = Seq(
        TLSlaveConfig(Seq((0x00, 0xFFFF)))
      )
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      // Initialize
      dut.io.in(0).a.valid.poke(false.B)
      dut.io.out(0).d.valid.poke(false.B)
      dut.clock.step()

      // Send A channel request
      dut.io.in(0).a.bits.opcode.poke(4.U)  // Get
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(5.U)
      dut.io.in(0).a.bits.size.poke(3.U)
      dut.io.in(0).a.bits.mask.poke(0.U)
      dut.io.in(0).a.valid.poke(true.B)
      dut.io.out(0).a.ready.poke(true.B)

      dut.clock.step()
      
      // Check that request arrived at slave
      dut.io.out(0).a.valid.expect(true.B)
      dut.io.out(0).a.bits.address.expect(0x100.U)
      dut.io.out(0).a.bits.source.expect(5.U)
      dut.io.in(0).a.valid.poke(false.B)
      dut.clock.step()

      // Send D channel response
      dut.io.out(0).d.bits.opcode.poke(1.U)  // AccessAckData
      dut.io.out(0).d.bits.source.poke(5.U)
      dut.io.out(0).d.bits.data.poke(0xDEAD.U)
      dut.io.out(0).d.valid.poke(true.B)
      dut.io.in(0).d.ready.poke(true.B)

      dut.clock.step()

      // Check that response arrived at master
      dut.io.in(0).d.valid.expect(true.B)
      dut.io.in(0).d.bits.source.expect(5.U)
      dut.io.in(0).d.bits.data.expect(0xDEAD.U)
    }
  }

  it should "route requests to correct slaves based on address" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 1,
      slaves = Seq(
        TLSlaveConfig(Seq((0x0000, 0x00FF))),      // Slave 0: 0x0000-0xFFFF
        TLSlaveConfig(Seq((0x0100, 0x0E00))),     // Slave 1: 0x10000-0x1FFFF
        TLSlaveConfig(Seq((0x1000, 0xE000)))      // Slave 2: 0x20000-0x2FFFF
      )
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // Test routing to slave 0
      dut.io.in(0).a.bits.address.poke(0.U)
      dut.io.in(0).a.bits.source.poke(1.U)
      dut.io.in(0).a.bits.opcode.poke(4.U)
      dut.io.in(0).a.valid.poke(true.B)
      dut.io.out.foreach(_.a.ready.poke(true.B))

      dut.clock.step()
      dut.io.out(0).a.valid.expect(true.B)
      dut.io.out(1).a.valid.expect(false.B)
      dut.io.out(2).a.valid.expect(false.B)

      dut.io.in(0).a.valid.poke(false.B)
      dut.clock.step()

      // Test routing to slave 1
      //dut.io.in(0).a.bits.address.poke(0x15000.U)
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(2.U)
      dut.io.in(0).a.bits.opcode.poke(4.U)
      dut.io.in(0).a.valid.poke(true.B)

      dut.clock.step()

      /*
      breakable{
        for(i <- 0 until 10){
          dut.clock.step()

          val out: Boolean = dut.io.out(1).a.valid.peek().litToBoolean

          if(out === true) {
            break()
          }
        }
      }
      */

      dut.io.out(0).a.valid.expect(false.B)
      dut.io.out(1).a.valid.expect(true.B)
      dut.io.out(2).a.valid.expect(false.B)

      dut.io.in(0).a.valid.poke(false.B)
      dut.clock.step()

      // Test routing to slave 2
      //dut.io.in(0).a.bits.address.poke(0x28000.U)
      dut.io.in(0).a.bits.address.poke(0x1000.U)
      dut.io.in(0).a.bits.source.poke(3.U)
      dut.io.in(0).a.valid.poke(true.B)

      dut.clock.step()
      dut.io.out(0).a.valid.expect(false.B)
      dut.io.out(1).a.valid.expect(false.B)
      dut.io.out(2).a.valid.expect(true.B)
    }
  }

  it should "arbitrate between multiple masters for same slave" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 3,
      slaves = Seq(
        TLSlaveConfig(Seq((0x00, 0xFFFF)))
      ),
      arbiterPolicy = "lowestIndexFirst"
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // All masters request same slave simultaneously
      //dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(1.U)
      dut.io.in(0).a.bits.opcode.poke(4.U)
      dut.io.in(0).a.valid.poke(true.B)

      //dut.io.in(1).a.bits.address.poke(0x200.U)
      dut.io.in(1).a.bits.address.poke(0x200.U)
      dut.io.in(1).a.bits.source.poke(2.U)
      dut.io.in(1).a.bits.opcode.poke(4.U)
      dut.io.in(1).a.valid.poke(true.B)

      //dut.io.in(2).a.bits.address.poke(0x300.U)
      dut.io.in(2).a.bits.address.poke(0x300.U)
      dut.io.in(2).a.bits.source.poke(3.U)
      dut.io.in(2).a.bits.opcode.poke(4.U)
      dut.io.in(2).a.valid.poke(true.B)

      dut.io.out(0).a.ready.poke(true.B)

      dut.clock.step()

      // Master 0 should win (lowest index first policy)
      dut.io.in(0).a.ready.expect(true.B)
      dut.io.out(0).a.valid.expect(true.B)
      //dut.io.out(0).a.bits.address.expect(0x100.U)
      dut.io.out(0).a.bits.address.expect(0x100.U)

      // Deassert master 0
      dut.io.in(0).a.valid.poke(false.B)
      dut.clock.step()

      // Master 1 should now be granted
      dut.io.in(1).a.ready.expect(true.B)
      //dut.io.out(0).a.bits.address.expect(0x200.U)
      dut.io.out(0).a.bits.address.expect(0x200.U)
    }
  }

  it should "handle ID range translation correctly" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 2,
      slaves = Seq(
        TLSlaveConfig(Seq((0x00, 0xFFFF)))
      )
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // Master 0 sends request with source ID 5
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(5.U)
      dut.io.in(0).a.bits.opcode.poke(4.U)
      dut.io.in(0).a.valid.poke(true.B)
      dut.io.out(0).a.ready.poke(true.B)

      dut.clock.step()

      // Slave should see transformed ID (5 + offset)
      dut.io.out(0).a.valid.expect(true.B)
      val transformedId0 = dut.io.out(0).a.bits.source.peek().litValue

      dut.io.in(0).a.valid.poke(false.B)
      dut.clock.step()

      // Master 1 sends request with source ID 5
      dut.io.in(1).a.bits.address.poke(0x200.U)
      dut.io.in(1).a.bits.source.poke(5.U)
      dut.io.in(1).a.bits.opcode.poke(4.U)
      dut.io.in(1).a.valid.poke(true.B)

      dut.clock.step()

      // Slave should see different transformed ID
      dut.io.out(0).a.valid.expect(true.B)
      val transformedId1 = dut.io.out(0).a.bits.source.peek().litValue

      // IDs should be different
      assert(transformedId0 != transformedId1, "Source IDs from different masters should be unique")

      // Send response back to master 1
      dut.io.in(1).a.valid.poke(false.B)
      dut.clock.step()

      dut.io.out(0).d.bits.source.poke(transformedId1.U)
      dut.io.out(0).d.bits.opcode.poke(1.U)
      dut.io.out(0).d.valid.poke(true.B)
      dut.io.in(1).d.ready.poke(true.B)

      dut.clock.step()

      // Master 1 should receive response with original source ID
      dut.io.in(1).d.valid.expect(true.B)
      dut.io.in(1).d.bits.source.expect(5.U)
    }
  }


  it should "handle backpressure correctly" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 1,
      slaves = Seq(
        TLSlaveConfig(Seq((0x0, 0xFFFF)))
      )
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // Master sends request but slave is not ready
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(1.U)
      dut.io.in(0).a.bits.opcode.poke(4.U)
      dut.io.in(0).a.valid.poke(true.B)
      dut.io.out(0).a.ready.poke(false.B)

      dut.clock.step()

      // Master should not be ready
      dut.io.in(0).a.ready.expect(false.B)

      dut.clock.step()

      // Slave becomes ready
      dut.io.out(0).a.ready.poke(true.B)
      dut.clock.step()

      // Now master should be ready and transaction completes
      dut.io.in(0).a.ready.expect(true.B)
      dut.io.out(0).a.valid.expect(true.B)
    }
  }


  it should "handle concurrent transactions to different slaves" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 2,
      slaves = Seq(
        TLSlaveConfig(Seq((0x0000, 0xFFFF))),
        TLSlaveConfig(Seq((0x10000, 0xFFFF)))
      )
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // Master 0 -> Slave 0, Master 1 -> Slave 1 (no conflict)
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(1.U)
      dut.io.in(0).a.bits.opcode.poke(4.U)
      dut.io.in(0).a.valid.poke(true.B)

      dut.io.in(1).a.bits.address.poke(0x10100.U)
      dut.io.in(1).a.bits.source.poke(2.U)
      dut.io.in(1).a.bits.opcode.poke(4.U)
      dut.io.in(1).a.valid.poke(true.B)

      dut.io.out.foreach(_.a.ready.poke(true.B))

      dut.clock.step()

      // Both slaves should receive their respective requests
      dut.io.out(0).a.valid.expect(true.B)
      dut.io.out(0).a.bits.address.expect(0x100.U)

      dut.io.out(1).a.valid.expect(true.B)
      dut.io.out(1).a.bits.address.expect(0x10100.U)

      // Both masters should be ready
      dut.io.in(0).a.ready.expect(true.B)
      dut.io.in(1).a.ready.expect(true.B)
    }
  }

  it should "handle round-robin arbitration" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 3,
      slaves = Seq(
        TLSlaveConfig(Seq((0x0, 0xFFFF)))
      ),
      arbiterPolicy = "roundRobin"
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // All masters continuously request
      for (cycle <- 0 until 10) {
        dut.io.in(0).a.bits.address.poke((0x100 + cycle * 0x10).U)
        dut.io.in(0).a.bits.source.poke(1.U)
        dut.io.in(0).a.valid.poke(true.B)

        dut.io.in(1).a.bits.address.poke((0x200 + cycle * 0x10).U)
        dut.io.in(1).a.bits.source.poke(2.U)
        dut.io.in(1).a.valid.poke(true.B)

        dut.io.in(2).a.bits.address.poke((0x300 + cycle * 0x10).U)
        dut.io.in(2).a.bits.source.poke(3.U)
        dut.io.in(2).a.valid.poke(true.B)

        dut.io.out(0).a.ready.poke(true.B)

        dut.clock.step()

        // Log which master was granted
        val grantedAddr = dut.io.out(0).a.bits.address.peek().litValue
        val grantedMaster = if ((grantedAddr & 0xF00) == 0x100) 0
                           else if ((grantedAddr & 0xF00) == 0x200) 1
                           else 2
      }
    }
  }


  it should "handle multiple response routing" in {
    implicit val c = testConfig
    val xbarConfig = TLXbarConfig(
      nMasters = 2,
      slaves = Seq(
        TLSlaveConfig(Seq((0x0, 0xFFFF)))
      )
    )(c)

    simulate(new TLXbar(xbarConfig)) { dut =>
      dut.clock.step()

      // Send requests from both masters
      dut.io.in(0).a.bits.address.poke(0x100.U)
      dut.io.in(0).a.bits.source.poke(5.U)
      dut.io.in(0).a.valid.poke(true.B)
      dut.io.out(0).a.ready.poke(true.B)

      dut.clock.step()
      val source0 = dut.io.out(0).a.bits.source.peek().litValue

      dut.io.in(0).a.valid.poke(false.B)
      dut.clock.step()

      dut.io.in(1).a.bits.address.poke(0x200.U)
      dut.io.in(1).a.bits.source.poke(7.U)
      dut.io.in(1).a.valid.poke(true.B)

      dut.clock.step()
      val source1 = dut.io.out(0).a.bits.source.peek().litValue

      dut.io.in(1).a.valid.poke(false.B)
      dut.clock.step(2)

      // Send responses in reverse order
      dut.io.out(0).d.bits.source.poke(source1.U)
      dut.io.out(0).d.bits.data.poke(0xBEEF.U)
      dut.io.out(0).d.bits.opcode.poke(1.U)
      dut.io.out(0).d.valid.poke(true.B)
      dut.io.in(0).d.ready.poke(true.B)
      dut.io.in(1).d.ready.poke(true.B)

      dut.clock.step()

      // Response should go to master 1
      dut.io.in(1).d.valid.expect(true.B)
      dut.io.in(1).d.bits.source.expect(7.U)
      dut.io.in(0).d.bits.data.expect(0xBEEF.U)
      dut.io.in(0).d.bits.opcode.expect(1.U)

      dut.io.out(0).d.valid.poke(false.B)
      dut.clock.step()

      // Send response for master 0
      dut.io.out(0).d.bits.source.poke(source0.U)
      dut.io.out(0).d.bits.data.poke(0xDEAD.U)
      dut.io.out(0).d.valid.poke(true.B)

      dut.clock.step()

      // Response should go to master 0
      dut.io.in(0).d.valid.expect(true.B)
      dut.io.in(0).d.bits.source.expect(5.U)
      dut.io.in(0).d.bits.data.expect(0xDEAD.U)
    }
  }
}
