package Pipeline 

import chisel3._
import chisel3.util._

import Common._
import VideoBuffer._
import MMU._
import ComputeModule._

//class VideoBuffer(implicit c: Configuration) extends Module{
class PipelineN(width: Int, height: Int, n: Int)(implicit val c: Configuration = defaultConfig) extends Module{
  // Alias for modules that expect 'config' as the implicit name
  val config: Configuration = c

  val pointerwidth = log2Ceil(c.bufferSize)

  val io = IO(new Bundle{
    val ReadData = Flipped(new Readport(UInt(12.W), pointerwidth))
    //val bufferPointer = Input(UInt(log2Ceil(c.bufferSize).W))
    val framePointer = Input(UInt(24.W))

    //val xmid    = Input(SInt(64.W))
    //val ymid    = Input(SInt(64.W))
    //val zoom        = Input(SInt(64.W))
    // val xmid    = Input(SInt(32.W))
    // val ymid    = Input(SInt(32.W))
    // val zoom        = Input(SInt(32.W))

    val select = Input(UInt(4.W))
    val enter = Input(Bool())

    //val maxiter     = Input(UInt(16.W))
    // val new_params  = Input(Bool())
  })

  // Create compute config inline
  val computeConfig = ComputeConfig(
    width = width,
    height = height,
    maxiter = 1000
  )

  val videoBuffer = Module(new VideoBuffer(config))
  val cu = Seq.tabulate(n)(i => Module(new CompColorWrapper(computeConfig, n, width * (height / n) * i)(c)))
  val params = Module(new Parameters())


  val xbarConfig = TLXbarConfig(
    nMasters = n,
    slaves = Seq(
      TLSlaveConfig(Seq((0x0000, 0xFFFF)))  // Full address space
    ),
    arbiterPolicy = "lock"
  )(config)

  val xbar = Module(new TLXbar(xbarConfig))

  xbar.io.in <> cu.map{module => module.io.tilelink_out} 

  val mmu = Module(new MMU()(config))
  mmu.io.tilelink_in <> xbar.io.out(0)

  mmu.io.bufferPointer := videoBuffer.io.bufferPointer 
  mmu.io.framePointer := io.framePointer

  videoBuffer.io.tilelink <> mmu.io.tilelink_out
  io.ReadData <> videoBuffer.io.ReadData

  params.io.select := io.select
  params.io.enter := io.enter

  cu.foreach { module =>
    module.io.xmid := params.io.xmid
    module.io.ymid := params.io.ymid
    module.io.zoom := params.io.zoom
    //module.io.maxiter := io.maxiter
    module.io.id := params.io.id
  }

  //for (i <- 0 until n) {
  //  //cu(i).io.start_address := (1024 * i).U
  //  cu(i).io.start_address := (width * (height / n) * i).U
  //}
}
