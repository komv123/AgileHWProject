import chisel3._
import chisel3.util._
import javax.swing.InputMap

class CompMod extends Module {
    val io = IO(new Bundle {
        val x_middle    = Input(SInt(64.W))
        val y_middle    = Input(SInt(64.W))
        val zoom        = Input(UInt(64.W))
        val maxiter     = Input(UInt(16.W))
        val new_params  = Input(Bool())

        val k_out       = Output(UInt(32.W))
        val valid       = Output(Bool())
    })

    /* Functions */
    def fixed_mul(a: SInt, b: SInt): SInt = {
        val product = a * b
        product >> 32
    }
    def rising(v: Bool) = v & !RegNext(v)

    /* Constants */
    val escape = 17179869184L.S
    val v_smth = 8589934592L.S

    /* Resolution */
    val xres = 640.S
    val yres = 480.S
    
    /* Register declarations */
    val xmid    = RegInit(-3335440880L.S(64.W))
    val ymid    = RegInit(586868269L.S(64.W))
    val zoom    = RegInit(99484L.S(64.W))
    val maxiter = RegInit(1000.U(16.W))
    
    val xmin = RegInit(0.S(64.W))
    val ymin = RegInit(0.S(64.W))
    val xmax = RegInit(0.S(64.W))
    val ymax = RegInit(0.S(64.W))

    val dx = RegInit(0.S(64.W))
    val dy = RegInit(0.S(64.W))

    val u = RegInit(0.S(64.W))
    val v = RegInit(0.S(64.W))
    val u2 = RegInit(0.S(64.W))
    val v2 = RegInit(0.S(64.W))

    val i = RegInit(0.S(16.W))
    val j = RegInit(0.S(16.W))
    val k = RegInit(1.U(16.W))

    val x = RegInit(0.S(64.W))
    val y = RegInit(0.S(64.W))

    val k_out = RegInit(0.U(32.W))
    val valid = RegInit(0.B)

    /* Startup calculations */
    when (rising(io.new_params)){
        xmin := xmid - (zoom >> 1)
        xmax := xmid + (zoom >> 1)
        ymin := ymid - (zoom * 3.S >> 2)
        ymax := ymid + (zoom * 3.S >> 2)

        dx := (xmax - xmin) / xres;
        dy := (ymax - ymin) / yres;
    }

    when (j < yres && valid === 1.B && i >= xres){
        y := ymax - j * dy
        i := 0.S
        j := j + 1.S
    }
    when (i < xres && valid === 1.B){
        x := xmin + i * dx

        /* Reset values */
        u := 0.S
        v := 0.S
        u2 := 0.S
        v2 := 0.S
        
        k := 0.U
        valid := 0.B

        i := i + 1.S
    }

    when (k < maxiter && ((u2 + v2) < escape)){
        v   := fixed_mul(fixed_mul(v_smth, u), v) + y
        u   := u2 - v2 + x
        u2  := fixed_mul(u, u)
        v2  := fixed_mul(v, v)

        k   := k + 1.U
    } .otherwise {
        k_out := k
        valid := 1.B
    }

    // when (i < xres){
    //     i := i + 1.S
    //     k := 0.S
    // }
    // when (j < yres){
    //     j := j + 1.S
    // }

    io.k_out := k_out
    io.valid := valid
}