package ComputeModule

import chisel3._
import chisel3.util._
import javax.swing.InputMap
import scala.annotation.switch

// Object containing all pipeline-related definitions
object MandelbrotPipeline {
  
  // Bundle definitions for each pipeline stage
  class Stage1Bundle extends Bundle {
    val u = SInt(32.W)
    val v = SInt(32.W)
    val u2 = SInt(32.W)
    val v2 = SInt(32.W)
    val k = UInt()
    val x = SInt(32.W)
    val y = SInt(32.W)
  }

  class Stage2Bundle extends Bundle {
    val u_next = SInt(32.W)
    val v_next_partial = SInt(32.W)
    val u2 = SInt(32.W)
    val v2 = SInt(32.W)
    val k = UInt()
    val y = SInt(32.W)
  }

  class Stage3Bundle extends Bundle {
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
    val u2 = SInt(32.W)
    val v2 = SInt(32.W)
    val k = UInt()
  }

  class Stage4Bundle extends Bundle {
    val u2_next = SInt(32.W)
    val v2_next = SInt(32.W)
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
    val k_next = UInt()
  }
  
  class OutputBundle extends Bundle {
    val k = UInt()
    val done = Bool()
    val u2_next = SInt(32.W)
    val v2_next = SInt(32.W)
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
  }
  
  // Pipeline stage computation functions
  def stage1Compute(in: Stage1Bundle, fixed_mul: (SInt, SInt) => SInt): Stage2Bundle = {
    val out = Wire(new Stage2Bundle)

    // Compute next u and v values
    out.u_next := in.u2 - in.v2 + in.x
    //out.v_next := fixed_mul(fixed_mul(in.v, in.u), 2.S) + in.y
    out.v_next_partial := fixed_mul(in.v, in.u)

    // Pass through values needed for next stage
    out.u2 := in.u2
    out.v2 := in.v2
    out.k := in.k
    out.y := in.y

    out
  }


  def stage2Compute(in: Stage2Bundle, fixed_mul: (SInt, SInt) => SInt, v_smth: SInt): Stage3Bundle = {
    val out = Wire(new Stage3Bundle)

    // Compute next u and v values
    out.v_next := fixed_mul(in.v_next_partial, v_smth) + in.y
    //out.u_next := in.u2 - in.v2 + in.x
    out.u_next := in.u_next

    // Pass through values needed for next stage
    out.u2 := in.u2
    out.v2 := in.v2
    out.k := in.k

    out
  }
  
  def stage3Compute(in: Stage3Bundle, fixed_mul: (SInt, SInt) => SInt): Stage4Bundle = {
    val out = Wire(new Stage4Bundle)

    // Compute squared values
    out.u2_next := fixed_mul(in.u_next, in.u_next)
    out.v2_next := fixed_mul(in.v_next, in.v_next)
    out.u_next := in.u_next
    out.v_next := in.v_next
    out.k_next := in.k + 1.U

    out
  }
  
  def stage4Check(in: Stage4Bundle, maxiter: UInt, escape: SInt): OutputBundle = {
    val out = Wire(new OutputBundle)

    val magnitude = in.u2_next + in.v2_next
    val escaped = magnitude >= escape
    val max_reached = in.k_next >= maxiter

    out.done := escaped || max_reached
    out.k := Mux(max_reached, maxiter, in.k_next)
    out.u2_next := in.u2_next
    out.v2_next := in.v2_next
    out.u_next := in.u_next
    out.v_next := in.v_next

    out
  }
}

// The actual module using the pipeline object
class IterationPipeline(config: ComputeConfig, n: Int, start_address: Int) extends Module {
  import MandelbrotPipeline._

  val io = IO(new Bundle {
    val in = Flipped(Valid(new Stage1Bundle))
    val out = Valid(new OutputBundle)
  })

  // Fixed-point multiplication helper
  def fixed_mul(a: SInt, b: SInt): SInt = {
    val product = a * b
    product >> 16
  }

  // Constants for Mandelbrot computation
  val escape = 262144.S  // 4.0 in Q16.16 fixed-point
  val v_smth = 131072.S  // 2.0 in Q16.16 fixed-point

  // Pipeline registers with valid bits
  val stage1_valid = RegInit(false.B)
  val stage1_data = Reg(new Stage2Bundle)
  
  val stage2_valid = RegInit(false.B)
  val stage2_data = Reg(new Stage3Bundle)
  
  val stage3_valid = RegInit(false.B)
  val stage3_data = Reg(new Stage4Bundle)

  val stage4_valid = RegInit(false.B)
  val stage4_data = Reg(new OutputBundle)
  
  // Stage 1: Compute next u and v
  stage1_valid := io.in.valid
  when(io.in.valid) {
    stage1_data := stage1Compute(io.in.bits, fixed_mul)
  }
  
  // Stage 2: Complete v_next computation
  stage2_valid := stage1_valid
  when(stage1_valid) {
    stage2_data := stage2Compute(stage1_data, fixed_mul, v_smth)
  }
  
  // Stage 3: Compute squared values
  stage3_valid := stage2_valid
  when(stage2_valid) {
    stage3_data := stage3Compute(stage2_data, fixed_mul)
  }

  // Stage 4: Check convergence
  stage4_valid := stage3_valid
  when(stage3_valid) {
    stage4_data := stage4Check(stage3_data, config.maxiter.U, escape)
  }

  // Output
  io.out.valid := stage4_valid
  io.out.bits := stage4_data
}





class CompMod(config: ComputeConfig, n: Int, start_address: Int) extends Module {
    import MandelbrotPipeline._

    // Extract parameters from config
    val width = config.width
    val height = config.height / n  // Each CU handles height/n rows
    val maxiter = config.maxiter
    val io = IO(new Bundle {
        val xmid    = Input(SInt(32.W))
        val ymid    = Input(SInt(32.W))
        val zoom        = Input(SInt(32.W))
        val new_params  = Input(Bool())
        //val start_address = Input(UInt(24.W))

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

    val i = RegInit(0.S(16.W))
    val j = RegInit(0.S(16.W))

    val x = RegInit(0.S(32.W))
    val y = RegInit(0.S(32.W))

    val k_out = RegInit(0.U(32.W))
    val valid = RegInit(0.B)

    // Instantiate the iteration pipeline
    val pipeline = Module(new IterationPipeline(config, n, start_address))

    // Pipeline input bundle with feedback loop
    val pipelineInput = Wire(new Stage1Bundle)

    // Default values (will be overridden based on state)
    pipelineInput.u := 0.S
    pipelineInput.v := 0.S
    pipelineInput.u2 := 0.S
    pipelineInput.v2 := 0.S
    pipelineInput.k := 0.U
    pipelineInput.x := x
    pipelineInput.y := y

    // Default pipeline connections (will be overridden in FSM states)
    pipeline.io.in.valid := false.B
    pipeline.io.in.bits := pipelineInput


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
            
            val position = start_address.U / addr_maxCU

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

            val valid_next = 0.B
            val i_next = i + 1.S

            when (i < width.S) {
              when (io.ready){
                i := i_next
                valid := valid_next

                // Start pipeline with initial values (u=0, v=0, u2=0, v2=0, k=1)
                pipelineInput.u := 0.S
                pipelineInput.v := 0.S
                pipelineInput.u2 := 0.S
                pipelineInput.v2 := 0.S
                pipelineInput.k := 1.U
                pipeline.io.in.valid := true.B

                stateReg := ITERATE
              }
            } .otherwise {
              stateReg := YLOOP
            }
        }

        is (ITERATE) {
            // *** OLD NON-PIPELINED COMPUTATION (COMMENTED OUT) ***
            /*
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

            when (!(k < maxiter.U && ((u2_next + v2_next) < escape))) {
                when (k_next > maxiter.U){k_out := maxiter.U}
                .otherwise {k_out := k_next}
                valid := 1.B
                stateReg := XLOOP
            }
            */

            // *** NEW PIPELINED COMPUTATION ***
            // Wait for pipeline output to be valid
            when(pipeline.io.out.valid) {
                // Check if iteration is done
                when(pipeline.io.out.bits.done) {
                    // Iteration complete, output result
                    k_out := pipeline.io.out.bits.k
                    valid := 1.B
                    stateReg := XLOOP
                }.otherwise {
                    // Continue iterating - feed pipeline output back combinationally
                    pipelineInput.u := pipeline.io.out.bits.u_next
                    pipelineInput.v := pipeline.io.out.bits.v_next
                    pipelineInput.u2 := pipeline.io.out.bits.u2_next
                    pipelineInput.v2 := pipeline.io.out.bits.v2_next
                    pipelineInput.k := pipeline.io.out.bits.k

                    // Restart pipeline with new values
                    pipeline.io.in.valid := true.B
                }
            }
        }
    }

    io.k_out := k_out
    io.valid := valid
    io.i_out := i
    io.j_out := j
}
