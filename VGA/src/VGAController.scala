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

  val io = IO(new Bundle{
    val counterEnable = Input(Bool())
    val counter = Output(UInt((log2Ceil(backPorchTime - 1)).W))
    val display, frontPorch, syncPulse, backPorch, wrap = Output(Bool())
  })

  val (counter, wrap) = Counter(io.counterEnable, backPorchTime - 1)

  io.display := counter < displayTime.U
  io.frontPorch := counter >= displayTime.U && counter < frontPorchTime.U
  io.syncPulse := counter >= frontPorchTime.U && counter < syncPulseTime.U
  io.backPorch := counter >= syncPulseTime.U && counter < backPorchTime.U
  io.counter := counter
  io.wrap := wrap
}

class VGAController(config: VGAConfig, clockFrequency: Int) extends Module {
  val io = IO(new Bundle{
    val Rin, Gin, Bin = Input(UInt(4.W))
    val horizontalSyncPulse, verticalSyncPulse = Output(Bool())
    val R, G, B = Output(UInt(4.W))
    val horizontalCounter, verticalCounter = Output(UInt(10.W)) // TODO: Set width
  })

  val (_, pixelClock) = Counter(true.B, config.pixelFrequency / clockFrequency)

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

  io.R := io.Rin
  io.G := io.Gin
  io.B := io.Bin

  // Sync outputs
  io.horizontalSyncPulse := horizontalCounter.io.syncPulse
  io.verticalSyncPulse := verticalCounter.io.syncPulse

  // Counters output
  io.horizontalCounter := horizontalCounter.io.counter
  io.verticalCounter := verticalCounter.io.counter
}
