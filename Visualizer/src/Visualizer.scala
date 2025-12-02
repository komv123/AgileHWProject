package visualizer

import chisel3._
import chisel3.util.{Counter, RegEnable, log2Up}

import circt.stage.ChiselStage

import java.nio.file.Files
import java.io.File

import vga._
import Pipeline._

case class VisualizerConfig(
  val vga: VGAConfig,
  val clockFrequency: Int,
)

object VisualizerConfig {
  val default = VisualizerConfig(
    vga = VGAConfig.vga640x480at60Hz,
    clockFrequency = 100000000,
  )
}

class ReadIO(size: Long, width: Int) extends Bundle {
  val en = Input(Bool())
  val addr = Input(UInt(log2Up(size).W))
  val data = Output(UInt(width.W))
}

class ROM(contents: Seq[UInt]) extends Module {
  val io = IO(new ReadIO(contents.length.toLong, contents.head.getWidth))

  val rom = VecInit(contents)

  val addrReg = RegEnable(io.addr, 0.U, io.en)

  io.data := rom(addrReg)
}

class Visualizer(config: VisualizerConfig) extends Module {
  val io = IO(new Bundle {
    val colors = Output(new RGB(config.vga.colorDepth))
    val horizontalSyncPulse, verticalSyncPulse = Output(Bool())
  })

  val vgaController = Module(new VGAController(config.vga, config.clockFrequency))

  val (pixel, pixelWrap) = Counter(vgaController.io.requestPixel, config.vga.horizontal.pixels)
  val (line, _) = Counter(pixelWrap, config.vga.vertical.pixels)

  val BYTE_WIDTH = 8
  def fileToBigIntBytes(path: String): Seq[BigInt] = {
    Files
      .readAllBytes((new File(path)).toPath())
      .map(_ & 0xff)
      .map(BigInt(_))
      .toSeq
  }
  def fileToUInts(path: String, width: Int): Seq[UInt] = {
    if (width % BYTE_WIDTH != 0) throw new Error("width must be a multiple of " + BYTE_WIDTH)
    fileToBigIntBytes(path).iterator
      .grouped(width / BYTE_WIDTH)
      .withPadding(BigInt(0))
      .map(
        _.zipWithIndex
          .map { case (data, i) => (data << (i * BYTE_WIDTH)) }
          .reduce(_ + _)
          .asUInt(width.W)
      )
      .toSeq
  }

  val contents = fileToUInts("/home/rumle/repos/AgileHWProject/c_model/pic.ppm-test", 8).grouped(3).toSeq.transpose
  val red = Module(new ROM(contents(0)))
  val green = Module(new ROM(contents(1)))
  val blue = Module(new ROM(contents(2)))

  red.io.en := true.B
  red.io.addr := ((pixel >> 2) + ((line >> 2) * 160.U))
  green.io.en := true.B
  green.io.addr := ((pixel >> 2) + ((line >> 2) * 160.U))
  blue.io.en := true.B
  blue.io.addr := ((pixel >> 2) + ((line >> 2) * 160.U))
  vgaController.io.colors.input.red := red.io.data
  vgaController.io.colors.input.green := green.io.data
  vgaController.io.colors.input.blue := blue.io.data

  io.horizontalSyncPulse := vgaController.io.horizontal.syncPulse
  io.verticalSyncPulse := vgaController.io.vertical.syncPulse
  io.colors := vgaController.io.colors.output
}

object Main extends App {
  ChiselStage.emitSystemVerilogFile(
    new Visualizer(VisualizerConfig.default),
    args = Array("--target-dir", "rtl"),
    firtoolOpts = Array("--lowering-options=disallowLocalVariables,disallowPackedArrays")
  )
}
