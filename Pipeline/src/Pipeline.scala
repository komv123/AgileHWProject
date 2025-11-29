package Pipeline 

import chisel3._
import chisel3.util._

import Common._
import VideoBuffer._
import MMU._
import ComputeModule._

//class VideoBuffer(implicit c: Configuration) extends Module{
class Pipeline(width: Int, height: Int)(implicit val c: Configuration = defaultConfig) extends Module{
  // Alias for modules that expect 'config' as the implicit name
  val config: Configuration = c

  val pointerwidth = log2Ceil(c.bufferSize)

  val io = IO(new Bundle{
    val ReadData = Flipped(new Readport(UInt(12.W), pointerwidth))
    //val bufferPointer = Input(UInt(log2Ceil(c.bufferSize).W))
    val framePointer = Input(UInt(24.W))

    // val xmid    = Input(SInt(64.W))
    // val ymid    = Input(SInt(64.W))
    // val zoom        = Input(SInt(64.W))
    // val maxiter     = Input(UInt(16.W))
    // val new_params  = Input(Bool())

    val select = Input(UInt(4.W))
    val enter = Input(Bool())

  })

  // Create compute config inline
  val computeConfig = ComputeConfig(
    width = width,
    height = height,
    maxiter = 1000
  )

  val videoBuffer = Module(new VideoBuffer(config))
  val mmu = Module(new MMU()(config))
  val cu = Module(new CompColorWrapper(computeConfig, n = 1, start_address = 0)(c))
  val params = Module(new Parameters())

  params.io.select := io.select
  params.io.enter := io.enter

  mmu.io.tilelink_in <> cu.io.tilelink_out
  videoBuffer.io.tilelink <> mmu.io.tilelink_out
  io.ReadData <> videoBuffer.io.ReadData

  mmu.io.bufferPointer := videoBuffer.io.bufferPointer 
  mmu.io.framePointer := io.framePointer

  cu.io.xmid := params.io.xmid
  cu.io.ymid := params.io.ymid
  cu.io.zoom := params.io.zoom
  //cu.io.maxiter := io.maxiter
  cu.io.id := params.io.id 

  //cu.io.start_address := 0.U
}
