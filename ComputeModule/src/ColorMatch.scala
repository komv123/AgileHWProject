package ComputeModule

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFile
import javax.swing.InputMap
import scala.annotation.switch
import java.io.PrintWriter

object ColorLUTGenerator {
  def generateLUT(lutSize: Int = 1024, maxk: Int = 1000, outputFile: String = "color_lut.hex"): Unit = {
    // Define color gradient stops (similar to original, but simplified)
    // Format: (position, red, green, blue) - each color component is 0-15 (4 bits)
    val colorStops: Seq[(Double, Int, Int, Int)] = Seq(
      (0.0,   0, 0, 6),   // Dark blue
      (0.16,  2, 6, 12),  // Cyan-ish
      (0.42,  14, 15, 15), // White-ish
      (0.64,  15, 10, 0),  // Orange-ish
      (1.0,   0, 0, 0)    // Black
    )

    def interpolateColor(k: Int, maxK: Int): Int = {
      val normalizedK = k.toDouble / maxK

      // Find the two color stops to interpolate between
      var idx = colorStops.length - 2  // Default to last segment
      var found = false
      for (i <- 0 until colorStops.length - 1 if !found) {
        val pos0 = colorStops(i)._1
        val pos1 = colorStops(i + 1)._1
        if (normalizedK >= pos0 && normalizedK <= pos1) {
          idx = i
          found = true
        }
      }

      val (pos0: Double, r0: Int, g0: Int, b0: Int) = colorStops(idx)
      val (pos1: Double, r1: Int, g1: Int, b1: Int) = colorStops(idx + 1)

      // Linear interpolation parameter (0.0 to 1.0)
      val t = if (pos1 == pos0) 0.0 else (normalizedK - pos0) / (pos1 - pos0)

      val red = (r0 + t * (r1 - r0)).round.toInt.max(0).min(15)
      val green = (g0 + t * (g1 - g0)).round.toInt.max(0).min(15)
      val blue = (b0 + t * (b1 - b0)).round.toInt.max(0).min(15)

      // Pack into 12-bit RGB (4 bits each)
      (red << 8) | (green << 4) | blue
    }

    val writer = new PrintWriter(outputFile)

    // Generate LUT entries
    for (i <- 0 until lutSize) {
      val rgb = interpolateColor(i, maxK)
      writer.println(f"$rgb%03x")
    }

    writer.close()
    println(s"Generated $outputFile with $lutSize entries")
  }
}

class ColorMatch(maxiter: Int) extends Module {
    val io = IO(new Bundle {
        val k_in        = Input(UInt(log2Ceil(maxiter).W))
        val valid_in    = Input(Bool())
        val buffer_ready = Input(Bool())

        val rgb_out     = Output(UInt(12.W))
        val ready       = Output(Bool())
        val valid_out   = Output(Bool())
    })

    // Color LUT: 1024 entries of 12-bit RGB values
    val colorLUT = Mem(1024, UInt(12.W))

    // Generate the LUT file at elaboration time with absolute path
    val lutFilePath = new java.io.File("color_lut.hex").getAbsolutePath
    ColorLUTGenerator.generateLUT(maxK = maxiter, outputFile = lutFilePath)

    // Initialize memory using SystemVerilog bind with absolute path
    loadMemoryFromFile(colorLUT, lutFilePath)

    def rising(v: Bool) = v & !RegNext(v)

    /* Register declarations */
    val new_k = RegInit(0.B)
    val k     = RegInit(0.U(32.W))
    val ready = RegInit(0.B)

    // LUT address register (for registered read)
    val lut_addr = RegInit(0.U(10.W))

    val rgb         = RegInit(0.U(12.W))
    val valid_out   = RegInit(0.B)

    /* Datapath */
    when (rising(io.valid_in)){
        new_k := 1.B
        k := io.k_in
    }

    // *** FSM ***
    object State extends ChiselEnum {
        val IDLE, LOOKUP, WAIT_MEM = Value
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
                stateReg := LOOKUP
            }
        }

        is (LOOKUP) {
            // Scale k to LUT address (0-1023)
            // Map maxiter range to 1024 LUT entries
            //val scaled_addr = (k * 1024.U) / maxiter.U
            //lut_addr := scaled_addr(9, 0)  // Take lower 10 bits for 1024 entries
            lut_addr := k  // Take lower 10 bits for 1024 entries
            stateReg := WAIT_MEM
        }

        is (WAIT_MEM) {
            // Read from LUT (combinational read since it's now a Mem, not SyncReadMem)
            rgb := colorLUT(lut_addr)
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
