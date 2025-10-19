import chisel3._

class ClockDivider(n: Int, freq: Int) extends Module{
    val io = IO(new Bundle{
        val tick = Output(Bool())
    })

    val max = ((freq / n) - 2).S
    val cntReg = RegInit(max)
    io.tick := false.B

    cntReg := cntReg - 1.S
    when(cntReg(max.getWidth - 1)){
        cntReg := max
        io.tick := true.B
    }
}
