package visualizer

import chisel3._

import circt.stage.ChiselStage

import vga._

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

class Visualizer(config: VisualizerConfig) extends Module {
  val io = IO(new Bundle {
    val colors = Output(new RGB(config.vga.colorDepth))
    val horizontalSyncPulse, verticalSyncPulse = Output(Bool())
  })

  val vgaController = Module(new VGAController(config.vga, config.clockFrequency))

  // Temporary colors
  vgaController.io.colors.input.red := 15.U
  vgaController.io.colors.input.green := 15.U
  vgaController.io.colors.input.blue := 15.U

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
