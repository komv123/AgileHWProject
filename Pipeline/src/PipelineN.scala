package Pipeline 

import chisel3._
import chisel3.util._

import Common._
import VideoBuffer._
import MMU._
import ComputeModule._
import UserInput._

//class VideoBuffer(implicit c: Configuration) extends Module{
class PipelineN(width: Int, height: Int, n: Int)(implicit val c: Configuration = defaultConfig) extends Module{
  // Alias for modules that expect 'config' as the implicit name
  val config: Configuration = c

  val pointerwidth = log2Ceil(c.bufferSize)

  val io = IO(new Bundle{
    val ReadData = Flipped(new Readport(UInt(12.W), pointerwidth))
    //val bufferPointer = Input(UInt(log2Ceil(c.bufferSize).W))
    val framePointer = Input(UInt(24.W))

    val userInput = Flipped(Valid(new UserInputPosition(32)))
  })

  // Create compute config inline
  val computeConfig = ComputeConfig(
    width = width,
    height = height,
    maxiter = 1000
  )

  val videoBuffer = Module(new VideoBuffer(config))
  val cu = Seq.tabulate(n)(i => Module(new CompColorWrapper(computeConfig, n, start_address = width * (height / n) * i)(c)))
  val idReg = RegInit(0.U(4.W))
  val xReg = RegNext(io.userInput.bits.xmid)
  val yReg = RegNext(io.userInput.bits.ymid)
  val zReg = RegNext(io.userInput.bits.zoom)

  when(io.userInput.valid && (io.userInput.bits.xmid =/= xReg || io.userInput.bits.ymid =/= yReg || io.userInput.bits.zoom =/= zReg)) {
    idReg := idReg + 1.U
  }


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

  cu.foreach { module =>
    module.io.xmid := io.userInput.bits.xmid
    module.io.ymid := io.userInput.bits.ymid
    module.io.zoom := io.userInput.bits.zoom
    module.io.id := idReg
  }
}
