// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSVSIMTESTBENCH_H_
#define VERILATED_VSVSIMTESTBENCH_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class VsvsimTestbench__Syms;
class VsvsimTestbench___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VsvsimTestbench__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VsvsimTestbench___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VsvsimTestbench(VerilatedContext* contextp, const char* name = "TOP");
    explicit VsvsimTestbench(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VsvsimTestbench();
  private:
    VL_UNCOPYABLE(VsvsimTestbench);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    /// DPI Export functions
    static void getBitWidthImpl_clock(int* value);
    static void getBitWidthImpl_io_VGA_B(int* value);
    static void getBitWidthImpl_io_VGA_G(int* value);
    static void getBitWidthImpl_io_VGA_R(int* value);
    static void getBitWidthImpl_io_VGA_RGB(int* value);
    static void getBitWidthImpl_io_VGA_hSync(int* value);
    static void getBitWidthImpl_io_VGA_horCntr(int* value);
    static void getBitWidthImpl_io_VGA_vSync(int* value);
    static void getBitWidthImpl_io_VGA_verCntr(int* value);
    static void getBitWidthImpl_io_request(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_address(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_corrupt(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_data(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_mask(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_opcode(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_param(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_size(int* value);
    static void getBitWidthImpl_io_tilelink_a_bits_source(int* value);
    static void getBitWidthImpl_io_tilelink_a_ready(int* value);
    static void getBitWidthImpl_io_tilelink_a_valid(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_corrupt(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_data(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_denied(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_opcode(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_param(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_sink(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_size(int* value);
    static void getBitWidthImpl_io_tilelink_d_bits_source(int* value);
    static void getBitWidthImpl_io_tilelink_d_ready(int* value);
    static void getBitWidthImpl_io_tilelink_d_valid(int* value);
    static void getBitWidthImpl_reset(int* value);
    static void getBitsImpl_clock(svBitVecVal* value_clock);
    static void getBitsImpl_io_VGA_B(svBitVecVal* value_io_VGA_B);
    static void getBitsImpl_io_VGA_G(svBitVecVal* value_io_VGA_G);
    static void getBitsImpl_io_VGA_R(svBitVecVal* value_io_VGA_R);
    static void getBitsImpl_io_VGA_RGB(svBitVecVal* value_io_VGA_RGB);
    static void getBitsImpl_io_VGA_hSync(svBitVecVal* value_io_VGA_hSync);
    static void getBitsImpl_io_VGA_horCntr(svBitVecVal* value_io_VGA_horCntr);
    static void getBitsImpl_io_VGA_vSync(svBitVecVal* value_io_VGA_vSync);
    static void getBitsImpl_io_VGA_verCntr(svBitVecVal* value_io_VGA_verCntr);
    static void getBitsImpl_io_request(svBitVecVal* value_io_request);
    static void getBitsImpl_io_tilelink_a_bits_address(svBitVecVal* value_io_tilelink_a_bits_address);
    static void getBitsImpl_io_tilelink_a_bits_corrupt(svBitVecVal* value_io_tilelink_a_bits_corrupt);
    static void getBitsImpl_io_tilelink_a_bits_data(svBitVecVal* value_io_tilelink_a_bits_data);
    static void getBitsImpl_io_tilelink_a_bits_mask(svBitVecVal* value_io_tilelink_a_bits_mask);
    static void getBitsImpl_io_tilelink_a_bits_opcode(svBitVecVal* value_io_tilelink_a_bits_opcode);
    static void getBitsImpl_io_tilelink_a_bits_param(svBitVecVal* value_io_tilelink_a_bits_param);
    static void getBitsImpl_io_tilelink_a_bits_size(svBitVecVal* value_io_tilelink_a_bits_size);
    static void getBitsImpl_io_tilelink_a_bits_source(svBitVecVal* value_io_tilelink_a_bits_source);
    static void getBitsImpl_io_tilelink_a_ready(svBitVecVal* value_io_tilelink_a_ready);
    static void getBitsImpl_io_tilelink_a_valid(svBitVecVal* value_io_tilelink_a_valid);
    static void getBitsImpl_io_tilelink_d_bits_corrupt(svBitVecVal* value_io_tilelink_d_bits_corrupt);
    static void getBitsImpl_io_tilelink_d_bits_data(svBitVecVal* value_io_tilelink_d_bits_data);
    static void getBitsImpl_io_tilelink_d_bits_denied(svBitVecVal* value_io_tilelink_d_bits_denied);
    static void getBitsImpl_io_tilelink_d_bits_opcode(svBitVecVal* value_io_tilelink_d_bits_opcode);
    static void getBitsImpl_io_tilelink_d_bits_param(svBitVecVal* value_io_tilelink_d_bits_param);
    static void getBitsImpl_io_tilelink_d_bits_sink(svBitVecVal* value_io_tilelink_d_bits_sink);
    static void getBitsImpl_io_tilelink_d_bits_size(svBitVecVal* value_io_tilelink_d_bits_size);
    static void getBitsImpl_io_tilelink_d_bits_source(svBitVecVal* value_io_tilelink_d_bits_source);
    static void getBitsImpl_io_tilelink_d_ready(svBitVecVal* value_io_tilelink_d_ready);
    static void getBitsImpl_io_tilelink_d_valid(svBitVecVal* value_io_tilelink_d_valid);
    static void getBitsImpl_reset(svBitVecVal* value_reset);
    static void setBitsImpl_clock(const svBitVecVal* value_clock);
    static void setBitsImpl_io_VGA_B(const svBitVecVal* value_io_VGA_B);
    static void setBitsImpl_io_VGA_G(const svBitVecVal* value_io_VGA_G);
    static void setBitsImpl_io_VGA_R(const svBitVecVal* value_io_VGA_R);
    static void setBitsImpl_io_VGA_hSync(const svBitVecVal* value_io_VGA_hSync);
    static void setBitsImpl_io_VGA_horCntr(const svBitVecVal* value_io_VGA_horCntr);
    static void setBitsImpl_io_VGA_vSync(const svBitVecVal* value_io_VGA_vSync);
    static void setBitsImpl_io_VGA_verCntr(const svBitVecVal* value_io_VGA_verCntr);
    static void setBitsImpl_io_request(const svBitVecVal* value_io_request);
    static void setBitsImpl_io_tilelink_a_bits_address(const svBitVecVal* value_io_tilelink_a_bits_address);
    static void setBitsImpl_io_tilelink_a_bits_corrupt(const svBitVecVal* value_io_tilelink_a_bits_corrupt);
    static void setBitsImpl_io_tilelink_a_bits_data(const svBitVecVal* value_io_tilelink_a_bits_data);
    static void setBitsImpl_io_tilelink_a_bits_mask(const svBitVecVal* value_io_tilelink_a_bits_mask);
    static void setBitsImpl_io_tilelink_a_bits_opcode(const svBitVecVal* value_io_tilelink_a_bits_opcode);
    static void setBitsImpl_io_tilelink_a_bits_param(const svBitVecVal* value_io_tilelink_a_bits_param);
    static void setBitsImpl_io_tilelink_a_bits_size(const svBitVecVal* value_io_tilelink_a_bits_size);
    static void setBitsImpl_io_tilelink_a_bits_source(const svBitVecVal* value_io_tilelink_a_bits_source);
    static void setBitsImpl_io_tilelink_a_valid(const svBitVecVal* value_io_tilelink_a_valid);
    static void setBitsImpl_io_tilelink_d_ready(const svBitVecVal* value_io_tilelink_d_ready);
    static void setBitsImpl_reset(const svBitVecVal* value_reset);
    static void simulation_disableTrace(int* success);
    static void simulation_enableTrace(int* success);
    static void simulation_initializeTrace(const char* traceFilePath);

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
