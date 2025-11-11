// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VSVSIMTESTBENCH__DPI_H_
#define VERILATED_VSVSIMTESTBENCH__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:73:17
    extern void getBitWidthImpl_clock(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:448:17
    extern void getBitWidthImpl_io_VGA_B(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:465:17
    extern void getBitWidthImpl_io_VGA_G(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:482:17
    extern void getBitWidthImpl_io_VGA_R(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:533:17
    extern void getBitWidthImpl_io_VGA_RGB(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:516:17
    extern void getBitWidthImpl_io_VGA_hSync(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:431:17
    extern void getBitWidthImpl_io_VGA_horCntr(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:499:17
    extern void getBitWidthImpl_io_VGA_vSync(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:414:17
    extern void getBitWidthImpl_io_VGA_verCntr(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:397:17
    extern void getBitWidthImpl_io_request(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:283:17
    extern void getBitWidthImpl_io_tilelink_a_bits_address(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:232:17
    extern void getBitWidthImpl_io_tilelink_a_bits_corrupt(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:249:17
    extern void getBitWidthImpl_io_tilelink_a_bits_data(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:266:17
    extern void getBitWidthImpl_io_tilelink_a_bits_mask(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:351:17
    extern void getBitWidthImpl_io_tilelink_a_bits_opcode(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:334:17
    extern void getBitWidthImpl_io_tilelink_a_bits_param(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:317:17
    extern void getBitWidthImpl_io_tilelink_a_bits_size(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:300:17
    extern void getBitWidthImpl_io_tilelink_a_bits_source(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:385:17
    extern void getBitWidthImpl_io_tilelink_a_ready(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:368:17
    extern void getBitWidthImpl_io_tilelink_a_valid(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:107:17
    extern void getBitWidthImpl_io_tilelink_d_bits_corrupt(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:119:17
    extern void getBitWidthImpl_io_tilelink_d_bits_data(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:131:17
    extern void getBitWidthImpl_io_tilelink_d_bits_denied(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:191:17
    extern void getBitWidthImpl_io_tilelink_d_bits_opcode(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:179:17
    extern void getBitWidthImpl_io_tilelink_d_bits_param(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:143:17
    extern void getBitWidthImpl_io_tilelink_d_bits_sink(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:167:17
    extern void getBitWidthImpl_io_tilelink_d_bits_size(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:155:17
    extern void getBitWidthImpl_io_tilelink_d_bits_source(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:215:17
    extern void getBitWidthImpl_io_tilelink_d_ready(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:203:17
    extern void getBitWidthImpl_io_tilelink_d_valid(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:90:17
    extern void getBitWidthImpl_reset(int* value);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:83:17
    extern void getBitsImpl_clock(svBitVecVal* value_clock);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:458:17
    extern void getBitsImpl_io_VGA_B(svBitVecVal* value_io_VGA_B);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:475:17
    extern void getBitsImpl_io_VGA_G(svBitVecVal* value_io_VGA_G);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:492:17
    extern void getBitsImpl_io_VGA_R(svBitVecVal* value_io_VGA_R);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:538:17
    extern void getBitsImpl_io_VGA_RGB(svBitVecVal* value_io_VGA_RGB);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:526:17
    extern void getBitsImpl_io_VGA_hSync(svBitVecVal* value_io_VGA_hSync);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:441:17
    extern void getBitsImpl_io_VGA_horCntr(svBitVecVal* value_io_VGA_horCntr);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:509:17
    extern void getBitsImpl_io_VGA_vSync(svBitVecVal* value_io_VGA_vSync);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:424:17
    extern void getBitsImpl_io_VGA_verCntr(svBitVecVal* value_io_VGA_verCntr);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:407:17
    extern void getBitsImpl_io_request(svBitVecVal* value_io_request);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:293:17
    extern void getBitsImpl_io_tilelink_a_bits_address(svBitVecVal* value_io_tilelink_a_bits_address);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:242:17
    extern void getBitsImpl_io_tilelink_a_bits_corrupt(svBitVecVal* value_io_tilelink_a_bits_corrupt);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:259:17
    extern void getBitsImpl_io_tilelink_a_bits_data(svBitVecVal* value_io_tilelink_a_bits_data);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:276:17
    extern void getBitsImpl_io_tilelink_a_bits_mask(svBitVecVal* value_io_tilelink_a_bits_mask);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:361:17
    extern void getBitsImpl_io_tilelink_a_bits_opcode(svBitVecVal* value_io_tilelink_a_bits_opcode);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:344:17
    extern void getBitsImpl_io_tilelink_a_bits_param(svBitVecVal* value_io_tilelink_a_bits_param);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:327:17
    extern void getBitsImpl_io_tilelink_a_bits_size(svBitVecVal* value_io_tilelink_a_bits_size);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:310:17
    extern void getBitsImpl_io_tilelink_a_bits_source(svBitVecVal* value_io_tilelink_a_bits_source);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:390:17
    extern void getBitsImpl_io_tilelink_a_ready(svBitVecVal* value_io_tilelink_a_ready);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:378:17
    extern void getBitsImpl_io_tilelink_a_valid(svBitVecVal* value_io_tilelink_a_valid);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:112:17
    extern void getBitsImpl_io_tilelink_d_bits_corrupt(svBitVecVal* value_io_tilelink_d_bits_corrupt);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:124:17
    extern void getBitsImpl_io_tilelink_d_bits_data(svBitVecVal* value_io_tilelink_d_bits_data);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:136:17
    extern void getBitsImpl_io_tilelink_d_bits_denied(svBitVecVal* value_io_tilelink_d_bits_denied);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:196:17
    extern void getBitsImpl_io_tilelink_d_bits_opcode(svBitVecVal* value_io_tilelink_d_bits_opcode);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:184:17
    extern void getBitsImpl_io_tilelink_d_bits_param(svBitVecVal* value_io_tilelink_d_bits_param);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:148:17
    extern void getBitsImpl_io_tilelink_d_bits_sink(svBitVecVal* value_io_tilelink_d_bits_sink);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:172:17
    extern void getBitsImpl_io_tilelink_d_bits_size(svBitVecVal* value_io_tilelink_d_bits_size);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:160:17
    extern void getBitsImpl_io_tilelink_d_bits_source(svBitVecVal* value_io_tilelink_d_bits_source);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:225:17
    extern void getBitsImpl_io_tilelink_d_ready(svBitVecVal* value_io_tilelink_d_ready);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:208:17
    extern void getBitsImpl_io_tilelink_d_valid(svBitVecVal* value_io_tilelink_d_valid);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:100:17
    extern void getBitsImpl_reset(svBitVecVal* value_reset);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:78:17
    extern void setBitsImpl_clock(const svBitVecVal* value_clock);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:453:17
    extern void setBitsImpl_io_VGA_B(const svBitVecVal* value_io_VGA_B);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:470:17
    extern void setBitsImpl_io_VGA_G(const svBitVecVal* value_io_VGA_G);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:487:17
    extern void setBitsImpl_io_VGA_R(const svBitVecVal* value_io_VGA_R);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:521:17
    extern void setBitsImpl_io_VGA_hSync(const svBitVecVal* value_io_VGA_hSync);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:436:17
    extern void setBitsImpl_io_VGA_horCntr(const svBitVecVal* value_io_VGA_horCntr);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:504:17
    extern void setBitsImpl_io_VGA_vSync(const svBitVecVal* value_io_VGA_vSync);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:419:17
    extern void setBitsImpl_io_VGA_verCntr(const svBitVecVal* value_io_VGA_verCntr);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:402:17
    extern void setBitsImpl_io_request(const svBitVecVal* value_io_request);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:288:17
    extern void setBitsImpl_io_tilelink_a_bits_address(const svBitVecVal* value_io_tilelink_a_bits_address);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:237:17
    extern void setBitsImpl_io_tilelink_a_bits_corrupt(const svBitVecVal* value_io_tilelink_a_bits_corrupt);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:254:17
    extern void setBitsImpl_io_tilelink_a_bits_data(const svBitVecVal* value_io_tilelink_a_bits_data);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:271:17
    extern void setBitsImpl_io_tilelink_a_bits_mask(const svBitVecVal* value_io_tilelink_a_bits_mask);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:356:17
    extern void setBitsImpl_io_tilelink_a_bits_opcode(const svBitVecVal* value_io_tilelink_a_bits_opcode);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:339:17
    extern void setBitsImpl_io_tilelink_a_bits_param(const svBitVecVal* value_io_tilelink_a_bits_param);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:322:17
    extern void setBitsImpl_io_tilelink_a_bits_size(const svBitVecVal* value_io_tilelink_a_bits_size);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:305:17
    extern void setBitsImpl_io_tilelink_a_bits_source(const svBitVecVal* value_io_tilelink_a_bits_source);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:373:17
    extern void setBitsImpl_io_tilelink_a_valid(const svBitVecVal* value_io_tilelink_a_valid);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:220:17
    extern void setBitsImpl_io_tilelink_d_ready(const svBitVecVal* value_io_tilelink_d_ready);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:95:17
    extern void setBitsImpl_reset(const svBitVecVal* value_reset);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:611:17
    extern void simulation_disableTrace(int* success);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:596:17
    extern void simulation_enableTrace(int* success);
    // DPI export at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:572:17
    extern void simulation_initializeTrace(const char* traceFilePath);

    // DPI IMPORTS
    // DPI import at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:68:40
    extern void initTestBenchScope();
    // DPI import at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:566:32
    extern void run_simulation(int timesteps, int* done);
    // DPI import at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:544:31
    extern int simulation_body();
    // DPI import at /app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/../generated-sources/testbench.sv:554:31
    extern int simulation_final();

#ifdef __cplusplus
}
#endif

#endif  // guard
