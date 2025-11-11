// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VsvsimTestbench.h"
#include "VsvsimTestbench__Syms.h"
#include "verilated_dpi.h"


void VsvsimTestbench::getBitWidthImpl_clock(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_clock\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_clock");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_clock_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_clock_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_clock(const svBitVecVal* value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_clock\n"); );
    // Init
    CData/*0:0*/ value_clock__Vcvt;
    value_clock__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_clock");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_clock_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_clock_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_clock__Vcvt = (1U & VL_SET_I_SVBV(value_clock));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_clock__Vcvt);
}

void VsvsimTestbench::getBitsImpl_clock(svBitVecVal* value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_clock\n"); );
    // Init
    CData/*0:0*/ value_clock__Vcvt;
    value_clock__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_clock");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_clock_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_clock_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_clock__Vcvt);
    for (size_t value_clock__Vidx = 0; value_clock__Vidx < 1; ++value_clock__Vidx) VL_SET_SVBV_I(1, value_clock + 1 * value_clock__Vidx, value_clock__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_reset(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_reset\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_reset");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_reset_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_reset_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_reset(const svBitVecVal* value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_reset\n"); );
    // Init
    CData/*0:0*/ value_reset__Vcvt;
    value_reset__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_reset");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_reset_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_reset_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_reset__Vcvt = (1U & VL_SET_I_SVBV(value_reset));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_reset__Vcvt);
}

void VsvsimTestbench::getBitsImpl_reset(svBitVecVal* value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_reset\n"); );
    // Init
    CData/*0:0*/ value_reset__Vcvt;
    value_reset__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_reset");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_reset_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_reset_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_reset__Vcvt);
    for (size_t value_reset__Vidx = 0; value_reset__Vidx < 1; ++value_reset__Vidx) VL_SET_SVBV_I(1, value_reset + 1 * value_reset__Vidx, value_reset__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_corrupt(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_corrupt\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_corrupt");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_corrupt_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_corrupt_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_corrupt(svBitVecVal* value_io_tilelink_d_bits_corrupt) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_corrupt\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_d_bits_corrupt__Vcvt;
    value_io_tilelink_d_bits_corrupt__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_corrupt");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_corrupt_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_corrupt_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_corrupt__Vcvt);
    for (size_t value_io_tilelink_d_bits_corrupt__Vidx = 0; value_io_tilelink_d_bits_corrupt__Vidx < 1; ++value_io_tilelink_d_bits_corrupt__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_d_bits_corrupt + 1 * value_io_tilelink_d_bits_corrupt__Vidx, value_io_tilelink_d_bits_corrupt__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_data(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_data\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_data");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_data_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_data(svBitVecVal* value_io_tilelink_d_bits_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_data\n"); );
    // Init
    IData/*23:0*/ value_io_tilelink_d_bits_data__Vcvt;
    value_io_tilelink_d_bits_data__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_data");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_data_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_data__Vcvt);
    for (size_t value_io_tilelink_d_bits_data__Vidx = 0; value_io_tilelink_d_bits_data__Vidx < 1; ++value_io_tilelink_d_bits_data__Vidx) VL_SET_SVBV_I(24, value_io_tilelink_d_bits_data + 1 * value_io_tilelink_d_bits_data__Vidx, value_io_tilelink_d_bits_data__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_denied(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_denied\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_denied");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_denied_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_denied_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_denied(svBitVecVal* value_io_tilelink_d_bits_denied) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_denied\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_d_bits_denied__Vcvt;
    value_io_tilelink_d_bits_denied__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_denied");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_denied_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_denied_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_denied__Vcvt);
    for (size_t value_io_tilelink_d_bits_denied__Vidx = 0; value_io_tilelink_d_bits_denied__Vidx < 1; ++value_io_tilelink_d_bits_denied__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_d_bits_denied + 1 * value_io_tilelink_d_bits_denied__Vidx, value_io_tilelink_d_bits_denied__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_sink(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_sink\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_sink");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_sink_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_sink_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_sink(svBitVecVal* value_io_tilelink_d_bits_sink) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_sink\n"); );
    // Init
    CData/*3:0*/ value_io_tilelink_d_bits_sink__Vcvt;
    value_io_tilelink_d_bits_sink__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_sink");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_sink_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_sink_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_sink__Vcvt);
    for (size_t value_io_tilelink_d_bits_sink__Vidx = 0; value_io_tilelink_d_bits_sink__Vidx < 1; ++value_io_tilelink_d_bits_sink__Vidx) VL_SET_SVBV_I(4, value_io_tilelink_d_bits_sink + 1 * value_io_tilelink_d_bits_sink__Vidx, value_io_tilelink_d_bits_sink__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_source(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_source\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_source");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_source_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_source_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_source(svBitVecVal* value_io_tilelink_d_bits_source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_source\n"); );
    // Init
    CData/*3:0*/ value_io_tilelink_d_bits_source__Vcvt;
    value_io_tilelink_d_bits_source__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_source");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_source_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_source_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_source__Vcvt);
    for (size_t value_io_tilelink_d_bits_source__Vidx = 0; value_io_tilelink_d_bits_source__Vidx < 1; ++value_io_tilelink_d_bits_source__Vidx) VL_SET_SVBV_I(4, value_io_tilelink_d_bits_source + 1 * value_io_tilelink_d_bits_source__Vidx, value_io_tilelink_d_bits_source__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_size(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_size\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_size");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_size_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_size_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_size(svBitVecVal* value_io_tilelink_d_bits_size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_size\n"); );
    // Init
    IData/*23:0*/ value_io_tilelink_d_bits_size__Vcvt;
    value_io_tilelink_d_bits_size__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_size");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_size_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_size_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_size__Vcvt);
    for (size_t value_io_tilelink_d_bits_size__Vidx = 0; value_io_tilelink_d_bits_size__Vidx < 1; ++value_io_tilelink_d_bits_size__Vidx) VL_SET_SVBV_I(24, value_io_tilelink_d_bits_size + 1 * value_io_tilelink_d_bits_size__Vidx, value_io_tilelink_d_bits_size__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_param(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_param\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_param");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_param_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_param_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_param(svBitVecVal* value_io_tilelink_d_bits_param) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_param\n"); );
    // Init
    CData/*1:0*/ value_io_tilelink_d_bits_param__Vcvt;
    value_io_tilelink_d_bits_param__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_param");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_param_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_param_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_param__Vcvt);
    for (size_t value_io_tilelink_d_bits_param__Vidx = 0; value_io_tilelink_d_bits_param__Vidx < 1; ++value_io_tilelink_d_bits_param__Vidx) VL_SET_SVBV_I(2, value_io_tilelink_d_bits_param + 1 * value_io_tilelink_d_bits_param__Vidx, value_io_tilelink_d_bits_param__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_bits_opcode(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_bits_opcode\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_bits_opcode");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_opcode_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_opcode_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_bits_opcode(svBitVecVal* value_io_tilelink_d_bits_opcode) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_bits_opcode\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_d_bits_opcode__Vcvt;
    value_io_tilelink_d_bits_opcode__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_bits_opcode");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_opcode_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_opcode_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_bits_opcode__Vcvt);
    for (size_t value_io_tilelink_d_bits_opcode__Vidx = 0; value_io_tilelink_d_bits_opcode__Vidx < 1; ++value_io_tilelink_d_bits_opcode__Vidx) VL_SET_SVBV_I(3, value_io_tilelink_d_bits_opcode + 1 * value_io_tilelink_d_bits_opcode__Vidx, value_io_tilelink_d_bits_opcode__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_valid(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_valid\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_valid_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_valid(svBitVecVal* value_io_tilelink_d_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_valid\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_d_valid__Vcvt;
    value_io_tilelink_d_valid__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_valid_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_valid__Vcvt);
    for (size_t value_io_tilelink_d_valid__Vidx = 0; value_io_tilelink_d_valid__Vidx < 1; ++value_io_tilelink_d_valid__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_d_valid + 1 * value_io_tilelink_d_valid__Vidx, value_io_tilelink_d_valid__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_d_ready(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_d_ready\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_d_ready");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_ready_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_ready_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_d_ready(const svBitVecVal* value_io_tilelink_d_ready) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_d_ready\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_d_ready__Vcvt;
    value_io_tilelink_d_ready__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_d_ready");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_d_ready_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_d_ready_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_d_ready__Vcvt = (1U & VL_SET_I_SVBV(value_io_tilelink_d_ready));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_ready__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_d_ready(svBitVecVal* value_io_tilelink_d_ready) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_d_ready\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_d_ready__Vcvt;
    value_io_tilelink_d_ready__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_d_ready");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_ready_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_ready_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_d_ready__Vcvt);
    for (size_t value_io_tilelink_d_ready__Vidx = 0; value_io_tilelink_d_ready__Vidx < 1; ++value_io_tilelink_d_ready__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_d_ready + 1 * value_io_tilelink_d_ready__Vidx, value_io_tilelink_d_ready__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_corrupt(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_corrupt\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_corrupt");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_corrupt_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_corrupt_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_corrupt(const svBitVecVal* value_io_tilelink_a_bits_corrupt) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_corrupt\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_a_bits_corrupt__Vcvt;
    value_io_tilelink_a_bits_corrupt__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_corrupt");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_corrupt_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_corrupt_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_corrupt__Vcvt = (1U & 
                                              VL_SET_I_SVBV(value_io_tilelink_a_bits_corrupt));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_corrupt__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_corrupt(svBitVecVal* value_io_tilelink_a_bits_corrupt) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_corrupt\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_a_bits_corrupt__Vcvt;
    value_io_tilelink_a_bits_corrupt__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_corrupt");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_corrupt_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_corrupt_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_corrupt__Vcvt);
    for (size_t value_io_tilelink_a_bits_corrupt__Vidx = 0; value_io_tilelink_a_bits_corrupt__Vidx < 1; ++value_io_tilelink_a_bits_corrupt__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_a_bits_corrupt + 1 * value_io_tilelink_a_bits_corrupt__Vidx, value_io_tilelink_a_bits_corrupt__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_data(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_data\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_data");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_data_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_data(const svBitVecVal* value_io_tilelink_a_bits_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_data\n"); );
    // Init
    IData/*23:0*/ value_io_tilelink_a_bits_data__Vcvt;
    value_io_tilelink_a_bits_data__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_data");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_data_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_data__Vcvt = (0xffffffU 
                                           & VL_SET_I_SVBV(value_io_tilelink_a_bits_data));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_data__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_data(svBitVecVal* value_io_tilelink_a_bits_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_data\n"); );
    // Init
    IData/*23:0*/ value_io_tilelink_a_bits_data__Vcvt;
    value_io_tilelink_a_bits_data__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_data");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_data_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_data__Vcvt);
    for (size_t value_io_tilelink_a_bits_data__Vidx = 0; value_io_tilelink_a_bits_data__Vidx < 1; ++value_io_tilelink_a_bits_data__Vidx) VL_SET_SVBV_I(24, value_io_tilelink_a_bits_data + 1 * value_io_tilelink_a_bits_data__Vidx, value_io_tilelink_a_bits_data__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_mask(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_mask\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_mask");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_mask_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_mask_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_mask(const svBitVecVal* value_io_tilelink_a_bits_mask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_mask\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_a_bits_mask__Vcvt;
    value_io_tilelink_a_bits_mask__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_mask");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_mask_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_mask_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_mask__Vcvt = (7U & VL_SET_I_SVBV(value_io_tilelink_a_bits_mask));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_mask__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_mask(svBitVecVal* value_io_tilelink_a_bits_mask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_mask\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_a_bits_mask__Vcvt;
    value_io_tilelink_a_bits_mask__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_mask");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_mask_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_mask_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_mask__Vcvt);
    for (size_t value_io_tilelink_a_bits_mask__Vidx = 0; value_io_tilelink_a_bits_mask__Vidx < 1; ++value_io_tilelink_a_bits_mask__Vidx) VL_SET_SVBV_I(3, value_io_tilelink_a_bits_mask + 1 * value_io_tilelink_a_bits_mask__Vidx, value_io_tilelink_a_bits_mask__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_address(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_address\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_address");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_address_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_address_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_address(const svBitVecVal* value_io_tilelink_a_bits_address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_address\n"); );
    // Init
    SData/*10:0*/ value_io_tilelink_a_bits_address__Vcvt;
    value_io_tilelink_a_bits_address__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_address");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_address_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_address_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_address__Vcvt = (0x7ffU 
                                              & VL_SET_I_SVBV(value_io_tilelink_a_bits_address));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_address__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_address(svBitVecVal* value_io_tilelink_a_bits_address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_address\n"); );
    // Init
    SData/*10:0*/ value_io_tilelink_a_bits_address__Vcvt;
    value_io_tilelink_a_bits_address__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_address");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_address_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_address_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_address__Vcvt);
    for (size_t value_io_tilelink_a_bits_address__Vidx = 0; value_io_tilelink_a_bits_address__Vidx < 1; ++value_io_tilelink_a_bits_address__Vidx) VL_SET_SVBV_I(11, value_io_tilelink_a_bits_address + 1 * value_io_tilelink_a_bits_address__Vidx, value_io_tilelink_a_bits_address__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_source(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_source\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_source");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_source_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_source_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_source(const svBitVecVal* value_io_tilelink_a_bits_source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_source\n"); );
    // Init
    CData/*3:0*/ value_io_tilelink_a_bits_source__Vcvt;
    value_io_tilelink_a_bits_source__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_source");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_source_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_source_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_source__Vcvt = (0xfU & 
                                             VL_SET_I_SVBV(value_io_tilelink_a_bits_source));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_source__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_source(svBitVecVal* value_io_tilelink_a_bits_source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_source\n"); );
    // Init
    CData/*3:0*/ value_io_tilelink_a_bits_source__Vcvt;
    value_io_tilelink_a_bits_source__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_source");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_source_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_source_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_source__Vcvt);
    for (size_t value_io_tilelink_a_bits_source__Vidx = 0; value_io_tilelink_a_bits_source__Vidx < 1; ++value_io_tilelink_a_bits_source__Vidx) VL_SET_SVBV_I(4, value_io_tilelink_a_bits_source + 1 * value_io_tilelink_a_bits_source__Vidx, value_io_tilelink_a_bits_source__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_size(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_size\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_size");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_size_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_size_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_size(const svBitVecVal* value_io_tilelink_a_bits_size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_size\n"); );
    // Init
    IData/*23:0*/ value_io_tilelink_a_bits_size__Vcvt;
    value_io_tilelink_a_bits_size__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_size");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_size_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_size_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_size__Vcvt = (0xffffffU 
                                           & VL_SET_I_SVBV(value_io_tilelink_a_bits_size));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_size__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_size(svBitVecVal* value_io_tilelink_a_bits_size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_size\n"); );
    // Init
    IData/*23:0*/ value_io_tilelink_a_bits_size__Vcvt;
    value_io_tilelink_a_bits_size__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_size");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_size_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_size_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_size__Vcvt);
    for (size_t value_io_tilelink_a_bits_size__Vidx = 0; value_io_tilelink_a_bits_size__Vidx < 1; ++value_io_tilelink_a_bits_size__Vidx) VL_SET_SVBV_I(24, value_io_tilelink_a_bits_size + 1 * value_io_tilelink_a_bits_size__Vidx, value_io_tilelink_a_bits_size__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_param(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_param\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_param");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_param_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_param_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_param(const svBitVecVal* value_io_tilelink_a_bits_param) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_param\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_a_bits_param__Vcvt;
    value_io_tilelink_a_bits_param__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_param");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_param_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_param_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_param__Vcvt = (7U & VL_SET_I_SVBV(value_io_tilelink_a_bits_param));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_param__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_param(svBitVecVal* value_io_tilelink_a_bits_param) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_param\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_a_bits_param__Vcvt;
    value_io_tilelink_a_bits_param__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_param");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_param_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_param_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_param__Vcvt);
    for (size_t value_io_tilelink_a_bits_param__Vidx = 0; value_io_tilelink_a_bits_param__Vidx < 1; ++value_io_tilelink_a_bits_param__Vidx) VL_SET_SVBV_I(3, value_io_tilelink_a_bits_param + 1 * value_io_tilelink_a_bits_param__Vidx, value_io_tilelink_a_bits_param__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_bits_opcode(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_bits_opcode\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_bits_opcode");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_opcode_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_opcode_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_bits_opcode(const svBitVecVal* value_io_tilelink_a_bits_opcode) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_bits_opcode\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_a_bits_opcode__Vcvt;
    value_io_tilelink_a_bits_opcode__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_bits_opcode");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_opcode_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_opcode_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_bits_opcode__Vcvt = (7U & VL_SET_I_SVBV(value_io_tilelink_a_bits_opcode));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_opcode__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_bits_opcode(svBitVecVal* value_io_tilelink_a_bits_opcode) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_bits_opcode\n"); );
    // Init
    CData/*2:0*/ value_io_tilelink_a_bits_opcode__Vcvt;
    value_io_tilelink_a_bits_opcode__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_bits_opcode");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_opcode_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_opcode_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_bits_opcode__Vcvt);
    for (size_t value_io_tilelink_a_bits_opcode__Vidx = 0; value_io_tilelink_a_bits_opcode__Vidx < 1; ++value_io_tilelink_a_bits_opcode__Vidx) VL_SET_SVBV_I(3, value_io_tilelink_a_bits_opcode + 1 * value_io_tilelink_a_bits_opcode__Vidx, value_io_tilelink_a_bits_opcode__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_valid(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_valid\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_valid_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_tilelink_a_valid(const svBitVecVal* value_io_tilelink_a_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_tilelink_a_valid\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_a_valid__Vcvt;
    value_io_tilelink_a_valid__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_tilelink_a_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_valid_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_tilelink_a_valid__Vcvt = (1U & VL_SET_I_SVBV(value_io_tilelink_a_valid));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_valid__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_valid(svBitVecVal* value_io_tilelink_a_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_valid\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_a_valid__Vcvt;
    value_io_tilelink_a_valid__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_valid_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_valid__Vcvt);
    for (size_t value_io_tilelink_a_valid__Vidx = 0; value_io_tilelink_a_valid__Vidx < 1; ++value_io_tilelink_a_valid__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_a_valid + 1 * value_io_tilelink_a_valid__Vidx, value_io_tilelink_a_valid__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_tilelink_a_ready(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_tilelink_a_ready\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_tilelink_a_ready");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_ready_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_ready_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_tilelink_a_ready(svBitVecVal* value_io_tilelink_a_ready) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_tilelink_a_ready\n"); );
    // Init
    CData/*0:0*/ value_io_tilelink_a_ready__Vcvt;
    value_io_tilelink_a_ready__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_tilelink_a_ready");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_ready_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_ready_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_tilelink_a_ready__Vcvt);
    for (size_t value_io_tilelink_a_ready__Vidx = 0; value_io_tilelink_a_ready__Vidx < 1; ++value_io_tilelink_a_ready__Vidx) VL_SET_SVBV_I(1, value_io_tilelink_a_ready + 1 * value_io_tilelink_a_ready__Vidx, value_io_tilelink_a_ready__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_request(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_request\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_request");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_request_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_request_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_request(const svBitVecVal* value_io_request) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_request\n"); );
    // Init
    CData/*0:0*/ value_io_request__Vcvt;
    value_io_request__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_request");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_request_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_request_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_request__Vcvt = (1U & VL_SET_I_SVBV(value_io_request));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_request__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_request(svBitVecVal* value_io_request) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_request\n"); );
    // Init
    CData/*0:0*/ value_io_request__Vcvt;
    value_io_request__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_request");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_request_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_request_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_request__Vcvt);
    for (size_t value_io_request__Vidx = 0; value_io_request__Vidx < 1; ++value_io_request__Vidx) VL_SET_SVBV_I(1, value_io_request + 1 * value_io_request__Vidx, value_io_request__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_verCntr(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_verCntr\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_verCntr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_verCntr_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_verCntr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_verCntr(const svBitVecVal* value_io_VGA_verCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_verCntr\n"); );
    // Init
    SData/*9:0*/ value_io_VGA_verCntr__Vcvt;
    value_io_VGA_verCntr__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_verCntr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_verCntr_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_verCntr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_verCntr__Vcvt = (0x3ffU & VL_SET_I_SVBV(value_io_VGA_verCntr));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_verCntr__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_verCntr(svBitVecVal* value_io_VGA_verCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_verCntr\n"); );
    // Init
    SData/*9:0*/ value_io_VGA_verCntr__Vcvt;
    value_io_VGA_verCntr__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_verCntr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_verCntr_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_verCntr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_verCntr__Vcvt);
    for (size_t value_io_VGA_verCntr__Vidx = 0; value_io_VGA_verCntr__Vidx < 1; ++value_io_VGA_verCntr__Vidx) VL_SET_SVBV_I(10, value_io_VGA_verCntr + 1 * value_io_VGA_verCntr__Vidx, value_io_VGA_verCntr__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_horCntr(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_horCntr\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_horCntr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_horCntr_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_horCntr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_horCntr(const svBitVecVal* value_io_VGA_horCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_horCntr\n"); );
    // Init
    SData/*9:0*/ value_io_VGA_horCntr__Vcvt;
    value_io_VGA_horCntr__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_horCntr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_horCntr_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_horCntr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_horCntr__Vcvt = (0x3ffU & VL_SET_I_SVBV(value_io_VGA_horCntr));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_horCntr__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_horCntr(svBitVecVal* value_io_VGA_horCntr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_horCntr\n"); );
    // Init
    SData/*9:0*/ value_io_VGA_horCntr__Vcvt;
    value_io_VGA_horCntr__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_horCntr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_horCntr_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_horCntr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_horCntr__Vcvt);
    for (size_t value_io_VGA_horCntr__Vidx = 0; value_io_VGA_horCntr__Vidx < 1; ++value_io_VGA_horCntr__Vidx) VL_SET_SVBV_I(10, value_io_VGA_horCntr + 1 * value_io_VGA_horCntr__Vidx, value_io_VGA_horCntr__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_B(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_B\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_B");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_B_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_B_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_B(const svBitVecVal* value_io_VGA_B) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_B\n"); );
    // Init
    CData/*3:0*/ value_io_VGA_B__Vcvt;
    value_io_VGA_B__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_B");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_B_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_B_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_B__Vcvt = (0xfU & VL_SET_I_SVBV(value_io_VGA_B));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_B__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_B(svBitVecVal* value_io_VGA_B) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_B\n"); );
    // Init
    CData/*3:0*/ value_io_VGA_B__Vcvt;
    value_io_VGA_B__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_B");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_B_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_B_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_B__Vcvt);
    for (size_t value_io_VGA_B__Vidx = 0; value_io_VGA_B__Vidx < 1; ++value_io_VGA_B__Vidx) VL_SET_SVBV_I(4, value_io_VGA_B + 1 * value_io_VGA_B__Vidx, value_io_VGA_B__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_G(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_G\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_G");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_G_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_G_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_G(const svBitVecVal* value_io_VGA_G) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_G\n"); );
    // Init
    CData/*3:0*/ value_io_VGA_G__Vcvt;
    value_io_VGA_G__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_G");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_G_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_G_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_G__Vcvt = (0xfU & VL_SET_I_SVBV(value_io_VGA_G));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_G__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_G(svBitVecVal* value_io_VGA_G) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_G\n"); );
    // Init
    CData/*3:0*/ value_io_VGA_G__Vcvt;
    value_io_VGA_G__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_G");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_G_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_G_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_G__Vcvt);
    for (size_t value_io_VGA_G__Vidx = 0; value_io_VGA_G__Vidx < 1; ++value_io_VGA_G__Vidx) VL_SET_SVBV_I(4, value_io_VGA_G + 1 * value_io_VGA_G__Vidx, value_io_VGA_G__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_R(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_R\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_R");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_R_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_R_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_R(const svBitVecVal* value_io_VGA_R) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_R\n"); );
    // Init
    CData/*3:0*/ value_io_VGA_R__Vcvt;
    value_io_VGA_R__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_R");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_R_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_R_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_R__Vcvt = (0xfU & VL_SET_I_SVBV(value_io_VGA_R));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_R__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_R(svBitVecVal* value_io_VGA_R) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_R\n"); );
    // Init
    CData/*3:0*/ value_io_VGA_R__Vcvt;
    value_io_VGA_R__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_R");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_R_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_R_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_R__Vcvt);
    for (size_t value_io_VGA_R__Vidx = 0; value_io_VGA_R__Vidx < 1; ++value_io_VGA_R__Vidx) VL_SET_SVBV_I(4, value_io_VGA_R + 1 * value_io_VGA_R__Vidx, value_io_VGA_R__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_vSync(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_vSync\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_vSync");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_vSync_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_vSync_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_vSync(const svBitVecVal* value_io_VGA_vSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_vSync\n"); );
    // Init
    CData/*0:0*/ value_io_VGA_vSync__Vcvt;
    value_io_VGA_vSync__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_vSync");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_vSync_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_vSync_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_vSync__Vcvt = (1U & VL_SET_I_SVBV(value_io_VGA_vSync));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_vSync__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_vSync(svBitVecVal* value_io_VGA_vSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_vSync\n"); );
    // Init
    CData/*0:0*/ value_io_VGA_vSync__Vcvt;
    value_io_VGA_vSync__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_vSync");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_vSync_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_vSync_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_vSync__Vcvt);
    for (size_t value_io_VGA_vSync__Vidx = 0; value_io_VGA_vSync__Vidx < 1; ++value_io_VGA_vSync__Vidx) VL_SET_SVBV_I(1, value_io_VGA_vSync + 1 * value_io_VGA_vSync__Vidx, value_io_VGA_vSync__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_hSync(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_hSync\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_hSync");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_hSync_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_hSync_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBitsImpl_io_VGA_hSync(const svBitVecVal* value_io_VGA_hSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBitsImpl_io_VGA_hSync\n"); );
    // Init
    CData/*0:0*/ value_io_VGA_hSync__Vcvt;
    value_io_VGA_hSync__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBitsImpl_io_VGA_hSync");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBitsImpl_io_VGA_hSync_t __Vcb = (VsvsimTestbench__Vcb_setBitsImpl_io_VGA_hSync_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_VGA_hSync__Vcvt = (1U & VL_SET_I_SVBV(value_io_VGA_hSync));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_hSync__Vcvt);
}

void VsvsimTestbench::getBitsImpl_io_VGA_hSync(svBitVecVal* value_io_VGA_hSync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_hSync\n"); );
    // Init
    CData/*0:0*/ value_io_VGA_hSync__Vcvt;
    value_io_VGA_hSync__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_hSync");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_hSync_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_hSync_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_hSync__Vcvt);
    for (size_t value_io_VGA_hSync__Vidx = 0; value_io_VGA_hSync__Vidx < 1; ++value_io_VGA_hSync__Vidx) VL_SET_SVBV_I(1, value_io_VGA_hSync + 1 * value_io_VGA_hSync__Vidx, value_io_VGA_hSync__Vcvt);
}

void VsvsimTestbench::getBitWidthImpl_io_VGA_RGB(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidthImpl_io_VGA_RGB\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidthImpl_io_VGA_RGB");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_RGB_t __Vcb = (VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_RGB_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBitsImpl_io_VGA_RGB(svBitVecVal* value_io_VGA_RGB) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitsImpl_io_VGA_RGB\n"); );
    // Init
    SData/*11:0*/ value_io_VGA_RGB__Vcvt;
    value_io_VGA_RGB__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitsImpl_io_VGA_RGB");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitsImpl_io_VGA_RGB_t __Vcb = (VsvsimTestbench__Vcb_getBitsImpl_io_VGA_RGB_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_VGA_RGB__Vcvt);
    for (size_t value_io_VGA_RGB__Vidx = 0; value_io_VGA_RGB__Vidx < 1; ++value_io_VGA_RGB__Vidx) VL_SET_SVBV_I(12, value_io_VGA_RGB + 1 * value_io_VGA_RGB__Vidx, value_io_VGA_RGB__Vcvt);
}

void VsvsimTestbench::simulation_initializeTrace(const char* traceFilePath) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::simulation_initializeTrace\n"); );
    // Init
    static thread_local std::string traceFilePath__Vcvt;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("simulation_initializeTrace");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_simulation_initializeTrace_t __Vcb = (VsvsimTestbench__Vcb_simulation_initializeTrace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    traceFilePath__Vcvt = VL_CVT_N_CSTR(traceFilePath);
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), traceFilePath__Vcvt);
}

void VsvsimTestbench::simulation_enableTrace(int* success) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::simulation_enableTrace\n"); );
    // Init
    IData/*31:0*/ success__Vcvt;
    success__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("simulation_enableTrace");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_simulation_enableTrace_t __Vcb = (VsvsimTestbench__Vcb_simulation_enableTrace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), success__Vcvt);
    for (size_t success__Vidx = 0; success__Vidx < 1; ++success__Vidx) *success = success__Vcvt;
}

void VsvsimTestbench::simulation_disableTrace(int* success) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::simulation_disableTrace\n"); );
    // Init
    IData/*31:0*/ success__Vcvt;
    success__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("simulation_disableTrace");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_simulation_disableTrace_t __Vcb = (VsvsimTestbench__Vcb_simulation_disableTrace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), success__Vcvt);
    for (size_t success__Vidx = 0; success__Vidx < 1; ++success__Vidx) *success = success__Vcvt;
}
