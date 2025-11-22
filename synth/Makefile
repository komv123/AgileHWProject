-include boards/nexys-a7-100t.mk

THIS_FILE := $(firstword $(MAKEFILE_LIST))

TARGET      := $(BOARD)
FPGA_FAM    := xc7
current_dir := ${CURDIR}
XDC         := ${CURDIR}/boards/Nexys-A7-100T-Master.xdc
TOP         := $(TOPMOD)

SOURCES     := $(wildcard $(RTLDIR)/*.sv)

PART = xc7a100t-1csg324

.ONESHELL:
SHELL = bash

.PHONY: synth
synth:
	export FPGA_FAM=$(FPGA_FAM)
	export F4PGA_INSTALL_DIR=$(F4PGA_INSTALL_DIR)
	source "${F4PGA_INSTALL_DIR}/${FPGA_FAM}/conda/etc/profile.d/conda.sh"
	conda activate $(FPGA_FAM)
	$(MAKE) -f $(THIS_FILE) all


.PHONY: program
program:
	export FPGA_FAM=$(FPGA_FAM)
	export F4PGA_INSTALL_DIR=$(F4PGA_INSTALL_DIR)
	source "${F4PGA_INSTALL_DIR}/${FPGA_FAM}/conda/etc/profile.d/conda.sh"
	conda activate $(FPGA_FAM)
	$(MAKE) -f $(THIS_FILE) download

# Artix-7 Nexys A7-100T device triplet
DEVICE  := xc7a100t
PACKAGE := csg324
SPEED   := -1

include ${F4PGA_EXAMPLES_DIR}/common/common.mk
