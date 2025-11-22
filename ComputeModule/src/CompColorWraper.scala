import chisel3._
import chisel3.util._
import javax.swing.InputMap
import scala.annotation.switch

class CompColorWrapper(width: Int, height: Int, n: Int) extends Module {
    val io = IO(new Bundle {
        val xmid    = Input(SInt(64.W))
        val ymid    = Input(SInt(64.W))
        val zoom        = Input(SInt(64.W))
        val maxiter     = Input(UInt(16.W))
        val new_params  = Input(Bool())

        val rgb_out     = Output(UInt(12.W))
        val valid_out   = Output(Bool())
        val k_out       = Output(UInt(32.W))
        val j_out       = Output(SInt(16.W))
    })

    val compmod = Module(new CompMod(width, height))
    val color = Module(new ColorMatch())

    val k_valid = RegInit(0.B)
    val col_ready = RegInit(0.B)
    
    /* IO connects */
    compmod.io.xmid         := io.xmid
    compmod.io.ymid         := io.ymid
    compmod.io.zoom         := io.zoom
    compmod.io.maxiter      := io.maxiter
    compmod.io.new_params   := io.new_params
    compmod.io.ready        := color.io.ready

    color.io.k_in       := compmod.io.k_out
    color.io.valid_in   := compmod.io.valid
    color.io.maxiter_in := io.maxiter

    io.rgb_out      := color.io.rgb_out
    io.valid_out    := color.io.valid_out
    io.k_out        := compmod.io.k_out
    io.j_out        := compmod.io.j_out
}