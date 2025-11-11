module svsimTestbench;
  reg  [$bits(dut.clock)-1:0] clock = '0;
  reg  [$bits(dut.reset)-1:0] reset = '0;
  wire [$bits(dut.io_tilelink_d_bits_corrupt)-1:0] io_tilelink_d_bits_corrupt;
  wire [$bits(dut.io_tilelink_d_bits_data)-1:0] io_tilelink_d_bits_data;
  wire [$bits(dut.io_tilelink_d_bits_denied)-1:0] io_tilelink_d_bits_denied;
  wire [$bits(dut.io_tilelink_d_bits_sink)-1:0] io_tilelink_d_bits_sink;
  wire [$bits(dut.io_tilelink_d_bits_source)-1:0] io_tilelink_d_bits_source;
  wire [$bits(dut.io_tilelink_d_bits_size)-1:0] io_tilelink_d_bits_size;
  wire [$bits(dut.io_tilelink_d_bits_param)-1:0] io_tilelink_d_bits_param;
  wire [$bits(dut.io_tilelink_d_bits_opcode)-1:0] io_tilelink_d_bits_opcode;
  wire [$bits(dut.io_tilelink_d_valid)-1:0] io_tilelink_d_valid;
  reg  [$bits(dut.io_tilelink_d_ready)-1:0] io_tilelink_d_ready = '0;
  reg  [$bits(dut.io_tilelink_a_bits_corrupt)-1:0] io_tilelink_a_bits_corrupt = '0;
  reg  [$bits(dut.io_tilelink_a_bits_data)-1:0] io_tilelink_a_bits_data = '0;
  reg  [$bits(dut.io_tilelink_a_bits_mask)-1:0] io_tilelink_a_bits_mask = '0;
  reg  [$bits(dut.io_tilelink_a_bits_address)-1:0] io_tilelink_a_bits_address = '0;
  reg  [$bits(dut.io_tilelink_a_bits_source)-1:0] io_tilelink_a_bits_source = '0;
  reg  [$bits(dut.io_tilelink_a_bits_size)-1:0] io_tilelink_a_bits_size = '0;
  reg  [$bits(dut.io_tilelink_a_bits_param)-1:0] io_tilelink_a_bits_param = '0;
  reg  [$bits(dut.io_tilelink_a_bits_opcode)-1:0] io_tilelink_a_bits_opcode = '0;
  reg  [$bits(dut.io_tilelink_a_valid)-1:0] io_tilelink_a_valid = '0;
  wire [$bits(dut.io_tilelink_a_ready)-1:0] io_tilelink_a_ready;
  reg  [$bits(dut.io_request)-1:0] io_request = '0;
  reg  [$bits(dut.io_VGA_verCntr)-1:0] io_VGA_verCntr = '0;
  reg  [$bits(dut.io_VGA_horCntr)-1:0] io_VGA_horCntr = '0;
  reg  [$bits(dut.io_VGA_B)-1:0] io_VGA_B = '0;
  reg  [$bits(dut.io_VGA_G)-1:0] io_VGA_G = '0;
  reg  [$bits(dut.io_VGA_R)-1:0] io_VGA_R = '0;
  reg  [$bits(dut.io_VGA_vSync)-1:0] io_VGA_vSync = '0;
  reg  [$bits(dut.io_VGA_hSync)-1:0] io_VGA_hSync = '0;
  wire [$bits(dut.io_VGA_RGB)-1:0] io_VGA_RGB;

VideoBuffer dut (
    .clock(clock),
    .reset(reset),
    .io_tilelink_d_bits_corrupt(io_tilelink_d_bits_corrupt),
    .io_tilelink_d_bits_data(io_tilelink_d_bits_data),
    .io_tilelink_d_bits_denied(io_tilelink_d_bits_denied),
    .io_tilelink_d_bits_sink(io_tilelink_d_bits_sink),
    .io_tilelink_d_bits_source(io_tilelink_d_bits_source),
    .io_tilelink_d_bits_size(io_tilelink_d_bits_size),
    .io_tilelink_d_bits_param(io_tilelink_d_bits_param),
    .io_tilelink_d_bits_opcode(io_tilelink_d_bits_opcode),
    .io_tilelink_d_valid(io_tilelink_d_valid),
    .io_tilelink_d_ready(io_tilelink_d_ready),
    .io_tilelink_a_bits_corrupt(io_tilelink_a_bits_corrupt),
    .io_tilelink_a_bits_data(io_tilelink_a_bits_data),
    .io_tilelink_a_bits_mask(io_tilelink_a_bits_mask),
    .io_tilelink_a_bits_address(io_tilelink_a_bits_address),
    .io_tilelink_a_bits_source(io_tilelink_a_bits_source),
    .io_tilelink_a_bits_size(io_tilelink_a_bits_size),
    .io_tilelink_a_bits_param(io_tilelink_a_bits_param),
    .io_tilelink_a_bits_opcode(io_tilelink_a_bits_opcode),
    .io_tilelink_a_valid(io_tilelink_a_valid),
    .io_tilelink_a_ready(io_tilelink_a_ready),
    .io_request(io_request),
    .io_VGA_verCntr(io_VGA_verCntr),
    .io_VGA_horCntr(io_VGA_horCntr),
    .io_VGA_B(io_VGA_B),
    .io_VGA_G(io_VGA_G),
    .io_VGA_R(io_VGA_R),
    .io_VGA_vSync(io_VGA_vSync),
    .io_VGA_hSync(io_VGA_hSync),
    .io_VGA_RGB(io_VGA_RGB)
);

  import "DPI-C" context function void initTestBenchScope();
  initial
    initTestBenchScope();
  // Port 0: clock
  export "DPI-C" function getBitWidthImpl_clock;
  function void getBitWidthImpl_clock;
    output int value;
    value = $bits(dut.clock);
  endfunction
  export "DPI-C" function setBitsImpl_clock;
  function void setBitsImpl_clock;
    input bit [$bits(dut.clock)-1:0] value_clock;
    clock = value_clock;
  endfunction
  export "DPI-C" function getBitsImpl_clock;
  function void getBitsImpl_clock;
    output bit [$bits(dut.clock)-1:0] value_clock;
    value_clock = clock;
  endfunction

  // Port 1: reset
  export "DPI-C" function getBitWidthImpl_reset;
  function void getBitWidthImpl_reset;
    output int value;
    value = $bits(dut.reset);
  endfunction
  export "DPI-C" function setBitsImpl_reset;
  function void setBitsImpl_reset;
    input bit [$bits(dut.reset)-1:0] value_reset;
    reset = value_reset;
  endfunction
  export "DPI-C" function getBitsImpl_reset;
  function void getBitsImpl_reset;
    output bit [$bits(dut.reset)-1:0] value_reset;
    value_reset = reset;
  endfunction

  // Port 2: io_tilelink_d_bits_corrupt
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_corrupt;
  function void getBitWidthImpl_io_tilelink_d_bits_corrupt;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_corrupt);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_corrupt;
  function void getBitsImpl_io_tilelink_d_bits_corrupt;
    output bit [$bits(dut.io_tilelink_d_bits_corrupt)-1:0] value_io_tilelink_d_bits_corrupt;
    value_io_tilelink_d_bits_corrupt = io_tilelink_d_bits_corrupt;
  endfunction

  // Port 3: io_tilelink_d_bits_data
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_data;
  function void getBitWidthImpl_io_tilelink_d_bits_data;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_data);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_data;
  function void getBitsImpl_io_tilelink_d_bits_data;
    output bit [$bits(dut.io_tilelink_d_bits_data)-1:0] value_io_tilelink_d_bits_data;
    value_io_tilelink_d_bits_data = io_tilelink_d_bits_data;
  endfunction

  // Port 4: io_tilelink_d_bits_denied
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_denied;
  function void getBitWidthImpl_io_tilelink_d_bits_denied;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_denied);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_denied;
  function void getBitsImpl_io_tilelink_d_bits_denied;
    output bit [$bits(dut.io_tilelink_d_bits_denied)-1:0] value_io_tilelink_d_bits_denied;
    value_io_tilelink_d_bits_denied = io_tilelink_d_bits_denied;
  endfunction

  // Port 5: io_tilelink_d_bits_sink
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_sink;
  function void getBitWidthImpl_io_tilelink_d_bits_sink;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_sink);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_sink;
  function void getBitsImpl_io_tilelink_d_bits_sink;
    output bit [$bits(dut.io_tilelink_d_bits_sink)-1:0] value_io_tilelink_d_bits_sink;
    value_io_tilelink_d_bits_sink = io_tilelink_d_bits_sink;
  endfunction

  // Port 6: io_tilelink_d_bits_source
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_source;
  function void getBitWidthImpl_io_tilelink_d_bits_source;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_source);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_source;
  function void getBitsImpl_io_tilelink_d_bits_source;
    output bit [$bits(dut.io_tilelink_d_bits_source)-1:0] value_io_tilelink_d_bits_source;
    value_io_tilelink_d_bits_source = io_tilelink_d_bits_source;
  endfunction

  // Port 7: io_tilelink_d_bits_size
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_size;
  function void getBitWidthImpl_io_tilelink_d_bits_size;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_size);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_size;
  function void getBitsImpl_io_tilelink_d_bits_size;
    output bit [$bits(dut.io_tilelink_d_bits_size)-1:0] value_io_tilelink_d_bits_size;
    value_io_tilelink_d_bits_size = io_tilelink_d_bits_size;
  endfunction

  // Port 8: io_tilelink_d_bits_param
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_param;
  function void getBitWidthImpl_io_tilelink_d_bits_param;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_param);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_param;
  function void getBitsImpl_io_tilelink_d_bits_param;
    output bit [$bits(dut.io_tilelink_d_bits_param)-1:0] value_io_tilelink_d_bits_param;
    value_io_tilelink_d_bits_param = io_tilelink_d_bits_param;
  endfunction

  // Port 9: io_tilelink_d_bits_opcode
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_bits_opcode;
  function void getBitWidthImpl_io_tilelink_d_bits_opcode;
    output int value;
    value = $bits(dut.io_tilelink_d_bits_opcode);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_bits_opcode;
  function void getBitsImpl_io_tilelink_d_bits_opcode;
    output bit [$bits(dut.io_tilelink_d_bits_opcode)-1:0] value_io_tilelink_d_bits_opcode;
    value_io_tilelink_d_bits_opcode = io_tilelink_d_bits_opcode;
  endfunction

  // Port a: io_tilelink_d_valid
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_valid;
  function void getBitWidthImpl_io_tilelink_d_valid;
    output int value;
    value = $bits(dut.io_tilelink_d_valid);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_valid;
  function void getBitsImpl_io_tilelink_d_valid;
    output bit [$bits(dut.io_tilelink_d_valid)-1:0] value_io_tilelink_d_valid;
    value_io_tilelink_d_valid = io_tilelink_d_valid;
  endfunction

  // Port b: io_tilelink_d_ready
  export "DPI-C" function getBitWidthImpl_io_tilelink_d_ready;
  function void getBitWidthImpl_io_tilelink_d_ready;
    output int value;
    value = $bits(dut.io_tilelink_d_ready);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_d_ready;
  function void setBitsImpl_io_tilelink_d_ready;
    input bit [$bits(dut.io_tilelink_d_ready)-1:0] value_io_tilelink_d_ready;
    io_tilelink_d_ready = value_io_tilelink_d_ready;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_d_ready;
  function void getBitsImpl_io_tilelink_d_ready;
    output bit [$bits(dut.io_tilelink_d_ready)-1:0] value_io_tilelink_d_ready;
    value_io_tilelink_d_ready = io_tilelink_d_ready;
  endfunction

  // Port c: io_tilelink_a_bits_corrupt
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_corrupt;
  function void getBitWidthImpl_io_tilelink_a_bits_corrupt;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_corrupt);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_corrupt;
  function void setBitsImpl_io_tilelink_a_bits_corrupt;
    input bit [$bits(dut.io_tilelink_a_bits_corrupt)-1:0] value_io_tilelink_a_bits_corrupt;
    io_tilelink_a_bits_corrupt = value_io_tilelink_a_bits_corrupt;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_corrupt;
  function void getBitsImpl_io_tilelink_a_bits_corrupt;
    output bit [$bits(dut.io_tilelink_a_bits_corrupt)-1:0] value_io_tilelink_a_bits_corrupt;
    value_io_tilelink_a_bits_corrupt = io_tilelink_a_bits_corrupt;
  endfunction

  // Port d: io_tilelink_a_bits_data
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_data;
  function void getBitWidthImpl_io_tilelink_a_bits_data;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_data);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_data;
  function void setBitsImpl_io_tilelink_a_bits_data;
    input bit [$bits(dut.io_tilelink_a_bits_data)-1:0] value_io_tilelink_a_bits_data;
    io_tilelink_a_bits_data = value_io_tilelink_a_bits_data;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_data;
  function void getBitsImpl_io_tilelink_a_bits_data;
    output bit [$bits(dut.io_tilelink_a_bits_data)-1:0] value_io_tilelink_a_bits_data;
    value_io_tilelink_a_bits_data = io_tilelink_a_bits_data;
  endfunction

  // Port e: io_tilelink_a_bits_mask
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_mask;
  function void getBitWidthImpl_io_tilelink_a_bits_mask;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_mask);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_mask;
  function void setBitsImpl_io_tilelink_a_bits_mask;
    input bit [$bits(dut.io_tilelink_a_bits_mask)-1:0] value_io_tilelink_a_bits_mask;
    io_tilelink_a_bits_mask = value_io_tilelink_a_bits_mask;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_mask;
  function void getBitsImpl_io_tilelink_a_bits_mask;
    output bit [$bits(dut.io_tilelink_a_bits_mask)-1:0] value_io_tilelink_a_bits_mask;
    value_io_tilelink_a_bits_mask = io_tilelink_a_bits_mask;
  endfunction

  // Port f: io_tilelink_a_bits_address
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_address;
  function void getBitWidthImpl_io_tilelink_a_bits_address;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_address);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_address;
  function void setBitsImpl_io_tilelink_a_bits_address;
    input bit [$bits(dut.io_tilelink_a_bits_address)-1:0] value_io_tilelink_a_bits_address;
    io_tilelink_a_bits_address = value_io_tilelink_a_bits_address;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_address;
  function void getBitsImpl_io_tilelink_a_bits_address;
    output bit [$bits(dut.io_tilelink_a_bits_address)-1:0] value_io_tilelink_a_bits_address;
    value_io_tilelink_a_bits_address = io_tilelink_a_bits_address;
  endfunction

  // Port 10: io_tilelink_a_bits_source
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_source;
  function void getBitWidthImpl_io_tilelink_a_bits_source;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_source);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_source;
  function void setBitsImpl_io_tilelink_a_bits_source;
    input bit [$bits(dut.io_tilelink_a_bits_source)-1:0] value_io_tilelink_a_bits_source;
    io_tilelink_a_bits_source = value_io_tilelink_a_bits_source;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_source;
  function void getBitsImpl_io_tilelink_a_bits_source;
    output bit [$bits(dut.io_tilelink_a_bits_source)-1:0] value_io_tilelink_a_bits_source;
    value_io_tilelink_a_bits_source = io_tilelink_a_bits_source;
  endfunction

  // Port 11: io_tilelink_a_bits_size
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_size;
  function void getBitWidthImpl_io_tilelink_a_bits_size;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_size);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_size;
  function void setBitsImpl_io_tilelink_a_bits_size;
    input bit [$bits(dut.io_tilelink_a_bits_size)-1:0] value_io_tilelink_a_bits_size;
    io_tilelink_a_bits_size = value_io_tilelink_a_bits_size;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_size;
  function void getBitsImpl_io_tilelink_a_bits_size;
    output bit [$bits(dut.io_tilelink_a_bits_size)-1:0] value_io_tilelink_a_bits_size;
    value_io_tilelink_a_bits_size = io_tilelink_a_bits_size;
  endfunction

  // Port 12: io_tilelink_a_bits_param
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_param;
  function void getBitWidthImpl_io_tilelink_a_bits_param;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_param);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_param;
  function void setBitsImpl_io_tilelink_a_bits_param;
    input bit [$bits(dut.io_tilelink_a_bits_param)-1:0] value_io_tilelink_a_bits_param;
    io_tilelink_a_bits_param = value_io_tilelink_a_bits_param;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_param;
  function void getBitsImpl_io_tilelink_a_bits_param;
    output bit [$bits(dut.io_tilelink_a_bits_param)-1:0] value_io_tilelink_a_bits_param;
    value_io_tilelink_a_bits_param = io_tilelink_a_bits_param;
  endfunction

  // Port 13: io_tilelink_a_bits_opcode
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_bits_opcode;
  function void getBitWidthImpl_io_tilelink_a_bits_opcode;
    output int value;
    value = $bits(dut.io_tilelink_a_bits_opcode);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_bits_opcode;
  function void setBitsImpl_io_tilelink_a_bits_opcode;
    input bit [$bits(dut.io_tilelink_a_bits_opcode)-1:0] value_io_tilelink_a_bits_opcode;
    io_tilelink_a_bits_opcode = value_io_tilelink_a_bits_opcode;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_bits_opcode;
  function void getBitsImpl_io_tilelink_a_bits_opcode;
    output bit [$bits(dut.io_tilelink_a_bits_opcode)-1:0] value_io_tilelink_a_bits_opcode;
    value_io_tilelink_a_bits_opcode = io_tilelink_a_bits_opcode;
  endfunction

  // Port 14: io_tilelink_a_valid
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_valid;
  function void getBitWidthImpl_io_tilelink_a_valid;
    output int value;
    value = $bits(dut.io_tilelink_a_valid);
  endfunction
  export "DPI-C" function setBitsImpl_io_tilelink_a_valid;
  function void setBitsImpl_io_tilelink_a_valid;
    input bit [$bits(dut.io_tilelink_a_valid)-1:0] value_io_tilelink_a_valid;
    io_tilelink_a_valid = value_io_tilelink_a_valid;
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_valid;
  function void getBitsImpl_io_tilelink_a_valid;
    output bit [$bits(dut.io_tilelink_a_valid)-1:0] value_io_tilelink_a_valid;
    value_io_tilelink_a_valid = io_tilelink_a_valid;
  endfunction

  // Port 15: io_tilelink_a_ready
  export "DPI-C" function getBitWidthImpl_io_tilelink_a_ready;
  function void getBitWidthImpl_io_tilelink_a_ready;
    output int value;
    value = $bits(dut.io_tilelink_a_ready);
  endfunction
  export "DPI-C" function getBitsImpl_io_tilelink_a_ready;
  function void getBitsImpl_io_tilelink_a_ready;
    output bit [$bits(dut.io_tilelink_a_ready)-1:0] value_io_tilelink_a_ready;
    value_io_tilelink_a_ready = io_tilelink_a_ready;
  endfunction

  // Port 16: io_request
  export "DPI-C" function getBitWidthImpl_io_request;
  function void getBitWidthImpl_io_request;
    output int value;
    value = $bits(dut.io_request);
  endfunction
  export "DPI-C" function setBitsImpl_io_request;
  function void setBitsImpl_io_request;
    input bit [$bits(dut.io_request)-1:0] value_io_request;
    io_request = value_io_request;
  endfunction
  export "DPI-C" function getBitsImpl_io_request;
  function void getBitsImpl_io_request;
    output bit [$bits(dut.io_request)-1:0] value_io_request;
    value_io_request = io_request;
  endfunction

  // Port 17: io_VGA_verCntr
  export "DPI-C" function getBitWidthImpl_io_VGA_verCntr;
  function void getBitWidthImpl_io_VGA_verCntr;
    output int value;
    value = $bits(dut.io_VGA_verCntr);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_verCntr;
  function void setBitsImpl_io_VGA_verCntr;
    input bit [$bits(dut.io_VGA_verCntr)-1:0] value_io_VGA_verCntr;
    io_VGA_verCntr = value_io_VGA_verCntr;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_verCntr;
  function void getBitsImpl_io_VGA_verCntr;
    output bit [$bits(dut.io_VGA_verCntr)-1:0] value_io_VGA_verCntr;
    value_io_VGA_verCntr = io_VGA_verCntr;
  endfunction

  // Port 18: io_VGA_horCntr
  export "DPI-C" function getBitWidthImpl_io_VGA_horCntr;
  function void getBitWidthImpl_io_VGA_horCntr;
    output int value;
    value = $bits(dut.io_VGA_horCntr);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_horCntr;
  function void setBitsImpl_io_VGA_horCntr;
    input bit [$bits(dut.io_VGA_horCntr)-1:0] value_io_VGA_horCntr;
    io_VGA_horCntr = value_io_VGA_horCntr;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_horCntr;
  function void getBitsImpl_io_VGA_horCntr;
    output bit [$bits(dut.io_VGA_horCntr)-1:0] value_io_VGA_horCntr;
    value_io_VGA_horCntr = io_VGA_horCntr;
  endfunction

  // Port 19: io_VGA_B
  export "DPI-C" function getBitWidthImpl_io_VGA_B;
  function void getBitWidthImpl_io_VGA_B;
    output int value;
    value = $bits(dut.io_VGA_B);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_B;
  function void setBitsImpl_io_VGA_B;
    input bit [$bits(dut.io_VGA_B)-1:0] value_io_VGA_B;
    io_VGA_B = value_io_VGA_B;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_B;
  function void getBitsImpl_io_VGA_B;
    output bit [$bits(dut.io_VGA_B)-1:0] value_io_VGA_B;
    value_io_VGA_B = io_VGA_B;
  endfunction

  // Port 1a: io_VGA_G
  export "DPI-C" function getBitWidthImpl_io_VGA_G;
  function void getBitWidthImpl_io_VGA_G;
    output int value;
    value = $bits(dut.io_VGA_G);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_G;
  function void setBitsImpl_io_VGA_G;
    input bit [$bits(dut.io_VGA_G)-1:0] value_io_VGA_G;
    io_VGA_G = value_io_VGA_G;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_G;
  function void getBitsImpl_io_VGA_G;
    output bit [$bits(dut.io_VGA_G)-1:0] value_io_VGA_G;
    value_io_VGA_G = io_VGA_G;
  endfunction

  // Port 1b: io_VGA_R
  export "DPI-C" function getBitWidthImpl_io_VGA_R;
  function void getBitWidthImpl_io_VGA_R;
    output int value;
    value = $bits(dut.io_VGA_R);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_R;
  function void setBitsImpl_io_VGA_R;
    input bit [$bits(dut.io_VGA_R)-1:0] value_io_VGA_R;
    io_VGA_R = value_io_VGA_R;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_R;
  function void getBitsImpl_io_VGA_R;
    output bit [$bits(dut.io_VGA_R)-1:0] value_io_VGA_R;
    value_io_VGA_R = io_VGA_R;
  endfunction

  // Port 1c: io_VGA_vSync
  export "DPI-C" function getBitWidthImpl_io_VGA_vSync;
  function void getBitWidthImpl_io_VGA_vSync;
    output int value;
    value = $bits(dut.io_VGA_vSync);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_vSync;
  function void setBitsImpl_io_VGA_vSync;
    input bit [$bits(dut.io_VGA_vSync)-1:0] value_io_VGA_vSync;
    io_VGA_vSync = value_io_VGA_vSync;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_vSync;
  function void getBitsImpl_io_VGA_vSync;
    output bit [$bits(dut.io_VGA_vSync)-1:0] value_io_VGA_vSync;
    value_io_VGA_vSync = io_VGA_vSync;
  endfunction

  // Port 1d: io_VGA_hSync
  export "DPI-C" function getBitWidthImpl_io_VGA_hSync;
  function void getBitWidthImpl_io_VGA_hSync;
    output int value;
    value = $bits(dut.io_VGA_hSync);
  endfunction
  export "DPI-C" function setBitsImpl_io_VGA_hSync;
  function void setBitsImpl_io_VGA_hSync;
    input bit [$bits(dut.io_VGA_hSync)-1:0] value_io_VGA_hSync;
    io_VGA_hSync = value_io_VGA_hSync;
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_hSync;
  function void getBitsImpl_io_VGA_hSync;
    output bit [$bits(dut.io_VGA_hSync)-1:0] value_io_VGA_hSync;
    value_io_VGA_hSync = io_VGA_hSync;
  endfunction

  // Port 1e: io_VGA_RGB
  export "DPI-C" function getBitWidthImpl_io_VGA_RGB;
  function void getBitWidthImpl_io_VGA_RGB;
    output int value;
    value = $bits(dut.io_VGA_RGB);
  endfunction
  export "DPI-C" function getBitsImpl_io_VGA_RGB;
  function void getBitsImpl_io_VGA_RGB;
    output bit [$bits(dut.io_VGA_RGB)-1:0] value_io_VGA_RGB;
    value_io_VGA_RGB = io_VGA_RGB;
  endfunction

  // Simulation
  import "DPI-C" context task simulation_body();
  enum {INIT, RUN, DONE} simulationState = INIT;
  initial
    simulationState = RUN;
  always @(simulationState) begin
    if (simulationState == RUN) begin
      simulation_body();
      simulationState = DONE;
    end
  end
  import "DPI-C" context task simulation_final();
  final
    simulation_final();
  `ifdef SVSIM_BACKEND_SUPPORTS_DELAY_IN_PUBLIC_FUNCTIONS
  export "DPI-C" task run_simulation;
  task run_simulation;
    input int timesteps;
    output int finish;
    #(timesteps*0.1);
    finish = 0;
  endtask
  `else
  import "DPI-C" function void run_simulation(input int timesteps, output int done);
  `endif

  // Tracing
  int traceSupported = 0;
  export "DPI-C" function simulation_initializeTrace;
  function void simulation_initializeTrace;
    input string traceFilePath;
    `ifdef SVSIM_ENABLE_FST_TRACING_SUPPORT
      $dumpfile({traceFilePath,".fst"});
      $dumpvars(0, dut);
      traceSupported = 1;
    `elsif SVSIM_ENABLE_VCD_TRACING_SUPPORT
      $dumpfile({traceFilePath,".vcd"});
      $dumpvars(0, dut);
      traceSupported = 1;
    `endif
    `ifdef SVSIM_ENABLE_VPD_TRACING_SUPPORT
      $vcdplusfile({traceFilePath,".vpd"});
      $dumpvars(0, dut);
      $vcdpluson(0, dut);
      traceSupported = 1;
    `endif
    `ifdef SVSIM_ENABLE_FSDB_TRACING_SUPPORT
      $fsdbDumpfile({traceFilePath,".fsdb"});
      $fsdbDumpvars(0, dut, "+all");
      traceSupported = 1;
    `endif
  endfunction
  export "DPI-C" function simulation_enableTrace;
  function void simulation_enableTrace;
    output int success;
    success = traceSupported;
    `ifdef SVSIM_ENABLE_VCD_TRACING_SUPPORT
    $dumpon;
    `elsif SVSIM_ENABLE_FST_TRACING_SUPPORT
    $dumpon;
    `elsif SVSIM_ENABLE_VPD_TRACING_SUPPORT
    $dumpon;
    `endif
    `ifdef SVSIM_ENABLE_FSDB_TRACING_SUPPORT
    $fsdbDumpon;
    `endif
  endfunction
  export "DPI-C" function simulation_disableTrace;
  function void simulation_disableTrace;
    output int success;
    success = traceSupported;
    `ifdef SVSIM_ENABLE_VCD_TRACING_SUPPORT
    $dumpoff;
    `elsif SVSIM_ENABLE_FST_TRACING_SUPPORT
    $dumpoff;
    `elsif SVSIM_ENABLE_VPD_TRACING_SUPPORT
    $dumpoff;
    `endif
    `ifdef SVSIM_ENABLE_FSDB_TRACING_SUPPORT
    $fsdbDumpoff;
    `endif
  endfunction

endmodule
