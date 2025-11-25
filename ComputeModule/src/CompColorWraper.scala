package ComputeModule

import chisel3._
import chisel3.util._
import Common._

class CompColorWrapper(width: Int, height: Int, n: Int)(implicit c: Configuration = defaultConfig) extends Module {
    val io = IO(new Bundle {
        val xmid    = Input(SInt(64.W))
        val ymid    = Input(SInt(64.W))
        val zoom        = Input(SInt(64.W))
        val maxiter     = Input(UInt(16.W))
        val new_params  = Input(Bool())
        val start_address = Input(UInt(24.W))

        val rgb_out     = Output(UInt(12.W))
        val valid_out   = Output(Bool())
        val k_out       = Output(UInt(32.W))
        val j_out       = Output(SInt(16.W))

        val tilelink_out = new Tilelink()(c)
    })

    val compmod = Module(new CompMod(width, (height / n), n))
    val color = Module(new ColorMatch())

    val k_valid = RegInit(0.B)
    val col_ready = RegInit(0.B)

    val buffer = Module(new BufferFIFO(1024, UInt(12.W)))
    
    /* IO connects */
    compmod.io.xmid             := io.xmid
    compmod.io.ymid             := io.ymid
    compmod.io.zoom             := io.zoom
    compmod.io.maxiter          := io.maxiter
    compmod.io.new_params       := io.new_params
    compmod.io.ready            := color.io.ready
    compmod.io.start_address    := io.start_address

    color.io.k_in       := compmod.io.k_out
    color.io.valid_in   := compmod.io.valid
    color.io.maxiter_in := io.maxiter
    color.io.buffer_ready := buffer.io.WriteData.ready

    io.rgb_out      := color.io.rgb_out
    io.valid_out    := color.io.valid_out
    io.k_out        := compmod.io.k_out
    io.j_out        := compmod.io.j_out

    io.tilelink_out.a.valid := false.B
    io.tilelink_out.a.bits := DontCare

    io.tilelink_out.d.ready := false.B 

    //buffer.io.WriteData.valid := false.B
    //buffer.io.WriteData.bits := DontCare 

    buffer.io.ReadData.request.valid := false.B
    buffer.io.ReadData.request.bits.addr := DontCare 

    buffer.io.WriteData.valid := color.io.valid_out
    buffer.io.WriteData.bits := color.io.rgb_out

    val addroffsetreg = RegInit(0.U(24.W))

    // *** FSM ***
    object State extends ChiselEnum {
        val IDLE, BURST, RECIEVE_ACK = Value
    }

    val stateReg = RegInit(State.IDLE)
    val cntReg = RegInit(0.U(12.W))
    val transcactionStarted = RegInit(0.U(1.W))

    when(transcactionStarted === 1.U){
        io.tilelink_out.a.bits.opcode := 0.U //FullPut
        io.tilelink_out.a.bits.param := 0.U //NA
        io.tilelink_out.a.bits.size := 1023.U //Full buffer write
        io.tilelink_out.a.bits.source := 0.U //ID 0
        io.tilelink_out.a.bits.address := addroffsetreg
        io.tilelink_out.a.bits.mask := 0.U // Not masking any bits
    }

    switch(stateReg){
        is(State.IDLE){
            // Buffer full
            when(!buffer.io.WriteData.ready) {
                io.tilelink_out.a.valid := true.B
                io.tilelink_out.a.bits.opcode := 0.U //FullPut
                io.tilelink_out.a.bits.param := 0.U //NA
                io.tilelink_out.a.bits.size := 1023.U //Full buffer write
                io.tilelink_out.a.bits.source := 0.U //ID 0
                io.tilelink_out.a.bits.address := addroffsetreg
                io.tilelink_out.a.bits.mask := 0.U // Not masking any bits
                io.tilelink_out.a.bits.data := buffer.io.ReadData.response.bits.readData // Reading directly from buffer
                io.tilelink_out.a.bits.corrupt := !buffer.io.ReadData.response.valid // Corrupt if buffer empty

                when(io.tilelink_out.a.ready){
                    stateReg := State.BURST
                    buffer.io.ReadData.request.valid := true.B
                    transcactionStarted := 1.U
                    cntReg := 1.U
                }
            }
        }
        is(State.BURST){
            when(io.tilelink_out.a.ready){
                io.tilelink_out.a.valid := true.B
                io.tilelink_out.a.bits.data := buffer.io.ReadData.response.bits.readData // Reading directly from buffer

                buffer.io.ReadData.request.valid := true.B
                cntReg := cntReg + 1.U

                when(cntReg === 1023.U) {
                    cntReg := 0.U
                    stateReg := State.RECIEVE_ACK
                    transcactionStarted := 0.U
                    addroffsetreg := addroffsetreg + 1024.U
                }
            }
        }
        is(State.RECIEVE_ACK) {
            io.tilelink_out.d.ready := true.B

            when(io.tilelink_out.d.valid){
                stateReg := State.IDLE
            }
        }
    }
}
