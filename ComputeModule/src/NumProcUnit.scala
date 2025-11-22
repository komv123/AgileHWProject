import chisel3._
import chisel3.util._

class NumProcUnit extends Module {
    val io = IO(new Bundle {
        val a = Input(UInt())
    })
}