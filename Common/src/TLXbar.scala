package Common
import chisel3._
import chisel3.util._

// Configuration for each slave port
case class TLSlaveConfig(
  addressSet: Seq[(BigInt, BigInt)], // Seq of (base, mask) pairs
  beatBytes: Int = 8
)

// Crossbar configuration
case class TLXbarConfig(
  nMasters: Int,
  slaves: Seq[TLSlaveConfig],
  arbiterPolicy: String = "roundRobin" // or "lowestIndexFirst"
)(implicit val c: Configuration)

class TLXbar(config: TLXbarConfig) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Vec(config.nMasters, new Tilelink()(config.c)))
    val out = Vec(config.slaves.size, new Tilelink()(config.c))
  })

  val nMasters = config.nMasters
  val nSlaves = config.slaves.size

  // =========================================================================
  // ID Range Assignment
  // =========================================================================
  def assignIdRanges(sizes: Seq[Int]): Seq[(Int, Int)] = {
    val pow2Sizes = sizes.map(z => if (z == 0) 0 else 1 << log2Ceil(z))
    val indexed = pow2Sizes.zipWithIndex.sortBy(_._1)
    val starts = indexed.scanRight(0)(_._1 + _).tail
    indexed.zip(starts)
      .map { case ((sz, i), st) => (if (sz == 0) (0, 0) else (st, st + sz), i) }
      .sortBy(_._2)
      .map(_._1)
  }

  // Assign source ID ranges for each master
  val masterIdRanges = assignIdRanges(Seq.fill(nMasters)(10)) // 10 ids each 
  
  // Helper function to trim ID based on range size
  def trimId(id: UInt, rangeSize: Int): UInt = 
    if (rangeSize <= 1) 0.U else id(log2Ceil(rangeSize) - 1, 0)

  // =========================================================================
  // Address Decode Logic
  // =========================================================================
  def addressMatches(addr: UInt, addressSet: Seq[(BigInt, BigInt)]): Bool = {
    addressSet.map { case (base, mask) =>
      // For each address range, check if addr matches
      // mask indicates which bits are "don't care"
      // We want: (addr & ~mask) == base
      val baseBits = base.U(config.c.addrWidth.W)
      val maskBits = mask.U(config.c.addrWidth.W)
      (addr & ~maskBits) === baseBits
      //(addr & maskBits) === baseBits
    }.reduce(_ || _)
  }

  // Routing matrix: For each master-slave pair, determine if reachable
  val routingMatrix = VecInit(
    io.in.map { master =>
      VecInit(config.slaves.map { slave =>
        addressMatches(master.a.bits.address, slave.addressSet)
      })
    }
  )

  // =========================================================================
  // Intermediate Wires with Transformed IDs
  // =========================================================================
  
  val masterA = Wire(Vec(nMasters, Decoupled(new Tilelink_A()(config.c))))
  val masterD = Wire(Vec(nMasters, Flipped(Decoupled(new Tilelink_D()(config.c)))))
  
  // Master-side A channel: Add ID offset
  (io.in zip masterA zip masterIdRanges).foreach { case ((ioIn, mA), (idStart, idEnd)) =>
    mA.bits := ioIn.a.bits
    mA.bits.source := ioIn.a.bits.source + idStart.U
    mA.valid := ioIn.a.valid
    ioIn.a.ready := mA.ready
  }
  
  // Master-side D channel: Remove ID offset
  (io.in zip masterD zip masterIdRanges).foreach { case ((ioIn, mD), (idStart, idEnd)) =>
    ioIn.d.bits := mD.bits
    ioIn.d.bits.source := trimId(mD.bits.source - idStart.U, idEnd - idStart)
    ioIn.d.valid := mD.valid
    mD.ready := ioIn.d.ready
  }

  // =========================================================================
  // Fanout: Replicate master A channels to all reachable slaves
  // =========================================================================
  val masterToSlave = (masterA zip routingMatrix).map { case (mA, routes) =>
    VecInit(routes.zipWithIndex.map { case (route, slaveIdx) =>
      val req = Wire(Decoupled(new Tilelink_A()(config.c)))
      req.bits := mA.bits
      req.valid := mA.valid && (route || (nSlaves == 1).B)
      req
    })
  }
  
  // Master ready when any selected slave is ready
  (masterA zip routingMatrix zip masterToSlave).foreach { case ((mA, routes), reqsToSlaves) =>
    mA.ready := Mux1H(routes, reqsToSlaves.map(_.ready))
  }

  // =========================================================================
  // A Channel Arbitration (Master -> Slave)
  // =========================================================================
  val arbiterFn: Seq[DecoupledIO[Tilelink_A]] => DecoupledIO[Tilelink_A] = 
    if (config.arbiterPolicy == "roundRobin") RRArbiter.apply else Arbiter.apply

  io.out.zipWithIndex.foreach { case (slaveOut, slaveIdx) =>
    val requests = masterToSlave.map(_(slaveIdx))
    slaveOut.a <> arbiterFn(requests)
  }

  // =========================================================================
  // D Channel Routing (Slave -> Master)
  // =========================================================================
  
  // For each slave D response, check which master ID range it belongs to
  def sourceInRange(source: UInt, range: (Int, Int)): Bool =
    (source >= range._1.U) && (source < range._2.U)
  
  val slaveToMaster = io.out.map { slaveOut =>
    VecInit(masterIdRanges.map { idRange =>
      val resp = Wire(Decoupled(new Tilelink_D()(config.c)))
      resp.bits := slaveOut.d.bits
      resp.valid := slaveOut.d.valid && sourceInRange(slaveOut.d.bits.source, idRange)
      resp
    })
  }
  
  // Slave ready when the target master is ready
  (io.out zip slaveToMaster).foreach { case (slaveOut, respsToMasters) =>
    val targetMaster = VecInit(masterIdRanges.map { idRange =>
      sourceInRange(slaveOut.d.bits.source, idRange)
    })
    slaveOut.d.ready := Mux1H(targetMaster, respsToMasters.map(_.ready))
  }

  // =========================================================================
  // D Channel Arbitration (Slave -> Master)
  // =========================================================================
  val dArbiterFn: Seq[DecoupledIO[Tilelink_D]] => DecoupledIO[Tilelink_D] = 
    if (config.arbiterPolicy == "roundRobin") RRArbiter.apply else Arbiter.apply

  (masterD zip slaveToMaster.transpose).foreach { case (mD, responses) =>
    mD <> dArbiterFn(responses)
  }
}

// Helper: Round-robin arbiter
object RRArbiter {
  def apply[T <: Data](requests: Seq[DecoupledIO[T]]): DecoupledIO[T] = {
    val arb = Module(new RRArbiter(chiselTypeOf(requests.head.bits), requests.size))
    arb.io.in.zip(requests).foreach { case (in, req) => in <> req }
    arb.io.out
  }
}

// Helper: Priority arbiter (lowest index first)
object Arbiter {
  def apply[T <: Data](requests: Seq[DecoupledIO[T]]): DecoupledIO[T] = {
    val arb = Module(new Arbiter(chiselTypeOf(requests.head.bits), requests.size))
    arb.io.in.zip(requests).foreach { case (in, req) => in <> req }
    arb.io.out
  }
}
