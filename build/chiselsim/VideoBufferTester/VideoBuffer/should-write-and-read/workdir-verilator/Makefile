# This Makefile enables lightweight debugging of `svsim` tests. 
# To rebuild the simulation run `make simulation` in this directory.
# To replay the simulation run `make replay` in this directory.
# Changes to `generated-sources` and `primary-sources` will be picked up when running `make replay` and `make simulation`. This is useful for debugging issues. You can also freely add, remove or change any of the arguments to the backend or simulation in the targets below.

.PHONY: clean simulation replay

clean:
	ls . | grep -v Makefile | grep -v execution-script.txt | xargs rm -rf

simulation: clean
	$(compilerEnvironment) \
	/nix/store/v2xlfkkfcffyz1vp0q7sg799ca2i0qqg-verilator-5.034/bin/verilator \
		'--cc' \
		'--exe' \
		'--build' \
		'-o' \
		'../simulation' \
		'--top-module' \
		'svsimTestbench' \
		'--Mdir' \
		'verilated-sources' \
		'--assert' \
		'-j' \
		'0' \
		'+incdir+/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/verification/assume' \
		'+incdir+/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/verification/assert' \
		'+incdir+/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/verification/cover' \
		'+incdir+/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources/verification' \
		'+incdir+/app/build/chiselsim/VideoBufferTester/VideoBuffer/should-write-and-read/primary-sources' \
		'--timescale' \
		'1ns/100ps' \
		'-CFLAGS' \
		'-std=c++17 -I$(shell pwd) -DSVSIM_ENABLE_VERILATOR_SUPPORT' \
		'+define+ASSERT_VERBOSE_COND=!svsimTestbench.reset' \
		'+define+PRINTF_COND=!svsimTestbench.reset' \
		'+define+STOP_COND=!svsimTestbench.reset' \
		'+define+layer$$Verification$$Assert$$Temporal' \
		'+define+layer$$Verification$$Assume$$Temporal' \
		'+define+layer$$Verification$$Cover$$Temporal' \
		'+define+RANDOMIZE_REG_INIT' \
		'+define+RANDOMIZE_MEM_INIT' \
		'+define+RANDOMIZE_DELAY=1' \
		'+define+RANDOM=$$urandom' \
		$(sourcefiles)

replay: simulation
	cat $(shell pwd)/execution-script.txt | { grep '^#' || true; } && \
	cat $(shell pwd)/execution-script.txt | sed -n 's/^[0-9]*> \(.*\)/\1/p' | \
		$(simulationEnvironment) $(shell pwd)/simulation \

sourcefiles = \
	'../primary-sources/VideoBuffer.sv' \
	'../primary-sources/verification/assume/layers-VideoBuffer-Verification-Assume.sv' \
	'../primary-sources/verification/layers-VideoBuffer-Verification.sv' \
	'../primary-sources/verification/assert/layers-VideoBuffer-Verification-Assert.sv' \
	'../primary-sources/verification/cover/layers-VideoBuffer-Verification-Cover.sv' \
	'../primary-sources/DualPortRAM.sv' \
	'../primary-sources/mem_1028x12.sv' \
	'../generated-sources/testbench.sv' \
	'../generated-sources/c-dpi-bridge.cpp' \
	'../generated-sources/simulation-driver.cpp'

compilerEnvironment = \

simulationEnvironment = \
	SVSIM_SIMULATION_LOG=$(shell pwd)/simulation-log.txt \
	SVSIM_SIMULATION_TRACE=trace

