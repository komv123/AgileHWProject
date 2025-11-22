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
    val btnl, btnc, btnr = Input(Bool())
    val red, green, blue = Output(UInt(4.W))
    val horizontalSyncPulse, verticalSyncPulse = Output(Bool())
  })

  val vgaController = Module(new VGAController(config.vga, config.clockFrequency))

  io.horizontalSyncPulse := vgaController.io.horizontal.syncPulse
  io.verticalSyncPulse := vgaController.io.vertical.syncPulse

  io.red := Mux(io.btnl && !(vgaController.io.horizontal.blank || vgaController.io.vertical.blank), "b1111".U, "b0000".U)
  io.green := Mux(io.btnc && !(vgaController.io.horizontal.blank || vgaController.io.vertical.blank), "b1111".U, "b0000".U)
  io.blue := Mux(io.btnr && !(vgaController.io.horizontal.blank || vgaController.io.vertical.blank), "b1111".U, "b0000".U)
}

object Main extends App {
  ChiselStage.emitSystemVerilogFile(
    new Visualizer(VisualizerConfig.default),
    args = Array("--target-dir", "rtl"),
    firtoolOpts = Array("--lowering-options=disallowLocalVariables,disallowPackedArrays")
  )
}
