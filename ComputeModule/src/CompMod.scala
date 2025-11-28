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
    val u2_next = SInt(32.W)
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
    val v2_next = SInt(32.W)
    val k_next = UInt()
    val done = Bool()
  }

  class OutputBundle extends Bundle {
    val k = UInt()
    val done = Bool()
    val u2_next = SInt(32.W)
    val v2_next = SInt(32.W)
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
  }
  
  // Pipeline stage computation is now done directly in IterationPipeline module
  // using a time-multiplexed hardware multiplier
}

// Hardware multiplier module for time-multiplexing
class FixedMul extends Module {
  val io = IO(new Bundle {
    val a = Input(SInt(32.W))
    val b = Input(SInt(32.W))
    val result = Output(SInt(32.W))
  })

  val product = io.a * io.b
  io.result := product >> 16
}

// The actual module using the pipeline object
class IterationPipeline(config: ComputeConfig, n: Int, start_address: Int) extends Module {
  import MandelbrotPipeline._

  val io = IO(new Bundle {
    val in = Flipped(Valid(new Stage1Bundle))
    val out = Valid(new OutputBundle)
  })

  // Instantiate single hardware multiplier
  val hwMul = Module(new FixedMul())

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
  val stage3_data = Reg(new Stage3Bundle)

  // Default values for hardware multiplier (will be overridden by stages)
  hwMul.io.a := 0.S
  hwMul.io.b := 0.S

  // Multiplexer control signal (which stage is using the multiplier)
  val mul_stage = RegInit(0.U(2.W))

  // Stage 1: Compute v*u using hardware multiplier
  stage1_valid := io.in.valid
  when(io.in.valid) {
    // Mux inputs to hardware multiplier for stage 1
    hwMul.io.a := io.in.bits.v
    hwMul.io.b := io.in.bits.u
    mul_stage := 1.U

    val stage1_result = Wire(new Stage2Bundle)
    stage1_result.u_next := io.in.bits.u2 - io.in.bits.v2 + io.in.bits.x
    stage1_result.v_next_partial := hwMul.io.result
    stage1_result.u2 := io.in.bits.u2
    stage1_result.v2 := io.in.bits.v2
    stage1_result.k := io.in.bits.k
    stage1_result.y := io.in.bits.y

    stage1_data := stage1_result
  }

  // Stage 2: Compute u_next^2 using hardware multiplier
  stage2_valid := stage1_valid
  when(stage1_valid) {
    // Mux inputs to hardware multiplier for stage 2
    hwMul.io.a := stage1_data.u_next
    hwMul.io.b := stage1_data.u_next
    mul_stage := 2.U

    val stage2_result = Wire(new Stage3Bundle)
    stage2_result.v_next := (stage1_data.v_next_partial << 1) + stage1_data.y  // multiply by 2 using shift
    stage2_result.u_next := stage1_data.u_next
    stage2_result.u2_next := hwMul.io.result
    stage2_result.v2_next := 0.S  // Will be computed in stage 3
    stage2_result.k_next := stage1_data.k
    stage2_result.done := false.B  // Will be computed in stage 3

    stage2_data := stage2_result
  }

  // Stage 3: Compute v_next^2 using hardware multiplier and check convergence
  stage3_valid := stage2_valid
  when(stage2_valid) {
    // Mux inputs to hardware multiplier for stage 3
    hwMul.io.a := stage2_data.v_next
    hwMul.io.b := stage2_data.v_next
    mul_stage := 3.U

    val stage3_result = Wire(new Stage3Bundle)
    stage3_result.u2_next := stage2_data.u2_next
    stage3_result.v2_next := hwMul.io.result
    stage3_result.u_next := stage2_data.u_next
    stage3_result.v_next := stage2_data.v_next
    stage3_result.k_next := stage2_data.k_next + 1.U

    // Check convergence
    val magnitude = stage3_result.u2_next + hwMul.io.result
    val escaped = magnitude >= escape
    val max_reached = stage3_result.k_next >= config.maxiter.U
    stage3_result.done := escaped || max_reached

    stage3_data := stage3_result
  }

  // Output directly from stage3
  io.out.valid := stage3_valid
  io.out.bits.done := stage3_data.done
  io.out.bits.k := Mux(stage3_data.k_next >= config.maxiter.U, config.maxiter.U, stage3_data.k_next)
  io.out.bits.u2_next := stage3_data.u2_next
  io.out.bits.v2_next := stage3_data.v2_next
  io.out.bits.u_next := stage3_data.u_next
  io.out.bits.v_next := stage3_data.v_next
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
            // *** NEW PIPELINED COMPUTATION WITH STAGE3 FORWARDING ***
            // Wait for pipeline output to be valid
            when(pipeline.io.out.valid) {
                // Check if iteration is done
                when(pipeline.io.out.bits.done) {
                    // Iteration complete, output result
                    k_out := pipeline.io.out.bits.k
                    valid := 1.B
                    stateReg := XLOOP
                }.otherwise {
                    // Continue iterating - feed pipeline output back directly to stage1
                    // This creates a forwarding path from stage3 output to stage1 input
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
