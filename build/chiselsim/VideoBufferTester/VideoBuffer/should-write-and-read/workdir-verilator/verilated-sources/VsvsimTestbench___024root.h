// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VsvsimTestbench.h for the primary calling header

#ifndef VERILATED_VSVSIMTESTBENCH___024ROOT_H_
#define VERILATED_VSVSIMTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"


class VsvsimTestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ svsimTestbench__DOT__clock;
    CData/*0:0*/ svsimTestbench__DOT__reset;
    CData/*0:0*/ svsimTestbench__DOT__io_tilelink_d_ready;
    CData/*0:0*/ svsimTestbench__DOT__io_tilelink_a_bits_corrupt;
    CData/*2:0*/ svsimTestbench__DOT__io_tilelink_a_bits_mask;
    CData/*3:0*/ svsimTestbench__DOT__io_tilelink_a_bits_source;
    CData/*2:0*/ svsimTestbench__DOT__io_tilelink_a_bits_param;
    CData/*2:0*/ svsimTestbench__DOT__io_tilelink_a_bits_opcode;
    CData/*0:0*/ svsimTestbench__DOT__io_tilelink_a_valid;
    CData/*0:0*/ svsimTestbench__DOT__io_request;
    CData/*3:0*/ svsimTestbench__DOT__io_VGA_B;
    CData/*3:0*/ svsimTestbench__DOT__io_VGA_G;
    CData/*3:0*/ svsimTestbench__DOT__io_VGA_R;
    CData/*0:0*/ svsimTestbench__DOT__io_VGA_vSync;
    CData/*0:0*/ svsimTestbench__DOT__io_VGA_hSync;
    CData/*3:0*/ svsimTestbench__DOT__dut__DOT__stateReg;
    CData/*3:0*/ svsimTestbench__DOT__dut__DOT__sourceReg;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT___GEN_0;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT___GEN_1;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT___GEN_2;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT___GEN_3;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT___GEN_4;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_5;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_en_d0;
    CData/*0:0*/ __Vdpi_export_trigger;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*10:0*/ svsimTestbench__DOT__io_tilelink_a_bits_address;
    SData/*9:0*/ svsimTestbench__DOT__io_VGA_verCntr;
    SData/*9:0*/ svsimTestbench__DOT__io_VGA_horCntr;
    SData/*10:0*/ svsimTestbench__DOT__dut__DOT__Tail;
    SData/*10:0*/ svsimTestbench__DOT__dut__DOT___GEN;
    SData/*10:0*/ svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr;
    SData/*10:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_addr_d0;
    SData/*11:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT____Vlvbound_h7ac5f637__0;
    SData/*11:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT____Vlvbound_h57b49c42__0;
    IData/*23:0*/ svsimTestbench__DOT__io_tilelink_a_bits_data;
    IData/*23:0*/ svsimTestbench__DOT__io_tilelink_a_bits_size;
    IData/*31:0*/ svsimTestbench__DOT__simulationState;
    IData/*23:0*/ svsimTestbench__DOT__dut__DOT__burstCounter;
    IData/*31:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM_MEM;
    IData/*31:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 2> svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM;
    VlUnpacked<SData/*11:0*/, 1028> svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    VsvsimTestbench__Syms* const vlSymsp;

    // CONSTRUCTORS
    VsvsimTestbench___024root(VsvsimTestbench__Syms* symsp, const char* v__name);
    ~VsvsimTestbench___024root();
    VL_UNCOPYABLE(VsvsimTestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
