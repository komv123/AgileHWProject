package ComputeModule

import chisel3._
import chisel3.util._
import javax.swing.InputMap
import scala.annotation.switch

class CompMod(config: ComputeConfig, n: Int, start_address: Int) extends Module {
    // Extract parameters from config
    val width = config.width
    val height = config.height
    val maxiter = config.maxiter
    val io = IO(new Bundle {
        val xmid    = Input(SInt(32.W))
        val ymid    = Input(SInt(32.W))
        val zoom        = Input(SInt(32.W))
        val new_params  = Input(Bool())
        val start_address = Input(UInt(24.W))

        val ready = Input(Bool())

        val k_out       = Output(UInt(32.W))
        val valid       = Output(Bool())
        val i_out       = Output(SInt(16.W))
        val j_out       = Output(SInt(16.W))
    })

    /* Functions */
    def fixed_mul(a: SInt, b: SInt): SInt = {
        val product = a * b
        product >> 16
    }
    def rising(v: Bool) = v & !RegNext(v)

    /* Constants */
    val escape = 262144.S  // 4.0 in Q16.16 fixed-point (was 4.0 in Q32.32)
    val v_smth = 131072.S  // 2.0 in Q16.16 fixed-point (was 2.0 in Q32.32)
    val three_eighths = 24576.S  // 3/8 = 0.375 in Q16.16 fixed-point

    val widthU = width.U
    val heightU = height.U
    val nU = n.U
    val widthS = width.S
    val heightS = height.S
    val nS = n.S

    val addr_max1 = width.U * (height.U * n.U)
    val addr_maxCU = addr_max1 / n.U
    
    /* Register declarations */
    val xmid    = RegInit(0.S(32.W)) //(-3335440880L.S(32.W))
    val ymid    = RegInit(0.S(32.W)) //(586868269L.S(32.W))
    val zoom    = RegInit(0.S(32.W)) //(99484L.S(32.W))
    //val maxiter = RegInit(1000.U(16.W)) //(1000.U(16.W))

    val xmin = RegInit(0.S(32.W))
    val ymin = RegInit(0.S(32.W))
    val xmax = RegInit(0.S(32.W))
    val ymax = RegInit(0.S(32.W))

    val dx = RegInit(0.S(32.W))
    val dy = RegInit(0.S(32.W))

    val u = RegInit(0.S(32.W))
    val v = RegInit(0.S(32.W))
    val u2 = RegInit(0.S(32.W))
    val v2 = RegInit(0.S(32.W))

    val i = RegInit(0.S(16.W))
    val j = RegInit(0.S(16.W))
    val k = RegInit(1.U(16.W))

    val x = RegInit(0.S(32.W))
    val y = RegInit(0.S(32.W))

    val k_out = RegInit(0.U(32.W))
    val valid = RegInit(0.B)

    // *** FSM ***
    object State extends ChiselEnum {
        val IDLE, SETUP, YLOOP, XLOOP, ITERATE = Value
    }

    import State._
    val stateReg = RegInit(IDLE)

    switch(stateReg){
        is(IDLE){
            when(io.new_params){stateReg := SETUP}
        }

        is (SETUP) {
            val xmin_next = io.xmid - (io.zoom >> 1)
            val xmax_next = io.xmid + (io.zoom >> 1)
            // Use fixed_mul to compute 3/8 * zoom without overflow
            val y_offset = fixed_mul(io.zoom, three_eighths)
            val ymin_next = io.ymid - y_offset
            val ymax_next = io.ymid + y_offset
            
            val position = io.start_address / addr_maxCU

            val y_window = (ymax_next - ymin_next) / n.S

            val ymin_cu_next = ymax_next - (y_window * (position + 1.U)) - 1.S
            val ymax_cu_next = ymax_next - (y_window * position)

            xmin := xmin_next
            xmax := xmax_next
            ymin := ymin_cu_next
            ymax := ymax_cu_next

            dx := (xmax_next - xmin_next) / width.S
            dy := (ymax_cu_next - ymin_cu_next) / height.S;

            j := 0.S

            stateReg := YLOOP
        }
        
        is (YLOOP) {
            y := ymax - j * dy
            i := 0.S
            j := j + 1.S

            when (j < height.S){stateReg := XLOOP} 
            .otherwise {
                j := 0.S
                stateReg := IDLE
            }
        }

        is (XLOOP) {
            x := xmin + i * dx

            /* Reset values */
            u := 0.S
            v := 0.S
            u2 := 0.S
            v2 := 0.S
            
            val k_next = 1.U
            val valid_next = 0.B

            val i_next = i + 1.S

            when (i < width.S) {
                when (io.ready){
                i := i_next
                k := k_next
                valid := valid_next

                stateReg := ITERATE}}
            .otherwise {stateReg := YLOOP}
        }

        is (ITERATE) {
            var v_next  = fixed_mul(fixed_mul(v_smth, u), v) + y
            var u_next  = u2 - v2 + x
            var u2_next = fixed_mul(u_next, u_next)
            var v2_next = fixed_mul(v_next, v_next)
            
            var k_next  = k + 1.U

            v  := v_next
            u  := u_next
            u2 := u2_next
            v2 := v2_next
            k  := k_next

            /*
            when (!(k < maxiter && ((u2_next + v2_next) < escape))) {
                when (k_next > maxiter){k_out := maxiter}
                .otherwise {k_out := k_next}
                valid := 1.B
                stateReg := XLOOP}
            */

            when (!(k < maxiter.U && ((u2_next + v2_next) < escape))) {
                when (k_next > maxiter.U){k_out := maxiter.U}
                .otherwise {k_out := k_next}
                valid := 1.B
                stateReg := XLOOP
            }

        }
    }

    io.k_out := k_out
    io.valid := valid
    io.i_out := i
    io.j_out := j
}
