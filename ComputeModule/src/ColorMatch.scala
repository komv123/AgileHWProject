package ComputeModule

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFile
import javax.swing.InputMap
import scala.annotation.switch
import java.io.PrintWriter


class ColorMatch(maxiter: Int) extends Module {
    val io = IO(new Bundle {
        val k_in        = Input(UInt(log2Ceil(maxiter).W))
        val valid_in    = Input(Bool())
        val buffer_ready = Input(Bool())

        val rgb_out     = Output(UInt(12.W))
        val ready       = Output(Bool())
        val valid_out   = Output(Bool())
    })


    def rising(v: Bool) = v & !RegNext(v)

    // def interpolate(c0: UInt, c1: UInt): UInt = {
    //     val range = Position(segment+1.U) - Position(segment)
    //     val offset = k - Position(segment)

    //     Mux(c1 >= c0,
    //         c0 + ((offset * (c1 - c0) * 256.U) / range) / 256.U,
    //         c0 - ((offset * (c0 - c1) * 256.U) / range) / 256.U
    //     )
    // }

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
    val new_k = RegInit(0.B)
    val k     = RegInit(0.U(32.W))
    val ready = RegInit(0.B)
    val segment = RegInit(0.U(3.W))

    val red = RegInit(0.U(4.W))
    val green = RegInit(0.U(4.W))
    val blue = RegInit(0.U(4.W))

    val rgb         = RegInit(0.U(12.W))
    val valid_out   = RegInit(0.B)

    /* Datapath */
    when (rising(io.valid_in)){
        new_k := 1.B
        k := io.k_in
    }

    /* Red fit */
    switch(segment){
        is(0.U){
            when(k <= 53.U){red := 0.U}
            .elsewhen(k > 53.U && k <= 106.U){red := 1.U}
            .otherwise{red := 2.U}
        }
        is(1.U){
            when(k <= 181.U){red := 2.U}
            .elsewhen(k > 181.U && k <= 202.U){red := 3.U}
            .elsewhen(k > 202.U && k <= 223.U){red := 4.U}
            .elsewhen(k > 223.U && k <= 244.U){red := 5.U}
            .elsewhen(k > 244.U && k <= 265.U){red := 6.U}
            .elsewhen(k > 265.U && k <= 286.U){red := 7.U}
            .elsewhen(k > 286.U && k <= 307.U){red := 8.U}
            .elsewhen(k > 307.U && k <= 328.U){red := 9.U}
            .elsewhen(k > 328.U && k <= 349.U){red := 10.U}
            .elsewhen(k > 349.U && k <= 370.U){red := 11.U}
            .elsewhen(k > 370.U && k <= 391.U){red := 12.U}
            .elsewhen(k > 391.U && k <= 412.U){red := 13.U}
            .otherwise{red := 14.U}
        }
        is(2.U){
            when(k <= 530.U){red := 14.U}
            .otherwise{red := 15.U}
        }
        is(3.U){
            when(k <= 664.U){red := 15.U}
            .elsewhen(k > 664.U && k <= 688.U){red := 14.U}
            .elsewhen(k > 688.U && k <= 712.U){red := 13.U}
            .elsewhen(k > 712.U && k <= 736.U){red := 12.U}
            .elsewhen(k > 736.U && k <= 760.U){red := 11.U}
            .elsewhen(k > 760.U && k <= 784.U){red := 10.U}
            .elsewhen(k > 784.U && k <= 808.U){red := 9.U}
            .elsewhen(k > 808.U && k <= 832.U){red := 8.U}
            .elsewhen(k > 832.U && k <= 856.U){red := 7.U}
            .elsewhen(k > 856.U && k <= 860.U){red := 6.U}
            .elsewhen(k > 860.U && k <= 884.U){red := 5.U}
            .elsewhen(k > 884.U && k <= 908.U){red := 4.U}
            .elsewhen(k > 908.U && k <= 932.U){red := 3.U}
            .elsewhen(k > 932.U && k <= 956.U){red := 2.U}
            .elsewhen(k > 956.U && k <= 980.U){red := 1.U}
            .otherwise{red := 0.U}
        }
    }

    /* Green fit */
    switch(segment){
        is(0.U){
            when(k <= 22.U){green := 0.U}
            .elsewhen(k > 22.U && k <= 44.U){green := 1.U}
            .elsewhen(k > 44.U && k <= 66.U){green := 2.U}
            .elsewhen(k > 66.U && k <= 88.U){green := 3.U}
            .elsewhen(k > 88.U && k <= 110.U){green := 4.U}
            .elsewhen(k > 110.U && k <= 132.U){green := 5.U}
            .otherwise{green := 6.U}
        }
        is(1.U){
            when(k <= 186.U){green := 6.U}
            .elsewhen(k > 186.U && k <= 212.U){green := 7.U}
            .elsewhen(k > 212.U && k <= 238.U){green := 8.U}
            .elsewhen(k > 238.U && k <= 254.U){green := 9.U}
            .elsewhen(k > 254.U && k <= 280.U){green := 10.U}
            .elsewhen(k > 280.U && k <= 306.U){green := 11.U}
            .elsewhen(k > 306.U && k <= 332.U){green := 12.U}
            .elsewhen(k > 332.U && k <= 358.U){green := 13.U}
            .elsewhen(k > 358.U && k <= 384.U){green := 14.U}
            .otherwise{green := 15.U}
        }
        is(2.U){
            when(k <= 456.U){green := 15.U}
            .elsewhen(k > 456.U && k <= 492.U){green := 14.U}
            .elsewhen(k > 492.U && k <= 528.U){green := 13.U}
            .elsewhen(k > 528.U && k <= 564.U){green := 12.U}
            .elsewhen(k > 564.U && k <= 600.U){green := 11.U}
            .otherwise{green := 10.U}
        }
        is(3.U){
            when(k <= 673.U){green := 10.U}
            .elsewhen(k > 673.U && k <= 706.U){green := 9.U}
            .elsewhen(k > 706.U && k <= 739.U){green := 8.U}
            .elsewhen(k > 739.U && k <= 772.U){green := 7.U}
            .elsewhen(k > 772.U && k <= 805.U){green := 6.U}
            .elsewhen(k > 805.U && k <= 838.U){green := 5.U}
            .elsewhen(k > 838.U && k <= 871.U){green := 4.U}
            .elsewhen(k > 871.U && k <= 904.U){green := 3.U}
            .elsewhen(k > 904.U && k <= 937.U){green := 2.U}
            .elsewhen(k > 937.U && k <= 970.U){green := 1.U}
            .otherwise{green := 0.U}
        }
    }

    /* Blue fit */
    switch(segment){
        is(0.U){
            when(k <= 23.U){blue := 6.U}
            .elsewhen(k > 23.U && k <= 46.U){blue := 7.U}
            .elsewhen(k > 46.U && k <= 69.U){blue := 8.U}
            .elsewhen(k > 69.U && k <= 92.U){blue := 9.U}
            .elsewhen(k > 92.U && k <= 115.U){blue := 10.U}
            .elsewhen(k > 115.U && k <= 138.U){blue := 11.U}
            .otherwise{blue := 12.U}
        }
        is(1.U){
            when(k <= 225.U){blue := 12.U}
            .elsewhen(k > 225.U && k <= 290.U){blue := 13.U}
            .elsewhen(k > 290.U && k <= 355.U){blue := 14.U}
            .otherwise{blue := 15.U}
        }
        is(2.U){
            when(k <= 434.U){blue := 15.U}
            .elsewhen(k > 434.U && k <= 448.U){blue := 14.U}
            .elsewhen(k > 448.U && k <= 462.U){blue := 13.U}
            .elsewhen(k > 462.U && k <= 476.U){blue := 12.U}
            .elsewhen(k > 476.U && k <= 490.U){blue := 11.U}
            .elsewhen(k > 490.U && k <= 504.U){blue := 10.U}
            .elsewhen(k > 504.U && k <= 518.U){blue := 9.U}
            .elsewhen(k > 518.U && k <= 532.U){blue := 8.U}
            .elsewhen(k > 532.U && k <= 546.U){blue := 7.U}
            .elsewhen(k > 546.U && k <= 560.U){blue := 6.U}
            .elsewhen(k > 560.U && k <= 574.U){blue := 5.U}
            .elsewhen(k > 574.U && k <= 588.U){blue := 4.U}
            .elsewhen(k > 588.U && k <= 602.U){blue := 3.U}
            .elsewhen(k > 602.U && k <= 616.U){blue := 2.U}
            .elsewhen(k > 616.U && k <= 630.U){blue := 1.U}
            .otherwise{blue := 0.U}
        }
        is(3.U){blue := 0.U}
    }



    // *** FSM ***
    object State extends ChiselEnum {
        val IDLE, FIND_K, FIT = Value
    }

    import State._
    val stateReg = RegInit(IDLE)

    switch(stateReg){
        is (IDLE){
            ready := 1.B
            valid_out := 0.B
            segment := 0.U
            when (new_k){
                ready := 0.B
                new_k := 0.B
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

            // val red = interpolate(Red(segment), Red(segment+1.U))
            // val green = interpolate(Green(segment), Green(segment+1.U))
            // val blue = interpolate(Blue(segment), Blue(segment+1.U))

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
