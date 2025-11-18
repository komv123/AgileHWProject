package VideoBuffer 

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers
import chisel3.simulator.scalatest.HasCliOptions.CliOption

import scala.util.Random

import Common.Configuration


class VideoBufferTester extends AnyFlatSpec with Matchers with ChiselSim {
  behavior of "VideoBuffer"


  it should "single write and read" in {

    val random = new Random()
    val numWords = 1  
    
    //val randInt = Array.fill(numWords)(Random.nextInt(4096))
    val randInt = Random.nextInt(4096)

    //simulate(new VideoBuffer(Configuration.default())).withAnnotations(Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
    simulate(new VideoBuffer(Configuration.default())) { dut =>
      // Tilelink burst write Transaction
      
      dut.io.tilelink.a.ready.expect(true.B)
      dut.io.tilelink.d.valid.expect(false.B)

      dut.clock.step(1)

      dut.io.tilelink.a.bits.opcode.poke(0.U)
      dut.io.tilelink.a.bits.source.poke(1.U)
      dut.io.tilelink.a.bits.size.poke(0.U)
      dut.io.tilelink.a.bits.address.poke(0.U)
      dut.io.tilelink.a.bits.mask.poke(7.U)
      dut.io.tilelink.a.bits.data.poke(randInt.asUInt)

      dut.io.tilelink.a.valid.poke(true.B)
      dut.io.tilelink.a.ready.expect(true.B)

      dut.clock.step(1)

      // Ack ready
      dut.io.tilelink.a.ready.expect(false.B)
      dut.io.tilelink.d.valid.expect(true.B)

      dut.clock.step(Random.nextInt(64) + 1) 

      // Accept Ack
      dut.io.tilelink.d.valid.expect(true.B)
      dut.io.tilelink.d.bits.opcode.expect(0.U) // AccessAck
      dut.io.tilelink.d.bits.size.expect(0.U) 
      dut.io.tilelink.d.bits.source.expect(1.U) // Source = 1

      dut.io.tilelink.d.ready.poke(true.B)

      dut.clock.step(1)
      
      // Transaction complete
      dut.io.tilelink.a.ready.expect(true.B)
      dut.io.tilelink.d.valid.expect(false.B)

      /////// Pop from the buffer ///////
      
      dut.io.ReadData.request.bits.addr.poke(0.U)
      dut.io.ReadData.request.valid.poke(true.B)
      dut.io.ReadData.response.bits.readData.expect(randInt.asUInt(12.W))

      dut.clock.step(1)
    }
  }
  
  it should "burst write and read" in {

    val random = new Random()
    val numWords = 16
    
    val randInt = Array.fill(numWords)(Random.nextInt(4096))

    //simulate(new VideoBuffer(Configuration.default())).withAnnotations(Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
    simulate(new VideoBuffer(Configuration.default())) { dut =>
      // Tilelink burst write Transaction
      
      dut.io.tilelink.a.ready.expect(true.B)
      dut.io.tilelink.d.valid.expect(false.B)

      dut.clock.step(1)

      // Write 16 words
      for (i <- 0 until numWords) {
        dut.io.tilelink.a.bits.opcode.poke(0.U)
        dut.io.tilelink.a.bits.source.poke(1.U)
        dut.io.tilelink.a.bits.size.poke(15.U)
        dut.io.tilelink.a.bits.address.poke(0.U)
        dut.io.tilelink.a.bits.mask.poke(7.U)
        dut.io.tilelink.a.bits.data.poke(randInt(i).asUInt)

        dut.io.tilelink.a.valid.poke(true.B)
        dut.io.tilelink.a.ready.expect(true.B)

        dut.clock.step(1)
			}

      // Ack ready
      dut.io.tilelink.a.ready.expect(false.B)
      dut.io.tilelink.d.valid.expect(true.B)

      dut.clock.step(Random.nextInt(64) + 1) 

      // Accept Ack
      dut.io.tilelink.d.valid.expect(true.B)
      dut.io.tilelink.d.bits.opcode.expect(0.U) // AccessAck
      dut.io.tilelink.d.bits.size.expect(0.U) 
      dut.io.tilelink.d.bits.source.expect(1.U) // Source = 1

      dut.io.tilelink.d.ready.poke(true.B)

      dut.clock.step(1)
      
      // Transaction complete
      dut.io.tilelink.a.ready.expect(true.B)
      dut.io.tilelink.d.valid.expect(false.B)


      /////// Pop from the buffer ///////
      
      for (i <- 0 until numWords) {
        dut.io.ReadData.request.bits.addr.poke(i.U)
        dut.io.ReadData.request.ready.expect(true.B)
        dut.io.ReadData.request.valid.poke(true.B)
        dut.io.ReadData.response.bits.readData.expect(randInt(i).asUInt(12.W))

        dut.clock.step(1)
			}
    }
  }
}
