// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench__Syms.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial__TOP(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_initial__TOP\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM;
    svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM = 0;
    SData/*10:0*/ svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i;
    svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i = 0;
    // Body
    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(
                                                                                (&(vlSymsp->__Vscope_svsimTestbench)), 
                                                                                "/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv", 0x46U);
    vlSelfRef.svsimTestbench__DOT__simulationState = 1U;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM[0U] 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM[1U] 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__Tail = 
        (0x7ffU & vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
         [0U]);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg 
        = (0xfU & (vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                   [0U] >> 0xbU));
    vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter 
        = ((0xffff80U & (vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                         [0U] >> 8U)) | (0x7fU & vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                                         [1U]));
    vlSelfRef.svsimTestbench__DOT__dut__DOT__sourceReg 
        = (0xfU & (vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                   [1U] >> 7U));
    svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x404U > (IData)(svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i))) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM_MEM 
            = VL_RANDOM_I();
        vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT____Vlvbound_h57b49c42__0 
            = (0xfffU & vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM_MEM);
        if (VL_LIKELY(((0x403U >= (IData)(svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i))))) {
            vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory[svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i] 
                = vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT____Vlvbound_h57b49c42__0;
        }
        svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i 
            = (0x7ffU & ((IData)(1U) + (IData)(svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__unnamedblk1__DOT__i)));
    }
    svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_en_d0 
        = (1U & svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_addr_d0 
        = (0x7ffU & (svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___RANDOM 
                     >> 1U));
}

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_final__TOP(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_final__TOP\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(
                                                                                (&(vlSymsp->__Vscope_svsimTestbench)), 
                                                                                "/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv", 0x22cU);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__stl(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___eval_triggers__stl(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_triggers__stl\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
