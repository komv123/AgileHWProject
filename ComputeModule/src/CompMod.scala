package ComputeModule

import chisel3._
import chisel3.util._
import javax.swing.InputMap
import scala.annotation.switch

// Object containing all pipeline-related definitions
object MandelbrotPipeline {

  // Bundle definitions for each pipeline stage
  class Stage0Bundle extends Bundle {
    val u = SInt(32.W)
    val v = SInt(32.W)
    val u2 = SInt(32.W)
    val v2 = SInt(32.W)
    val k = UInt(10.W)
    val x = SInt(32.W)
    val y = SInt(32.W)
  }

  class Stage1Bundle extends Bundle {
    val u = SInt(32.W)
    val v = SInt(32.W)
    val u2 = SInt(32.W)
    val v2 = SInt(32.W)
    val k = UInt(10.W)
    val x = SInt(32.W)
    val y = SInt(32.W)
  }

  class Stage2Bundle extends Bundle {
    val u_next = SInt(32.W)
    val v_next_partial = SInt(32.W)
    val u2 = SInt(32.W)
    val v2 = SInt(32.W)
    val k = UInt(10.W)
    val y = SInt(32.W)
  }

  class Stage3Bundle extends Bundle {
    val u2_next = SInt(32.W)
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
    val v2_next = SInt(32.W)
    val k_next = UInt()
  }

  class Stage4Bundle extends Bundle {
    val u2_next = SInt(32.W)
    val v2_next = SInt(32.W)
    val u_next = SInt(32.W)
    val v_next = SInt(32.W)
    //val k_next = UInt()
    val k = UInt(10.W)
    val done = Bool()
  }

  class OutputBundle extends Bundle {
    val k = UInt(10.W)
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
  //io.result := product(63,32).asSInt
  io.result := product >> 16
}

// The actual module using the pipeline object
class IterationPipeline(config: ComputeConfig, n: Int, start_address: Int) extends Module {
  import MandelbrotPipeline._

  val io = IO(new Bundle {
    val in = Flipped(Valid(new Stage0Bundle))
    val out = Valid(new OutputBundle)
    val clear_pipeline = Input(Bool())  // Signal from FSM to clear pipeline
  })

  // Instantiate single hardware multiplier
  val hwMul = Module(new FixedMul())

  val hwMulRegA = RegInit(0.S(32.W))
  val hwMulRegB = RegInit(0.S(32.W))

  hwMul.io.a := hwMulRegA
  hwMul.io.b := hwMulRegB 

  // Fixed-point multiplication helper
  def fixed_mul(a: SInt, b: SInt): SInt = {
    val product = a * b
    product >> 16
  }

  // Constants for Mandelbrot computation
  val escape = 262144.S  // 4.0 in Q16.16 fixed-point
  val v_smth = 131072.S  // 2.0 in Q16.16 fixed-point

  // Pipeline registers with valid bits
  val stage0_valid = RegInit(false.B)
  val stage0_data = Reg(new Stage1Bundle)

  val stage1_valid = RegInit(false.B)
  val stage1_data = Reg(new Stage2Bundle)

  val stage2_valid = RegInit(false.B)
  val stage2_data = Reg(new Stage3Bundle)

  val stage3_valid = RegInit(false.B)
  val stage3_data = Reg(new Stage3Bundle)

  val stage4_valid = RegInit(false.B)
  val stage4_data = Reg(new Stage4Bundle)

  // Clear register for pipeline flushing (set when FSM exits ITERATE state)
  //val clear = RegInit(VecInit(Seq.fill(2)(false.B)))
  val clearReg = RegInit(false.B)

  clearReg := false.B //Default statement

  // Stage 0: Setup hardware multiplier input registers for v*u (initial input only)
  stage0_valid := io.in.valid && !clearReg
  when(io.in.valid && !clearReg) {
    // Set up inputs to hardware multiplier registers for initial v*u
    hwMulRegA := io.in.bits.v
    hwMulRegB := io.in.bits.u

    val stage0_result = Wire(new Stage1Bundle)
    stage0_result.u := io.in.bits.u
    stage0_result.v := io.in.bits.v
    stage0_result.u2 := io.in.bits.u2
    stage0_result.v2 := io.in.bits.v2
    stage0_result.k := io.in.bits.k
    stage0_result.x := io.in.bits.x
    stage0_result.y := io.in.bits.y

    stage0_data := stage0_result
  }

  // Create input mux for Stage1: select between Stage0 and Stage3 feedback
  val stage1_input = Wire(new Stage1Bundle)
  val use_feedback = stage3_valid

  stage1_input := Mux(use_feedback,
    // Feedback from stage3
    {
      val fb = Wire(new Stage1Bundle)
      fb.u := stage3_data.u_next
      fb.v := stage3_data.v_next
      fb.u2 := stage3_data.u2_next
      fb.v2 := stage3_data.v2_next
      fb.k := stage3_data.k_next
      fb.x := io.in.bits.x
      fb.y := io.in.bits.y
      fb
    },
    // From Stage0
    stage0_data
  )

  // Stage 1: Read v*u result, compute u_next, setup u_next^2 multiplication
  stage1_valid := (stage0_valid || stage3_valid) && !clearReg
  when((stage0_valid || stage3_valid) && !clearReg) {
    // Set up next multiplication (u_next^2)
    val u_next = stage1_input.u2 - stage1_input.v2 + stage1_input.x
    hwMulRegA := u_next
    hwMulRegB := u_next

    val stage1_result = Wire(new Stage2Bundle)
    stage1_result.u_next := u_next
    stage1_result.v_next_partial := hwMul.io.result  // v*u result from Stage0 or Stage3
    stage1_result.u2 := stage1_input.u2
    stage1_result.v2 := stage1_input.v2
    stage1_result.k := stage1_input.k
    stage1_result.y := stage1_input.y

    stage1_data := stage1_result
  }

  // Stage 2: Read u_next^2 result, compute v_next, setup v_next^2 multiplication
  stage2_valid := stage1_valid && !clearReg
  when(stage1_valid && !clearReg) {
    // Compute v_next and set up next multiplication (v_next^2)
    val v_next = (stage1_data.v_next_partial << 1) + stage1_data.y
    hwMulRegA := v_next
    hwMulRegB := v_next

    val stage2_result = Wire(new Stage3Bundle)
    stage2_result.v_next := v_next
    stage2_result.u_next := stage1_data.u_next
    stage2_result.u2_next := hwMul.io.result  // u_next^2 result from Stage1
    stage2_result.v2_next := 0.S  // Will be computed in stage 3
    stage2_result.k_next := stage1_data.k

    stage2_data := stage2_result
  }

  // Stage 3: Read v_next^2 result, complete iteration values, setup next v*u for feedback
  // Output feeds back to stage1 via the mux
  stage3_valid := stage2_valid && !clearReg
  when(stage2_valid && !clearReg) {
    // Set up next multiplication for feedback (v_next * u_next)
    hwMulRegA := stage2_data.v_next
    hwMulRegB := stage2_data.u_next

    val stage3_result = Wire(new Stage3Bundle)
    stage3_result.u2_next := stage2_data.u2_next
    stage3_result.v2_next := hwMul.io.result  // v_next^2 result from Stage2
    stage3_result.u_next := stage2_data.u_next
    stage3_result.v_next := stage2_data.v_next
    stage3_result.k_next := stage2_data.k_next + 1.U

    stage3_data := stage3_result
  }

  // Stage 4: Check convergence only
  // Pass through values from stage3 and add done signal
  stage4_valid := stage3_valid && !clearReg
  when(stage3_valid && !clearReg) {
    val stage4_result = Wire(new Stage4Bundle)
    stage4_result.u2_next := stage3_data.u2_next
    stage4_result.v2_next := stage3_data.v2_next
    stage4_result.u_next := stage3_data.u_next
    stage4_result.v_next := stage3_data.v_next
    //stage4_result.k_next := stage3_data.k_next
    stage4_result.k := Mux(stage3_data.k_next >= config.maxiter.U, config.maxiter.U, stage3_data.k_next)

    // Check convergence
    val magnitude = stage3_data.u2_next + stage3_data.v2_next
    val escaped = magnitude >= escape
    val max_reached = stage3_data.k_next >= config.maxiter.U

    val done = escaped || max_reached
    stage4_result.done := done

    clearReg := done // Reset pipeline

    stage4_data := stage4_result
  }

  when(clearReg){ //Reset done
    stage4_data.done := false.B
  }

  // Output from stage4
  io.out.valid := stage4_valid
  io.out.bits.done := stage4_data.done
  io.out.bits.k := stage4_data.k
  io.out.bits.u2_next := stage4_data.u2_next
  io.out.bits.v2_next := stage4_data.v2_next
  io.out.bits.u_next := stage4_data.u_next
  io.out.bits.v_next := stage4_data.v_next
}





class CompMod(config: ComputeConfig, n: Int, start_address: Int) extends Module {
    import MandelbrotPipeline._

    // Extract parameters from config
    val width = config.width
    //val height = config.height / n  // Each CU handles height/n rows
    val height = config.height  // Each CU handles height/n rows
    val maxiter = config.maxiter
    val io = IO(new Bundle {
        val xmid    = Input(SInt(32.W))
        val ymid    = Input(SInt(32.W))
        val zoom        = Input(SInt(32.W))
        val id  = Input(UInt(4.W))
        //val start_address = Input(UInt(24.W))

        val ready = Input(Bool())

        val k_out       = Output(UInt(32.W))
        val valid       = Output(Bool())
        //val i_out       = Output(SInt(16.W))
        //val j_out       = Output(SInt(16.W))
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

    val addr_maxCU = (width * height)
    
    /* Register declarations */
    val xmid    = RegInit(0.S(32.W)) //(-3335440880L.S(32.W))
    val ymid    = RegInit(0.S(32.W)) //(586868269L.S(32.W))
    val zoom    = RegInit(0.S(32.W)) //(99484L.S(32.W))
    val id      = RegInit(0.U(4.W))
    val new_params = RegInit(0.B)
    //val maxiter = RegInit(1000.U(16.W)) //(1000.U(16.W))

    val xmin = RegInit(0.S(32.W))
    val ymin = RegInit(0.S(32.W))
    val xmax = RegInit(0.S(32.W))
    val ymax = RegInit(0.S(32.W))

    val dx = RegInit(0.S(32.W))
    val dy = RegInit(0.S(32.W))

    //val i = RegInit(0.S(16.W))
    //val j = RegInit(0.S(16.W))

    val i = RegInit(0.U(16.W))
    val j = RegInit(0.U(16.W))

    val x = RegInit(0.S(32.W))
    val y = RegInit(0.S(32.W))

    val k_out = RegInit(0.U(32.W))
    val valid = RegInit(0.B)

    // Instantiate the iteration pipeline
    val pipeline = Module(new IterationPipeline(config, n, start_address))

    // Pipeline input bundle with feedback loop
    val pipelineInput = Wire(new Stage0Bundle)

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
    pipeline.io.clear_pipeline := false.B

    when(io.id =/= id){
      xmid := io.xmid
      ymid := io.ymid
      zoom := io.zoom
      id := io.id
      new_params := 1.B
    }

    // *** FSM ***
    object State extends ChiselEnum {
        val IDLE, SETUP, YLOOP, XLOOP, ITERATE = Value
    }

    import State._
    val stateReg = RegInit(IDLE)

    switch(stateReg){
        is(IDLE){
            when(new_params){stateReg := SETUP}
        }

        is (SETUP) {
            new_params := 0.B

            val xmin_next = xmid - (zoom >> 1)
            val xmax_next = xmid + (zoom >> 1)
            // Use fixed_mul to compute 3/8 * zoom without overflow
            //val y_offset = fixed_mul(zoom, three_eighths)
            val y_offset = (zoom >> 1)
            val ymin_next = ymid - y_offset
            val ymax_next = ymid + y_offset
            
            //val position = start_address.U / addr_maxCU
            val position = start_address / addr_maxCU  // Scala Int, computed at elaboration time

            // Compute coordinate ranges for this CU
            // Divide the total y-range among n CUs
            // To avoid gaps from rounding errors, we compute dy first, then derive ymin/ymax from it

            val total_y_range = ymax_next - ymin_next
            val total_height = (n * height).S
            val dy_next = total_y_range / total_height

            // Each CU gets height rows, starting from position*height rows from the top
            val row_offset = (position * height).S
            val ymax_cu_next = ymax_next - (dy_next * row_offset)
            val ymin_cu_next = ymax_cu_next - (dy_next * height.S)

            xmin := xmin_next
            xmax := xmax_next
            ymin := ymin_cu_next
            ymax := ymax_cu_next

            val dx_next = (xmax_next - xmin_next) / width.S

            dx := dx_next
            dy := dy_next
            //dy := (ymax - ymin) / height.S

            //j := 0.S
            j := 0.U

            stateReg := YLOOP
        }
        
        is (YLOOP) {
            y := ymax - (j.asSInt * dy)
            //i := 0.S
            i := 0.U
            //j := j + 1.S
            j := j + 1.U

            when (j < height.U){stateReg := XLOOP} 
            .otherwise {
                //j := 0.S
                j := 0.U
                stateReg := IDLE
            }
        }

        is (XLOOP) {
            x := xmin + (i.asSInt * dx)

            val valid_next = 0.B
            //val i_next = i + 1.S
            val i_next = i + 1.U

            //when (i < width.S) {
            when (i < width.U) {
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
            // *** PIPELINED COMPUTATION WITH AUTOMATIC STAGE3 FEEDBACK ***
            // The pipeline automatically feeds stage3 output back to stage1
            // We only need to wait for the done signal from stage4
            when(pipeline.io.out.valid && pipeline.io.out.bits.done) {
                // Iteration complete, output result and clear pipeline
                k_out := pipeline.io.out.bits.k
                valid := 1.B
                //pipeline.io.clear_pipeline := true.B  // Trigger pipeline clear
                stateReg := XLOOP
            }
            // No else needed - pipeline continues automatically via internal feedback
        }
    }

    io.k_out := k_out
    io.valid := valid
    //io.i_out := i
    //io.j_out := j
}
