# Include user-specific configuration
-include config.mk

# Tools
MILL        = ./mill

MILL_FLAGS = --no-server

# Directories
SYNTHDIR    = $(CURDIR)/synth
F4PGADIR    = $(CURDIR)/f4pga

# F4PGA Paths
F4PGA_INSTALL_DIR  ?= $(CURDIR)/f4pga/tools
F4PGA_EXAMPLES_DIR ?= $(CURDIR)/f4pga/f4pga-examples

# --- Primary Targets ---

# Default target
.PHONY: all
all: synth

# Generate SystemVerilog using the mill command from config.mk
.PHONY: rtl
rtl:
	@echo "+++ Generating Verilog using mill..."
	$(MILL) $(MILL_FLAGS) $(MILL_TARGET)

# Synthesize the design using F4PGA
# Depends on the Verilog file being generated first.
.PHONY: synth
synth: rtl
	@echo "+++ Synthesizing for $(BOARD) board..."
	$(MAKE) -C $(SYNTHDIR) synth BOARD=$(BOARD) TOPMOD=$(TOPMOD) RTLDIR=$(RTLDIR) F4PGA_INSTALL_DIR=$(F4PGA_INSTALL_DIR) F4PGA_EXAMPLES_DIR=$(F4PGA_EXAMPLES_DIR)

# Program the FPGA
# Depends on the bitstream from the synth step.
.PHONY: program
program:
	@echo "+++ Programming $(BOARD) board..."
	$(MAKE) -C $(SYNTHDIR) program BOARD=$(BOARD) TOPMOD=$(TOPMOD) F4PGA_INSTALL_DIR=$(F4PGA_INSTALL_DIR) F4PGA_EXAMPLES_DIR=$(F4PGA_EXAMPLES_DIR)

# --- Toolchain and Cleanup ---

# Install F4PGA synthesis tools
.PHONY: install
install:
	cd $(F4PGADIR) && ./install.sh

# Uninstall F4PGA synthesis tools
.PHONY: uninstall
uninstall:
	$(RM) -rf $(F4PGA_INSTALL_DIR) $(F4PGA_EXAMPLES_DIR)

# Cleanup working directory
.PHONY: clean
clean:
	@echo "+++ Cleaning workspace..."
	$(RM) -rf test_run_dir/ target/ project/target project/project out/
	$(MAKE) -C $(SYNTHDIR) BOARD=$(BOARD) F4PGA_EXAMPLES_DIR=$(F4PGA_EXAMPLES_DIR) clean

# For debugging Makefile variables from config.mk
.PHONY: show
show:
	@echo '--- Variables from config.mk ---'
	@echo 'BOARD       :' $(BOARD)
	@echo 'TOPMOD      :' $(TOPMOD)
	@echo 'RTLDIR      :' $(RTLDIR)
	@echo 'RTLFILE     :' $(RTLFILE)
	@echo 'MILL_TARGET :' $(MILL_TARGET)
	@echo '--------------------------------'
	@echo 'F4PGA_INSTALL_DIR  :' $(F4PGA_INSTALL_DIR)
	@echo 'F4PGA_EXAMPLES_DIR :' $(F4PGA_EXAMPLES_DIR)