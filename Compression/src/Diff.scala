package Compression 

import chisel3._
import chisel3.util._


object Hilbert {

  def generateRGBToHilbertLUT(): Seq[UInt] = {
    def rot(n: Int, x: Int, y: Int, z: Int, rx: Int, ry: Int, rz: Int): (Int, Int, Int) = {
      var nx = x
      var ny = y
      var nz = z
      
      if (rz == 0) {
        if (ry == 0) {
          val tmp = nx
          nx = ny
          ny = tmp
        }
        val tmp = nx
        nx = nz
        nz = tmp
      }
      
      if (rx == 0) {
        nx = n - 1 - nx
        nz = n - 1 - nz
      }
      if (ry == 0) {
        ny = n - 1 - ny
        nz = n - 1 - nz
      }
      
      (nx, ny, nz)
    }
    
    def pointToHilbertIndex(x: Int, y: Int, z: Int): UInt = {
      val n = 16
      var index = 0
      var nx = x
      var ny = y
      var nz = z
      
      for (i <- 3 to 0 by -1) {
        val rx = if ((nx & (n >> (i + 1))) != 0) 1 else 0
        val ry = if ((ny & (n >> (i + 1))) != 0) 1 else 0
        val rz = if ((nz & (n >> (i + 1))) != 0) 1 else 0
        
        index += ((7 * rx) ^ (3 * ry) ^ rz) << (3 * i)
        
        val rotated = rot(n >> (i + 1), nx, ny, nz, rx, ry, rz)
        nx = rotated._1
        ny = rotated._2
        nz = rotated._3
      }
      
      index.U
    }
    
    (0 until 4096).map { rgbValue =>
      val r = (rgbValue >> 8) & 0xF
      val g = (rgbValue >> 4) & 0xF
      val b = rgbValue & 0xF
      pointToHilbertIndex(r, g, b)
    }
  }
}

class Diff(implicit config: Configuration) extends Module{
  //implicit val c = config
  val io = IO(new Bundle{
    val in = Flipped(Valid(UInt(12.W)))
    val delta = Decoupled(SInt(12.W))
  })

  val LUT = VecInit(Hilbert.generateRGBToHilbertLUT())

  val lastReg = RegInit(0.U(12.W))
  val outReg = RegInit(0.U(12.W))
  //val validReg = RegInit(false.B(Bool))
  val validReg = RegInit(0.U(1.W))

  io.delta.valid := false.B
  io.delta.bits := 0.S 

  when(io.in.valid){
    outReg := LUT(io.in.bits)
    lastReg := outReg
    validReg := io.in.valid
  }

  when(validReg.asBool){
    io.delta.valid := true.B
    io.delta.bits := outReg - lastReg
  }
}



