package ComputeModule

import chisel3._
import chisel3.util._

class Parameters() extends Module {
    val io = IO(new Bundle {
        val select = Input(UInt(4.W))
        val enter = Input(Bool())

        val xmid    = Output(SInt(32.W))
        val ymid    = Output(SInt(32.W))
        val zoom    = Output(SInt(32.W))
        val id      = Output(UInt(4.W))
    })

    val xmid    = RegInit(0.S(32.W)) //(-3335440880L.S(32.W))
    val ymid    = RegInit(0.S(32.W)) //(586868269L.S(32.W))
    val zoom    = RegInit(0.S(32.W)) //(99484L.S(32.W))
    val id      = RegInit(0.U(4.W))

    def rising(v: Bool) = v & !RegNext(v)

    switch(io.select){
        is(0.U){
            when(rising(io.enter)){
                xmid := -87819.S
                ymid := 0.S
                zoom := 262144.S
                id := id + 1.U
            }
        }
        is(1.U){
            when(rising(io.enter)){
                xmid := -48729.S  // -3193384776 >> 16
                ymid := 8329.S    // 545867056 >> 16
                zoom := 328.S     // 21474836 >> 16
                id := id + 1.U
            }
        }
    }

    io.xmid := xmid
    io.ymid := ymid
    io.zoom := zoom
    io.id   := id

}