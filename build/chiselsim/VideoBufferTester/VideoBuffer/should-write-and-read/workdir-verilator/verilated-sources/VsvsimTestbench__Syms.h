// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSVSIMTESTBENCH__SYMS_H_
#define VERILATED_VSVSIMTESTBENCH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VsvsimTestbench.h"

// INCLUDE MODULE CLASSES
#include "VsvsimTestbench___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VsvsimTestbench__Vcb_getBitWidthImpl_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_B_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_G_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_RGB_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_R_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_hSync_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_horCntr_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_vSync_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_VGA_verCntr_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_request_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_address_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_corrupt_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_data_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_mask_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_opcode_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_param_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_size_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_bits_source_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_ready_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_a_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_corrupt_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_data_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_denied_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_opcode_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_param_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_sink_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_size_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_bits_source_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_ready_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_tilelink_d_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitsImpl_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_clock);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_B_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_VGA_B);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_G_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_VGA_G);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_RGB_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ &value_io_VGA_RGB);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_R_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_VGA_R);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_hSync_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_VGA_hSync);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_horCntr_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ &value_io_VGA_horCntr);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_vSync_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_VGA_vSync);
using VsvsimTestbench__Vcb_getBitsImpl_io_VGA_verCntr_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ &value_io_VGA_verCntr);
using VsvsimTestbench__Vcb_getBitsImpl_io_request_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_request);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_address_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*10:0*/ &value_io_tilelink_a_bits_address);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_corrupt_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_a_bits_corrupt);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_data_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_a_bits_data);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_mask_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_a_bits_mask);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_opcode_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_a_bits_opcode);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_param_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_a_bits_param);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_size_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_a_bits_size);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_bits_source_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_tilelink_a_bits_source);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_ready_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_a_ready);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_a_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_a_valid);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_corrupt_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_bits_corrupt);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_data_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_d_bits_data);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_denied_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_bits_denied);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_opcode_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_tilelink_d_bits_opcode);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_param_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*1:0*/ &value_io_tilelink_d_bits_param);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_sink_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_tilelink_d_bits_sink);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_size_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ &value_io_tilelink_d_bits_size);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_bits_source_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_tilelink_d_bits_source);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_ready_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_ready);
using VsvsimTestbench__Vcb_getBitsImpl_io_tilelink_d_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_tilelink_d_valid);
using VsvsimTestbench__Vcb_getBitsImpl_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_reset);
using VsvsimTestbench__Vcb_setBitsImpl_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_clock);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_B_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_VGA_B);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_G_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_VGA_G);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_R_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_VGA_R);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_hSync_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_VGA_hSync);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_horCntr_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ value_io_VGA_horCntr);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_vSync_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_VGA_vSync);
using VsvsimTestbench__Vcb_setBitsImpl_io_VGA_verCntr_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*9:0*/ value_io_VGA_verCntr);
using VsvsimTestbench__Vcb_setBitsImpl_io_request_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_request);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_address_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*10:0*/ value_io_tilelink_a_bits_address);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_corrupt_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_tilelink_a_bits_corrupt);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_data_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ value_io_tilelink_a_bits_data);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_mask_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_tilelink_a_bits_mask);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_opcode_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_tilelink_a_bits_opcode);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_param_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_tilelink_a_bits_param);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_size_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*23:0*/ value_io_tilelink_a_bits_size);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_bits_source_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_tilelink_a_bits_source);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_a_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_tilelink_a_valid);
using VsvsimTestbench__Vcb_setBitsImpl_io_tilelink_d_ready_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_tilelink_d_ready);
using VsvsimTestbench__Vcb_setBitsImpl_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_reset);
using VsvsimTestbench__Vcb_simulation_disableTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &success);
using VsvsimTestbench__Vcb_simulation_enableTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &success);
using VsvsimTestbench__Vcb_simulation_initializeTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, std::string traceFilePath);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VsvsimTestbench__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VsvsimTestbench* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VsvsimTestbench___024root      TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_svsimTestbench;

    // CONSTRUCTORS
    VsvsimTestbench__Syms(VerilatedContext* contextp, const char* namep, VsvsimTestbench* modelp);
    ~VsvsimTestbench__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
