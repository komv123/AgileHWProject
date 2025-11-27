package ComputeModule

import chisel3._
import chisel3.util._
import javax.swing.InputMap
import scala.annotation.switch

class ColorMatch(maxiter: Int) extends Module {
    val io = IO(new Bundle {
        //val k_in        = Input(UInt(32.W))
        val k_in        = Input(UInt(log2Ceil(maxiter).W))
        val valid_in    = Input(Bool())
        //val maxiter_in  = Input(UInt(16.W))
        val buffer_ready = Input(Bool())

        val rgb_out     = Output(UInt(12.W))
        val ready       = Output(Bool())
        val valid_out   = Output(Bool())
    })

    def rising(v: Bool) = v & !RegNext(v)

    def interpolate(c0: UInt, c1: UInt): UInt = {
        val range = Position(segment+1.U) - Position(segment)
        val offset = k - Position(segment)

        Mux(c1 >= c0,
            c0 + ((offset * (c1 - c0) * 256.U) / range) / 256.U,
            c0 - ((offset * (c0 - c1) * 256.U) / range) / 256.U
        )
    }

    /* Constants */
    val Red     = VecInit(0.U(4.W), 2.U(4.W), 14.U(4.W), 15.U(4.W), 0.U(4.W))
    val Green   = VecInit(0.U(4.W), 6.U(4.W), 15.U(4.W), 10.U(4.W), 0.U(4.W))
    val Blue    = VecInit(6.U(4.W), 12.U(4.W), 15.U(4.W), 0.U(4.W), 0.U(4.W))

    val Position = Reg(Vec(5, UInt(16.W)))

    Position(0) := 0.U
    Position(1) := (0.16 * maxiter).asInstanceOf[Int].U   //~0.16 * maxiter
    Position(2) := (0.42 * maxiter).asInstanceOf[Int].U  //~0.42 * maxiter
    Position(3) := (0.64 * maxiter).asInstanceOf[Int].U  //~0.64 * maxiter
    Position(4) := maxiter.U
    
    /* Register declarations */
    val segment  = RegInit(0.U(3.W))

    val new_k = RegInit(0.B)

    val k       = RegInit(0.U(32.W))
    val ready   = RegInit(0.B)

    val rgb         = RegInit(0.U(12.W))
    val valid_out   = RegInit(0.B)

    /* Datapath */
    when (rising(io.valid_in)){
        new_k := 1.B
        k := io.k_in
    }

    // *** FSM ***
    object State extends ChiselEnum {
        val IDLE, SETUP, FIND_K, FIT = Value
    }

    import State._
    val stateReg = RegInit(IDLE)

    switch(stateReg){
        is (IDLE){
            ready := 1.B
            valid_out := 0.B
            when (new_k){
                ready := 0.B
                new_k := 0.B
                //stateReg := SETUP
                stateReg := FIND_K 
            }
        }
        /*

        is (SETUP) {
            when (k >= maxiter){
                rgb := 0.U
                valid_out := 1.B
                new_k := 0.B
                stateReg := IDLE
            } .otherwise {

                // NOTE: Change maxiter to parameter, compute the following at compiletime
                // NOTE: With above changes, no SETUP state is needed 

                Position(0) := 0.U
                Position(1) := (maxiter * 41.U) >> 8.U   //~0.16 * maxiter
                Position(2) := (maxiter * 107.U) >> 8.U  //~0.42 * maxiter
                Position(3) := (maxiter * 164.U) >> 8.U  //~0.64 * maxiter
                Position(4) := maxiter

                segment := 0.U
                stateReg := FIND_K
            }
        }
        */

        is (FIND_K) {
            when(k >= Position(segment) && k <= Position(segment+1.U)){
                stateReg := FIT
            } .otherwise {
                segment := segment + 1.U
            }
        }

        is (FIT) {
            val red = interpolate(Red(segment), Red(segment+1.U))
            val green = interpolate(Green(segment), Green(segment+1.U))
            val blue = interpolate(Blue(segment), Blue(segment+1.U))

            //rgb := (red << 8) | (green << 4) | blue
            rgb := Cat(red(3,0), green(3,0), blue(3,0)) 
            when(io.buffer_ready){
                ready := 1.B
                stateReg := IDLE
                valid_out := 1.B
            }
        }

    }

    io.rgb_out := rgb
    io.ready := ready
    io.valid_out := valid_out
}
