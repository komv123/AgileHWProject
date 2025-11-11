#include <stdint.h>

#ifdef SVSIM_ENABLE_VERILATOR_SUPPORT
#include "verilated-sources/VsvsimTestbench__Dpi.h"
#endif
#ifdef SVSIM_ENABLE_VCS_SUPPORT
#include "vc_hdrs.h"
#endif

extern "C" {
 svScope setScopeToTestBench();
void getBitWidth_clock(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_clock(result);
           svSetScope(prev);
        }
void getBits_clock(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_clock(result);
           svSetScope(prev);
        }
void setBits_clock(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_clock(data);
           svSetScope(prev);
        }
void getBitWidth_reset(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_reset(result);
           svSetScope(prev);
        }
void getBits_reset(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_reset(result);
           svSetScope(prev);
        }
void setBits_reset(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_reset(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_corrupt(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_corrupt(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_corrupt(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_corrupt(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_data(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_data(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_data(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_data(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_denied(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_denied(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_denied(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_denied(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_sink(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_sink(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_sink(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_sink(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_source(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_source(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_source(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_source(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_size(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_size(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_size(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_size(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_param(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_param(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_param(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_param(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_bits_opcode(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_bits_opcode(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_bits_opcode(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_bits_opcode(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_valid(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_valid(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_valid(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_valid(result);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_d_ready(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_d_ready(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_d_ready(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_d_ready(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_d_ready(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_d_ready(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_corrupt(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_corrupt(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_corrupt(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_corrupt(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_corrupt(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_corrupt(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_data(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_data(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_data(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_data(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_data(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_data(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_mask(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_mask(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_mask(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_mask(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_mask(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_mask(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_address(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_address(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_address(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_address(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_address(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_address(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_source(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_source(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_source(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_source(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_source(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_source(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_size(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_size(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_size(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_size(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_size(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_size(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_param(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_param(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_param(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_param(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_param(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_param(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_bits_opcode(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_bits_opcode(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_bits_opcode(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_bits_opcode(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_bits_opcode(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_bits_opcode(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_valid(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_valid(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_valid(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_valid(result);
           svSetScope(prev);
        }
void setBits_io_tilelink_a_valid(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_tilelink_a_valid(data);
           svSetScope(prev);
        }
void getBitWidth_io_tilelink_a_ready(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_tilelink_a_ready(result);
           svSetScope(prev);
        }
void getBits_io_tilelink_a_ready(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_tilelink_a_ready(result);
           svSetScope(prev);
        }
void getBitWidth_io_request(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_request(result);
           svSetScope(prev);
        }
void getBits_io_request(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_request(result);
           svSetScope(prev);
        }
void setBits_io_request(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_request(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_verCntr(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_verCntr(result);
           svSetScope(prev);
        }
void getBits_io_VGA_verCntr(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_verCntr(result);
           svSetScope(prev);
        }
void setBits_io_VGA_verCntr(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_verCntr(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_horCntr(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_horCntr(result);
           svSetScope(prev);
        }
void getBits_io_VGA_horCntr(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_horCntr(result);
           svSetScope(prev);
        }
void setBits_io_VGA_horCntr(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_horCntr(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_B(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_B(result);
           svSetScope(prev);
        }
void getBits_io_VGA_B(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_B(result);
           svSetScope(prev);
        }
void setBits_io_VGA_B(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_B(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_G(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_G(result);
           svSetScope(prev);
        }
void getBits_io_VGA_G(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_G(result);
           svSetScope(prev);
        }
void setBits_io_VGA_G(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_G(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_R(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_R(result);
           svSetScope(prev);
        }
void getBits_io_VGA_R(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_R(result);
           svSetScope(prev);
        }
void setBits_io_VGA_R(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_R(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_vSync(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_vSync(result);
           svSetScope(prev);
        }
void getBits_io_VGA_vSync(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_vSync(result);
           svSetScope(prev);
        }
void setBits_io_VGA_vSync(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_vSync(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_hSync(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_hSync(result);
           svSetScope(prev);
        }
void getBits_io_VGA_hSync(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_hSync(result);
           svSetScope(prev);
        }
void setBits_io_VGA_hSync(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_VGA_hSync(data);
           svSetScope(prev);
        }
void getBitWidth_io_VGA_RGB(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_VGA_RGB(result);
           svSetScope(prev);
        }
void getBits_io_VGA_RGB(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_VGA_RGB(result);
           svSetScope(prev);
        }

int port_getter(int id, int *bitWidth, void (**getter)(uint8_t*)) {
  switch (id) {
    case 0: // clock
      getBitWidth_clock(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_clock;
      return 0;
    case 1: // reset
      getBitWidth_reset(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_reset;
      return 0;
    case 2: // io_tilelink_d_bits_corrupt
      getBitWidth_io_tilelink_d_bits_corrupt(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_corrupt;
      return 0;
    case 3: // io_tilelink_d_bits_data
      getBitWidth_io_tilelink_d_bits_data(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_data;
      return 0;
    case 4: // io_tilelink_d_bits_denied
      getBitWidth_io_tilelink_d_bits_denied(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_denied;
      return 0;
    case 5: // io_tilelink_d_bits_sink
      getBitWidth_io_tilelink_d_bits_sink(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_sink;
      return 0;
    case 6: // io_tilelink_d_bits_source
      getBitWidth_io_tilelink_d_bits_source(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_source;
      return 0;
    case 7: // io_tilelink_d_bits_size
      getBitWidth_io_tilelink_d_bits_size(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_size;
      return 0;
    case 8: // io_tilelink_d_bits_param
      getBitWidth_io_tilelink_d_bits_param(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_param;
      return 0;
    case 9: // io_tilelink_d_bits_opcode
      getBitWidth_io_tilelink_d_bits_opcode(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_bits_opcode;
      return 0;
    case 10: // io_tilelink_d_valid
      getBitWidth_io_tilelink_d_valid(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_valid;
      return 0;
    case 11: // io_tilelink_d_ready
      getBitWidth_io_tilelink_d_ready(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_d_ready;
      return 0;
    case 12: // io_tilelink_a_bits_corrupt
      getBitWidth_io_tilelink_a_bits_corrupt(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_corrupt;
      return 0;
    case 13: // io_tilelink_a_bits_data
      getBitWidth_io_tilelink_a_bits_data(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_data;
      return 0;
    case 14: // io_tilelink_a_bits_mask
      getBitWidth_io_tilelink_a_bits_mask(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_mask;
      return 0;
    case 15: // io_tilelink_a_bits_address
      getBitWidth_io_tilelink_a_bits_address(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_address;
      return 0;
    case 16: // io_tilelink_a_bits_source
      getBitWidth_io_tilelink_a_bits_source(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_source;
      return 0;
    case 17: // io_tilelink_a_bits_size
      getBitWidth_io_tilelink_a_bits_size(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_size;
      return 0;
    case 18: // io_tilelink_a_bits_param
      getBitWidth_io_tilelink_a_bits_param(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_param;
      return 0;
    case 19: // io_tilelink_a_bits_opcode
      getBitWidth_io_tilelink_a_bits_opcode(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_bits_opcode;
      return 0;
    case 20: // io_tilelink_a_valid
      getBitWidth_io_tilelink_a_valid(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_valid;
      return 0;
    case 21: // io_tilelink_a_ready
      getBitWidth_io_tilelink_a_ready(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_tilelink_a_ready;
      return 0;
    case 22: // io_request
      getBitWidth_io_request(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_request;
      return 0;
    case 23: // io_VGA_verCntr
      getBitWidth_io_VGA_verCntr(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_verCntr;
      return 0;
    case 24: // io_VGA_horCntr
      getBitWidth_io_VGA_horCntr(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_horCntr;
      return 0;
    case 25: // io_VGA_B
      getBitWidth_io_VGA_B(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_B;
      return 0;
    case 26: // io_VGA_G
      getBitWidth_io_VGA_G(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_G;
      return 0;
    case 27: // io_VGA_R
      getBitWidth_io_VGA_R(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_R;
      return 0;
    case 28: // io_VGA_vSync
      getBitWidth_io_VGA_vSync(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_vSync;
      return 0;
    case 29: // io_VGA_hSync
      getBitWidth_io_VGA_hSync(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_hSync;
      return 0;
    case 30: // io_VGA_RGB
      getBitWidth_io_VGA_RGB(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_VGA_RGB;
      return 0;
    default:
      return -1;
  }
}

int port_setter(int id, int *bitWidth, void (**setter)(const uint8_t*)) {
  switch (id) {
    case 0: // clock
      getBitWidth_clock(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_clock;
      return 0;
    case 1: // reset
      getBitWidth_reset(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_reset;
      return 0;
    case 11: // io_tilelink_d_ready
      getBitWidth_io_tilelink_d_ready(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_d_ready;
      return 0;
    case 12: // io_tilelink_a_bits_corrupt
      getBitWidth_io_tilelink_a_bits_corrupt(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_corrupt;
      return 0;
    case 13: // io_tilelink_a_bits_data
      getBitWidth_io_tilelink_a_bits_data(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_data;
      return 0;
    case 14: // io_tilelink_a_bits_mask
      getBitWidth_io_tilelink_a_bits_mask(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_mask;
      return 0;
    case 15: // io_tilelink_a_bits_address
      getBitWidth_io_tilelink_a_bits_address(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_address;
      return 0;
    case 16: // io_tilelink_a_bits_source
      getBitWidth_io_tilelink_a_bits_source(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_source;
      return 0;
    case 17: // io_tilelink_a_bits_size
      getBitWidth_io_tilelink_a_bits_size(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_size;
      return 0;
    case 18: // io_tilelink_a_bits_param
      getBitWidth_io_tilelink_a_bits_param(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_param;
      return 0;
    case 19: // io_tilelink_a_bits_opcode
      getBitWidth_io_tilelink_a_bits_opcode(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_bits_opcode;
      return 0;
    case 20: // io_tilelink_a_valid
      getBitWidth_io_tilelink_a_valid(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_tilelink_a_valid;
      return 0;
    case 22: // io_request
      getBitWidth_io_request(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_request;
      return 0;
    case 23: // io_VGA_verCntr
      getBitWidth_io_VGA_verCntr(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_verCntr;
      return 0;
    case 24: // io_VGA_horCntr
      getBitWidth_io_VGA_horCntr(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_horCntr;
      return 0;
    case 25: // io_VGA_B
      getBitWidth_io_VGA_B(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_B;
      return 0;
    case 26: // io_VGA_G
      getBitWidth_io_VGA_G(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_G;
      return 0;
    case 27: // io_VGA_R
      getBitWidth_io_VGA_R(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_R;
      return 0;
    case 28: // io_VGA_vSync
      getBitWidth_io_VGA_vSync(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_vSync;
      return 0;
    case 29: // io_VGA_hSync
      getBitWidth_io_VGA_hSync(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_VGA_hSync;
      return 0;
    default:
      return -1;
  }
}

} // extern "C"

