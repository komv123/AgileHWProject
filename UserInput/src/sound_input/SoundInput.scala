package UserInput

import chisel3._

//output shared by all hardware microphones
class SoundInputSignalIO extends Bundle {
  val amplitude = Output(UInt(8.W))
  val waveform = Output(UInt(8.W))
  val valid = Output(Bool())
}

// Trait that should be implemented by all micropones
trait SoundInput {
  this: Module =>
  val signal: SoundInputSignalIO
}
