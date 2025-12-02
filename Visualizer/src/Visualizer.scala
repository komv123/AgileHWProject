package visualizer

import chisel3._
import chisel3.util.Counter

import circt.stage.ChiselStage

import vga._
import Pipeline._
import UserInput._

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
    val btnu = Input(Bool())
    val btnd = Input(Bool())
    val btnl = Input(Bool())
    val btnr = Input(Bool())
    val btnc = Input(Bool())
  })

  val vgaController = Module(
    new VGAController(config.vga, config.clockFrequency)
  )
  val pipeline = Module(
    new Pipeline(config.vga.horizontal.pixels, config.vga.vertical.pixels, 15)
  )

  val (pixelCount, _) = Counter(
    vgaController.io.requestPixel,
    config.vga.horizontal.pixels * config.vga.vertical.pixels
  )

  val userInputs = Module(
    new NexysDirectionalKeys(
    )
  )

  userInputs.io.upButton := io.btnu
  userInputs.io.downButton := io.btnd
  userInputs.io.leftButton := io.btnl
  userInputs.io.rightButton := io.btnr
  userInputs.io.midButton := io.btnc
  pipeline.io.userInput <> userInputs.io.userInput

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
