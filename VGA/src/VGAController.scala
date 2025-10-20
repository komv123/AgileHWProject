package vga

import chisel3._

class VGAController(freq: Int) extends Module {
  val io = IO(new Bundle{
    val Rin, Gin, Bin = Input(UInt(4.W))
    val hSync, vSync = Output(Bool())
    val R, G, B = Output(UInt(4.W))
    val horCntr, verCntr = Output(UInt(10.W))
  })

  val clkDiv = Module(new ClockDivider(25000000, freq)) // 25MHz clock
  val horCntr = Module(new HorizontalCounter) // Horizontal
  val verCntr = Module(new VerticalCounter) // Vertical

  // Clocks
  horCntr.io.pxlCLK := clkDiv.io.tick
  verCntr.io.enVCnt := horCntr.io.enVCnt

  // Display only in display time
  when(horCntr.io.dispTime && verCntr.io.dispTime){
    io.R := io.Rin
    io.G := io.Gin
    io.B := io.Bin
  }. otherwise{
    io.R := 0.U
    io.G := 0.U
    io.B := 0.U
  }

  // Sync outputs
  io.hSync := horCntr.io.horSync
  io.vSync := verCntr.io.verSync

  //Counters ouput
  io.horCntr := horCntr.io.horCnt
  io.verCntr := verCntr.io.verCnt
}
