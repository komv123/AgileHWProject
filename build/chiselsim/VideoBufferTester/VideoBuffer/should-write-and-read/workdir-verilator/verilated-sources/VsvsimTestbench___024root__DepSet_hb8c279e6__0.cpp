// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench__Syms.h"
#include "VsvsimTestbench___024root.h"

extern "C" void initTestBenchScope();

VL_INLINE_OPT void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    initTestBenchScope();
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__clock = value_clock;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP\n"); );
    // Init
    // Body
    value_clock = vlSymsp->TOP.svsimTestbench__DOT__clock;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__reset = value_reset;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP\n"); );
    // Init
    // Body
    value_reset = vlSymsp->TOP.svsimTestbench__DOT__reset;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_corrupt_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_corrupt_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_corrupt_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_bits_corrupt) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_corrupt_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_corrupt = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_data_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_data_TOP\n"); );
    // Init
    // Body
    value = 0x18U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_data_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_d_bits_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_data_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_data = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_denied_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_denied_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_denied_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_bits_denied) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_denied_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_denied = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_sink_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_sink_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_sink_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_tilelink_d_bits_sink) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_sink_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_sink = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_source_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_source_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_source_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_tilelink_d_bits_source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_source_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_source = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__sourceReg;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_size_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_size_TOP\n"); );
    // Init
    // Body
    value = 0x18U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_size_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_d_bits_size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_size_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_size = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_param_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_param_TOP\n"); );
    // Init
    // Body
    value = 2U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_param_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*1:0*/ &value_io_tilelink_d_bits_param) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_param_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_param = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_opcode_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_bits_opcode_TOP\n"); );
    // Init
    // Body
    value = 3U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_opcode_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_d_bits_opcode) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_bits_opcode_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_bits_opcode = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_valid_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_valid_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_valid = ((~ (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT___GEN_4)) 
                                 & (2U == (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__stateReg)));
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_ready_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_d_ready_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_d_ready_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_tilelink_d_ready) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_d_ready_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_d_ready 
        = value_io_tilelink_d_ready;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_ready_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_ready) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_d_ready_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_d_ready = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_d_ready;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_corrupt_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_corrupt_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_corrupt_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_tilelink_a_bits_corrupt) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_corrupt_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_corrupt 
        = value_io_tilelink_a_bits_corrupt;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_corrupt_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_a_bits_corrupt) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_corrupt_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_corrupt = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_corrupt;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_data_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_data_TOP\n"); );
    // Init
    // Body
    value = 0x18U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_data_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ value_io_tilelink_a_bits_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_data_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_data 
        = value_io_tilelink_a_bits_data;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_data_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_a_bits_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_data_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_data = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_data;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_mask_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_mask_TOP\n"); );
    // Init
    // Body
    value = 3U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_mask_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_tilelink_a_bits_mask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_mask_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_mask 
        = value_io_tilelink_a_bits_mask;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_mask_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_a_bits_mask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_mask_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_mask = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_mask;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_address_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_address_TOP\n"); );
    // Init
    // Body
    value = 0xbU;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_address_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*10:0*/ value_io_tilelink_a_bits_address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_address_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_address 
        = value_io_tilelink_a_bits_address;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_address_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*10:0*/ &value_io_tilelink_a_bits_address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_address_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_address = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_address;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_source_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_source_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_source_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_tilelink_a_bits_source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_source_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_source 
        = value_io_tilelink_a_bits_source;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_source_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_tilelink_a_bits_source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_source_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_source = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_source;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_size_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_size_TOP\n"); );
    // Init
    // Body
    value = 0x18U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_size_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ value_io_tilelink_a_bits_size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_size_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_size 
        = value_io_tilelink_a_bits_size;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_size_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_a_bits_size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_size_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_size = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_size;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_param_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_param_TOP\n"); );
    // Init
    // Body
    value = 3U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_param_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_tilelink_a_bits_param) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_param_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_param 
        = value_io_tilelink_a_bits_param;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_param_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_a_bits_param) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_param_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_param = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_param;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_opcode_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_bits_opcode_TOP\n"); );
    // Init
    // Body
    value = 3U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_opcode_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_tilelink_a_bits_opcode) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_bits_opcode_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_opcode 
        = value_io_tilelink_a_bits_opcode;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_opcode_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_a_bits_opcode) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_bits_opcode_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_bits_opcode = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_bits_opcode;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_valid_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_tilelink_a_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_tilelink_a_valid_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_valid 
        = value_io_tilelink_a_valid;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_a_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_valid_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_valid = vlSymsp->TOP.svsimTestbench__DOT__io_tilelink_a_valid;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_ready_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_tilelink_a_ready_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_ready_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_a_ready) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_tilelink_a_ready_TOP\n"); );
    // Init
    // Body
    value_io_tilelink_a_ready = ((IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT___GEN_4) 
                                 | (2U != (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__stateReg)));
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_request_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_request_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_request_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_request) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_request_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_request = value_io_request;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_request_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_request) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_request_TOP\n"); );
    // Init
    // Body
    value_io_request = vlSymsp->TOP.svsimTestbench__DOT__io_request;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_verCntr_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_verCntr_TOP\n"); );
    // Init
    // Body
    value = 0xaU;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_verCntr_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ value_io_VGA_verCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_verCntr_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_verCntr 
        = value_io_VGA_verCntr;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_verCntr_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ &value_io_VGA_verCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_verCntr_TOP\n"); );
    // Init
    // Body
    value_io_VGA_verCntr = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_verCntr;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_horCntr_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_horCntr_TOP\n"); );
    // Init
    // Body
    value = 0xaU;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_horCntr_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ value_io_VGA_horCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_horCntr_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_horCntr 
        = value_io_VGA_horCntr;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_horCntr_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ &value_io_VGA_horCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_horCntr_TOP\n"); );
    // Init
    // Body
    value_io_VGA_horCntr = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_horCntr;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_B_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_B_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_B_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_VGA_B) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_B_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_B = value_io_VGA_B;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_B_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_VGA_B) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_B_TOP\n"); );
    // Init
    // Body
    value_io_VGA_B = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_B;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_G_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_G_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_G_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_VGA_G) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_G_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_G = value_io_VGA_G;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_G_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_VGA_G) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_G_TOP\n"); );
    // Init
    // Body
    value_io_VGA_G = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_G;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_R_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_R_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_R_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_VGA_R) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_R_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_R = value_io_VGA_R;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_R_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_VGA_R) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_R_TOP\n"); );
    // Init
    // Body
    value_io_VGA_R = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_R;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_vSync_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_vSync_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_vSync_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_VGA_vSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_vSync_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_vSync 
        = value_io_VGA_vSync;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_vSync_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_VGA_vSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_vSync_TOP\n"); );
    // Init
    // Body
    value_io_VGA_vSync = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_vSync;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_hSync_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_hSync_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_hSync_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_VGA_hSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_VGA_hSync_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_VGA_hSync 
        = value_io_VGA_hSync;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_hSync_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_VGA_hSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_hSync_TOP\n"); );
    // Init
    // Body
    value_io_VGA_hSync = vlSymsp->TOP.svsimTestbench__DOT__io_VGA_hSync;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_RGB_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_VGA_RGB_TOP\n"); );
    // Init
    // Body
    value = 0xcU;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_RGB_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ &value_io_VGA_RGB) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_VGA_RGB_TOP\n"); );
    // Init
    // Body
    value_io_VGA_RGB = ((IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_en_d0)
                         ? ((0x403U >= (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_addr_d0))
                             ? vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT__Memory
                            [vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__Mem__DOT__mem_ext__DOT___R0_addr_d0]
                             : 0U) : 0U);
}

extern "C" int simulation_body();

VL_INLINE_OPT void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    simulation_body();
}

extern "C" int simulation_final();

VL_INLINE_OPT void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    simulation_final();
}

extern "C" void run_simulation(int timesteps, int* done);

VL_INLINE_OPT void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__run_simulation_TOP(IData/*31:0*/ timesteps, IData/*31:0*/ &done) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__run_simulation_TOP\n"); );
    // Body
    int timesteps__Vcvt;
    for (size_t timesteps__Vidx = 0; timesteps__Vidx < 1; ++timesteps__Vidx) timesteps__Vcvt = timesteps;
    int done__Vcvt;
    run_simulation(timesteps__Vcvt, &done__Vcvt);
    done = done__Vcvt;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, std::string traceFilePath) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP\n"); );
    // Init
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &success) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP\n"); );
    // Init
    // Body
    success = 0U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &success) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP\n"); );
    // Init
    // Body
    success = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval_triggers__ico(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_triggers__ico\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
    vlSelfRef.__VicoTriggered.set(1U, (IData)(vlSelfRef.__Vdpi_export_trigger));
    vlSelfRef.__Vdpi_export_trigger = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval_triggers__act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_triggers__act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (IData)(vlSelfRef.__Vdpi_export_trigger));
    vlSelfRef.__Vdpi_export_trigger = 0U;
    vlSelfRef.__VactTriggered.set(1U, (vlSelfRef.svsimTestbench__DOT__simulationState 
                                       != vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSelfRef.svsimTestbench__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0 
        = vlSelfRef.svsimTestbench__DOT__simulationState;
    vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 
        = vlSelfRef.svsimTestbench__DOT__clock;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VsvsimTestbench___024root___act_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___act_sequent__TOP__0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U == vlSelfRef.svsimTestbench__DOT__simulationState)) {
        VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP(
                                                                                (&(vlSymsp->__Vscope_svsimTestbench)), 
                                                                                "/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv", 0x226U);
        vlSelfRef.svsimTestbench__DOT__simulationState = 2U;
    }
}
