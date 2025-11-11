// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root___ico_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_ico(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_ico\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VsvsimTestbench___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VsvsimTestbench___024root___ico_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___ico_sequent__TOP__0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1 
        = ((IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_valid) 
           & (0U == (IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_opcode)));
    if ((0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg))) {
        if (vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1) {
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 1U;
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
                = (0x7ffU & (IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_address));
        } else {
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 0U;
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
                = (0x7ffU & 0U);
        }
    } else if ((1U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg))) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 1U;
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
            = (0x7ffU & ((IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_address) 
                         + vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter));
    } else {
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 0U;
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
            = (0x7ffU & 0U);
    }
}

void VsvsimTestbench___024root___eval_triggers__ico(VsvsimTestbench___024root* vlSelf);

bool VsvsimTestbench___024root___eval_phase__ico(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__ico\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VsvsimTestbench___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VsvsimTestbench___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VsvsimTestbench___024root___act_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VsvsimTestbench___024root___act_sequent__TOP__0(vlSelf);
    }
}

void VsvsimTestbench___024root___nba_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___nba_sequent__TOP__1(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___nba_comb__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_nba(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_nba\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_sequent__TOP__0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter;
    __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter = 0;
    SData/*11:0*/ __VdlyVal__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0;
    __VdlyVal__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __VdlyDim0__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0;
    __VdlyDim0__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlySet__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0;
    __VdlySet__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 = 0;
    // Body
    __VdlySet__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 = 0U;
    __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter 
        = vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter;
    if (vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT____Vlvbound_h7ac5f637__0 
            = ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid)
                ? (0xfffU & vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_data)
                : 0U);
        if ((0x403U >= (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr))) {
            __VdlyVal__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 
                = vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT____Vlvbound_h7ac5f637__0;
            __VdlyDim0__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 
                = vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr;
            __VdlySet__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0 = 1U;
        }
    }
    vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_en_d0 = 1U;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_addr_d0 
        = ((IData)(vlSelfRef.svsimTestbench__DOT__io_request)
            ? (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN)
            : (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__Tail));
    if (vlSelfRef.svsimTestbench__DOT__reset) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT__sourceReg = 0U;
        vlSelfRef.svsimTestbench__DOT__dut__DOT__Tail = 0U;
        vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg = 0U;
        __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter = 0U;
    } else {
        if (((0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg)) 
             & (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1))) {
            vlSelfRef.svsimTestbench__DOT__dut__DOT__sourceReg 
                = vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_source;
        }
        if (vlSelfRef.svsimTestbench__DOT__io_request) {
            vlSelfRef.svsimTestbench__DOT__dut__DOT__Tail 
                = vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN;
        }
        if (vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_0) {
            if (vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1) {
                vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg 
                    = (0U != vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_size);
            }
            if (((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1) 
                 & (0U != vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_size))) {
                __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter = 1U;
            }
        } else {
            vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_5 
                = (vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter 
                   < vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_size);
            if (vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_2) {
                vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg 
                    = ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_5)
                        ? 1U : 2U);
            } else if (((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_3) 
                        & (IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_d_ready))) {
                vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg = 0U;
            }
            if (((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_2) 
                 & (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_5))) {
                __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter 
                    = (0xffffffU & ((IData)(1U) + vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter));
            }
        }
    }
    if (__VdlySet__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory[__VdlyDim0__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0] 
            = __VdlyVal__svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory__v0;
    }
    vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter 
        = __Vdly__svsimTestbench__DOT__dut__DOT__burstCounter;
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN = 
        ((0x403U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__Tail))
          ? 0U : (0x7ffU & ((IData)(1U) + (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__Tail))));
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_0 
        = (0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg));
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_2 
        = (1U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg));
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_3 
        = (2U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg));
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_4 
        = ((0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg)) 
           | (1U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg)));
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_sequent__TOP__1(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_sequent__TOP__1\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1 
        = ((IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_valid) 
           & (0U == (IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_opcode)));
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_comb__TOP__0(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_comb__TOP__0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg))) {
        if (vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN_1) {
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 1U;
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
                = (0x7ffU & (IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_address));
        } else {
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 0U;
            vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
                = (0x7ffU & 0U);
        }
    } else if ((1U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__stateReg))) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 1U;
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
            = (0x7ffU & ((IData)(vlSelfRef.svsimTestbench__DOT__io_tilelink_a_bits_address) 
                         + vlSelfRef.svsimTestbench__DOT__dut__DOT__burstCounter));
    } else {
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_valid = 0U;
        vlSelfRef.svsimTestbench__DOT__dut__DOT____Vcellinp__Mem__io_Write_bits_addr 
            = (0x7ffU & 0U);
    }
}

void VsvsimTestbench___024root___eval_triggers__act(VsvsimTestbench___024root* vlSelf);

bool VsvsimTestbench___024root___eval_phase__act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VsvsimTestbench___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VsvsimTestbench___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VsvsimTestbench___024root___eval_phase__nba(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__nba\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VsvsimTestbench___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__nba(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VsvsimTestbench___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VsvsimTestbench___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VsvsimTestbench___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VsvsimTestbench___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VsvsimTestbench___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VsvsimTestbench___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VsvsimTestbench___024root___eval_debug_assertions(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_debug_assertions\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
