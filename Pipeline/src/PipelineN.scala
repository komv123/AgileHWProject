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

    val xmid    = Input(SInt(64.W))
    val ymid    = Input(SInt(64.W))
    val zoom        = Input(SInt(64.W))
    val maxiter     = Input(UInt(16.W))
    val new_params  = Input(Bool())
  })

  val videoBuffer = Module(new VideoBuffer(config))
  val mmu = Module(new MMU()(config))
  val cu = VecInit(Seq.fill(n)(Module(new CompColorWrapper(width, height, n)(c))))

  mmu.io.tilelink_in <> cu.io.tilelink_out
  videoBuffer.io.tilelink <> mmu.io.tilelink_out
  io.ReadData <> videoBuffer.io.ReadData

  //mmu.io.bufferPointer := io.bufferPointer
  mmu.io.bufferPointer := videoBuffer.io.bufferPointer 
  mmu.io.framePointer := io.framePointer

  //CU.io.xmid := -3193384776L.S
  //CU.io.ymid := 545867056L.S  
  //CU.io.zoom := 21474836L.S
  //CU.io.maxiter := 1000.U
  //CU.io.new_params := 1.B
  
  // cu.io.xmid := io.xmid
  // cu.io.ymid := io.ymid
  // cu.io.zoom := io.zoom
  // cu.io.maxiter := io.maxiter
  // cu.io.new_params := io.new_params 

  cu.foreach { module =>
    module.io.xmid := io.xmid
    module.io.ymid := io.ymid
    module.io.zoom := io.zoom
    module.io.maxiter := io.maxiter
    module.io.new_params := io.new_params
  }

  for (i <- 0 until nw) {
    cu(i).io.start_address := (1024 * i).U
  }
}
