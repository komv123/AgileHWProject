package vga

import chisel3._
import chisel3.util.{Counter, log2Ceil}

case class VGATiming (
  pixels: Int,
  frontPorch: Int,
  syncPulse: Int,
  backPorch: Int,
)

case class VGAConfig (
  horizontal: VGATiming,
  vertical: VGATiming,
  colorDepth: Int,
  pixelFrequency: Int,
)

object VGAConfig {
  val vga640x480at60Hz = VGAConfig(
    VGATiming(640, 16, 96, 48),
    VGATiming(480, 10, 2, 33),
    4,
    25000000
  )
}

class VGACounter(pixels: Int, frontPorch: Int, syncPulse: Int, backPorch: Int) extends Module {
  val displayTime = pixels
  val frontPorchTime = displayTime + frontPorch
  val syncPulseTime = frontPorchTime + syncPulse
  val backPorchTime = syncPulseTime + backPorch

  val io = IO(new Bundle {
    val counterEnable = Input(Bool())
    val blank, syncPulse, wrap  = Output(Bool())
  })

  val (counter, wrap) = Counter(io.counterEnable, backPorchTime)

  io.blank := counter >= displayTime.U
  io.syncPulse := !(counter >= frontPorchTime.U && counter < syncPulseTime.U)
  io.wrap := wrap
}

object VGACounter {
  def apply(c: VGATiming) =  {
    Module(new VGACounter(c.pixels, c.frontPorch, c.syncPulse, c.backPorch))
  }
}

class VGASignals extends Bundle {
  val syncPulse, blank = Output(Bool())
}

class RGB(colorDepth: Int) extends Bundle {
  val red, green, blue = UInt(colorDepth.W)
}

class VGAController(config: VGAConfig, clockFrequency: Int) extends Module {
  val io = IO(new Bundle {
    val horizontal = new VGASignals()
    val vertical = new VGASignals()
    val colors = new Bundle {
      val input = Input(new RGB(config.colorDepth))
      val output = Output(new RGB(config.colorDepth))
    }
    val requestPixel = Output(Bool())
  })

  // VGA clock generator
  val (_, pixelClock) = Counter(true.B, clockFrequency / config.pixelFrequency)

  val horizontalCounter = VGACounter(config.horizontal)
  val verticalCounter = VGACounter(config.vertical)

  horizontalCounter.io.counterEnable := pixelClock
  verticalCounter.io.counterEnable := horizontalCounter.io.wrap

  io.horizontal.syncPulse := horizontalCounter.io.syncPulse
  io.vertical.syncPulse := verticalCounter.io.syncPulse

  io.horizontal.blank := horizontalCounter.io.blank
  io.vertical.blank := verticalCounter.io.blank

  // Only request pixels in display time
  io.requestPixel := pixelClock && !(horizontalCounter.io.blank || verticalCounter.io.blank)

  // Only output colors in display time
  io.colors.output.red := Mux(!(horizontalCounter.io.blank || verticalCounter.io.blank), io.colors.input.red, 0.U)
  io.colors.output.green := Mux(!(horizontalCounter.io.blank || verticalCounter.io.blank), io.colors.input.green, 0.U)
  io.colors.output.blue := Mux(!(horizontalCounter.io.blank || verticalCounter.io.blank), io.colors.input.blue, 0.U)
}
