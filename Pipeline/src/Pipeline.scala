package Pipeline 

import chisel3._
import chisel3.util._

import Common._
import VideoBuffer._
//import ComputeModule._
import MMU._

//class VideoBuffer(implicit c: Configuration) extends Module{
class Pipeline(width: Int, height: Int) extends Module{
  implicit val c: Configuration = config
  //val pointerwidth = log2Ceil(c.bufferSize)

  val io = IO(new Bundle{
    val ReadData = Flipped(new Readport(UInt(12.W), pointerwidth))
    val bufferPointer = Input(UInt(log2Ceil(config.bufferSize).W))
    val framePointer = Input(UInt(24.W))

    val xmid    = Input(SInt(64.W))
    val ymid    = Input(SInt(64.W))
    val zoom        = Input(SInt(64.W))
    val maxiter     = Input(UInt(16.W))
    val new_params  = Input(Bool())
  })

  val VideoBuffer = Module(new VideoBuffer())
  val MMU = Module(new MMU())
  val CU = Module(new CompColorWrapper(width,height,0))

  MMU.io.tilelink_in <> CU.io.tilelink_out
  VideoBuffer.io.tilelink <> MMU.io.tilelink_in
  io.ReadData <> Videobuffer.io.ReadData

  io.bufferPointer := MMU.io.bufferPointer
  io.framePointer := MMU.io.framePointer

  //CU.io.xmid := -3193384776L.S
  //CU.io.ymid := 545867056L.S  
  //CU.io.zoom := 21474836L.S
  //CU.io.maxiter := 1000.U
  //CU.io.new_params := 1.B
  
  CU.io.xmid := io.xmid 
  CU.io.ymid := io.ymid 
  CU.io.zoom := io.zoom 
  CU.io.maxiter := io.maxiter 
  CU.io.new_params := io.new_params 
}
