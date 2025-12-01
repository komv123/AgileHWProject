package visualizer

import chisel3._
import chisel3.util.Counter

import circt.stage.ChiselStage

import vga._
import Pipeline._

case class VisualizerConfig(
    val vga: VGAConfig,
    val clockFrequency: Int
)

object VisualizerConfig {
  val default = VisualizerConfig(
    vga = VGAConfig.vga640x480at60Hz,
    clockFrequency = 100000000
  )
}

class Visualizer(config: VisualizerConfig) extends Module {
  val io = IO(new Bundle {
    val colors = Output(new RGB(config.vga.colorDepth))
    val horizontalSyncPulse, verticalSyncPulse = Output(Bool())
    val btnr = Input(Bool())
    val btnl = Input(Bool())
  })

  val vgaController = Module(
    new VGAController(config.vga, config.clockFrequency)
  )
  val pipeline = Module(
    new Pipeline(config.vga.horizontal.pixels, config.vga.vertical.pixels)
  )

  val (pixelCount, _) = Counter(
    vgaController.io.requestPixel,
    config.vga.horizontal.pixels * config.vga.vertical.pixels
  )

  pipeline.io.select := io.btnr
  pipeline.io.enter := io.btnr
  pipeline.io.framePointer := pixelCount
  pipeline.io.ReadData.request.valid := vgaController.io.requestPixel
  pipeline.io.ReadData.request.bits.addr := 0.U

  vgaController.io.colors.input := pipeline.io.ReadData.response.bits.readData
    .asTypeOf(new RGB(config.vga.colorDepth))

  io.horizontalSyncPulse := vgaController.io.horizontal.syncPulse
  io.verticalSyncPulse := vgaController.io.vertical.syncPulse
  io.colors := vgaController.io.colors.output
}

object Main extends App {
  ChiselStage.emitSystemVerilogFile(
    new Visualizer(VisualizerConfig.default),
    args = Array("--target-dir", "rtl"),
    firtoolOpts =
      Array("--lowering-options=disallowLocalVariables,disallowPackedArrays")
  )
}
