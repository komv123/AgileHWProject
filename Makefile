-include config.mk

# Tools
MILL        = mill
MILL_FLAGS  = --no-server
SYNTH_TOOL  ?= openxc7

# Directories
RTLDIR      = $(CURDIR)/rtl
BUILDDIR    = $(CURDIR)/build
OUTDIR      = $(CURDIR)/out
SYNTHDIR    = $(CURDIR)/synth

# Default targets
TOP_MODULE ?= Visualizer
MILL_TARGET ?= ${TOP_MODULE}.run

RTL_SOURCES = $(wildcard $(RTLDIR)/*.sv)

.PHONY: all
all: rtl

# Generate SystemVerilog
.PHONY: rtl
rtl: $(RTLDIR)/$(TOP_MODULE).sv
$(RTLDIR)/$(TOP_MODULE).sv:
	@echo "+++ Generating Verilog..."
	$(MILL) $(MILL_FLAGS) $(MILL_TARGET)

# Run all tests
.PHONY: test
test:
	@echo "+++ Running tests..."
	$(MILL) _.test

# Cleanup working directory
.PHONY: clean
clean:
	@echo "+++ Cleaning workspace..."
	$(RM) -rf $(RTLDIR) $(BUILDDIR) $(OUTDIR)

-include $(SYNTHDIR)/$(SYNTH_TOOL).mk

# For debugging Makefile variables from config.mk
.PHONY: show
show:
	@echo '--- Variables from config.mk ---'
	@echo 'TOP_MODULE  :' $(TOP_MODULE)
	@echo 'MILL_TARGET :' $(MILL_TARGET)
	@echo 'RTLDIR      :' $(RTLDIR)
	@echo 'BUILDDIR    :' $(BUILDDIR)
	@echo 'OUTDIR      :' $(OUTDIR)
	@echo 'SYNTHDIR    :' $(SYNTHDIR)
	@echo 'RTL_SOURCES :' $(RTL_SOURCES)
