
import chisel3._
import chisel3.util._


class Device() extends Module {
  val io = IO(new Bundle {
    
  })


}


/**
 * An object extending App to generate the Verilog code.
 */
object DeviceMain extends App {
  println("Hello World, I will now generate the Verilog file!")
  emitVerilog(new Device())
}