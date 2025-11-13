package Compression  

import chisel3._
import chisel3.util._


class Compression(config: Configuration) extends Module{
//class Compression() extends Module{
  implicit val c = config

  val io = IO(new Bundle{
    val in = new SimplePort(UInt(12.W), 8)
    val out = Flipped(new SimplePort(UInt(12.W), 8))
  })

  val InputBuffer = Module(new BufferFIFO(4, UInt(12.W))) // Compensates for the depth of the Diff pipeline in the case of stall
  val Diff = Module(new Diff())
  //val GolombEnc = Module(new GolombEncode(config))
  val GolombEnc = Module(new GolombEncode())


  ////////////////////////////////////////////////////////////////////////////////


  Diff.io.in.valid := io.in.request.valid  
  Diff.io.in.bits := io.in.request.bits.data  

  io.in.request.ready := io.out.request.ready

  InputBuffer.io.WriteData.valid := Diff.io.delta.valid
  InputBuffer.io.WriteData.bits := Diff.io.delta.bits


  ////////////////////////////////////////////////////////////////////////////////

 

  val stateReg = RegInit(0.U(4.W))

  when(InputBuffer.io.ReadData.request.ready){
    InputBuffer.io.ReadData.request.valid := true.B
  }

  switch(stateReg){
    is(0.U){
      when(InputBuffer.io.ReadData.request.ready && GolombEnc.io.request.ready){
        InputBuffer.io.ReadData.request.valid := true.B
        GolombEnc.io.request.bits.diff := InputBuffer.io.ReadData.response.bits.readData.asSInt
        GolombEnc.io.request.valid := true.B
        stateReg := 1.U
      }.otherwise{
        GolombEnc.io.request.bits.diff := 0.S
        GolombEnc.io.request.valid := false.B
      }
    }
    is(1.U){
      GolombEnc.io.request.bits.diff := 0.S
      GolombEnc.io.request.valid := false.B

    }
  }

  // Connect GolombEnc output to compression module output
  io.out.request.valid := GolombEnc.io.out.request.valid
  io.out.request.bits.data := GolombEnc.io.out.request.bits.data
  GolombEnc.io.out.request.ready := io.out.request.ready




  









  





  










  






}
