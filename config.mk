# name of the target FPGA board
BOARD = nexys-a7-100t

# name of the top-level Chisel module
TOPMOD = Visualizer

# directory where mill will output the Verilog file
RTLDIR = $(CURDIR)/rtl

# defines the final name of the SystemVerilog file
RTLFILELIST = $(shell cat $(RTLDIR)/filelist.f)

# mill command to generate the SystemVerilog file.
# This command tells mill to run the generator's Main function.
# !!! need to replace 'AgileHWProject.MandelbrotGenerator' with the actual Main object !!!
MILL_TARGET = Visualizer.run
