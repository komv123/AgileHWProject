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
  pixelFrequency: Int,
)

object VGAConfig {
  val vga640x480at60Hz = VGAConfig(
    VGATiming(640, 16, 96, 48),
    VGATiming(480, 10, 2, 33),
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

class VGAController(config: VGAConfig, clockFrequency: Int) extends Module {
  val io = IO(new Bundle {
    val horizontalSyncPulse, verticalSyncPulse, horizontalBlank, verticalBlank, pixelClock = Output(Bool())
  })

  val (_, pixelClock) = Counter(true.B, clockFrequency / config.pixelFrequency)
  io.pixelClock := pixelClock

  val horizontalCounter = VGACounter(config.horizontal)

  horizontalCounter.io.counterEnable := pixelClock

  val verticalCounter = VGACounter(config.vertical)

  verticalCounter.io.counterEnable := horizontalCounter.io.wrap

  io.horizontalSyncPulse := horizontalCounter.io.syncPulse
  io.verticalSyncPulse := verticalCounter.io.syncPulse

  io.horizontalBlank := horizontalCounter.io.blank
  io.verticalBlank := verticalCounter.io.blank
}
