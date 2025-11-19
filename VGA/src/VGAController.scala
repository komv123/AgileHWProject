package vga

import chisel3._
import chisel3.util.{Counter, log2Ceil}

case class VGAConfig (
  horizontalPixels: Int,
  horizontalFrontPorch: Int,
  horizontalSyncPulse: Int,
  horizontalBackPorch: Int,
  verticalPixels: Int,
  verticalFrontPorch: Int,
  verticalSyncPulse: Int,
  verticalBackPorch: Int,
  pixelFrequency: Int,
)

object VGAConfig {
  val vga640x480at60Hz = VGAConfig(640, 16, 96, 48, 480, 10, 2, 33, 25000000)
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

class VGAController(config: VGAConfig, clockFrequency: Int) extends Module {
  val io = IO(new Bundle {
    val horizontalSyncPulse, verticalSyncPulse, horizontalBlank, verticalBlank, pixelClock = Output(Bool())
  })

  val (_, pixelClock) = Counter(true.B, clockFrequency / config.pixelFrequency)
  io.pixelClock := pixelClock

  val horizontalCounter = Module(new VGACounter(
    config.horizontalPixels,
    config.horizontalFrontPorch,
    config.horizontalSyncPulse,
    config.horizontalBackPorch
  ))

  horizontalCounter.io.counterEnable := pixelClock

  val verticalCounter = Module(new VGACounter(
    config.verticalPixels,
    config.verticalFrontPorch,
    config.verticalSyncPulse,
    config.verticalBackPorch
  ))

  verticalCounter.io.counterEnable := horizontalCounter.io.wrap

  io.horizontalSyncPulse := horizontalCounter.io.syncPulse
  io.verticalSyncPulse := verticalCounter.io.syncPulse

  io.horizontalBlank := horizontalCounter.io.blank
  io.verticalBlank := verticalCounter.io.blank
}
