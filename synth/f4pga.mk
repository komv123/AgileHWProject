THIS_FILE := $(firstword $(MAKEFILE_LIST))

current_dir := ${SYNTHDIR}
TOP         := $(TOP_MODULE)
SOURCES     := $(RTL_SOURCES)

# Artix-7 Nexys A7-100T device triplet
TARGET    ?= arty_100
BOARD     ?= nexys_a7_100
DEVICE    ?= xc7a100t
PACKAGE   ?= csg324
SPEED     ?= -1
PART      ?= xc7a100t-1csg324
FPGA_FAM  ?= xc7

BOARDDIR ?= $(SYNTHDIR)/boards
SYNTHBUILDDIR ?= $(SYNTHDIR)/build

XDC := ${BOARDDIR}/${BOARD}.xdc

# F4PGA stuff
F4PGA_INSTALL_DIR  := $(SYNTHDIR)/f4pga/tools
F4PGA_EXAMPLES_DIR := $(SYNTHDIR)/f4pga/f4pga-examples
F4PGA_TIMESTAMP    := "20220920-124259"
F4PGA_HASH         := "007d1c1"

.ONESHELL:
SHELL = bash

# Synthsize design
.PHONY: synth
synth:
	export FPGA_FAM=$(FPGA_FAM)
	export F4PGA_INSTALL_DIR=$(F4PGA_INSTALL_DIR)
	source "${F4PGA_INSTALL_DIR}/${FPGA_FAM}/conda/etc/profile.d/conda.sh"
	conda activate $(FPGA_FAM)
	$(MAKE) -f $(THIS_FILE) all

# Program FPGA
.PHONY: program
program:
	export FPGA_FAM=$(FPGA_FAM)
	export F4PGA_INSTALL_DIR=$(F4PGA_INSTALL_DIR)
	source "${F4PGA_INSTALL_DIR}/${FPGA_FAM}/conda/etc/profile.d/conda.sh"
	conda activate $(FPGA_FAM)
	$(MAKE) -f $(THIS_FILE) download

# Install F4PGA synthesis tools
.PHONY: install
install:
	git clone "https://github.com/chipsalliance/f4pga-examples" ${F4PGA_EXAMPLES_DIR}
	curl -L https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh -o conda_installer.sh
	bash conda_installer.sh -u -b -p "${F4PGA_INSTALL_DIR}/${FPGA_FAM}/conda"
	$(RM) conda_installer.sh
	source "${F4PGA_INSTALL_DIR}/${FPGA_FAM}/conda/etc/profile.d/conda.sh"
	conda env create -f ${F4PGA_EXAMPLES_DIR}/$(FPGA_FAM)/environment.yml
	conda env update -f ${F4PGA_EXAMPLES_DIR}/$(FPGA_FAM)/environment.yml
	mkdir -p $(F4PGA_INSTALL_DIR)/$(FPGA_FAM)
	wget -qO- https://storage.googleapis.com/symbiflow-arch-defs/artifacts/prod/foss-fpga-tools/symbiflow-arch-defs/continuous/install/${F4PGA_TIMESTAMP}/symbiflow-arch-defs-install-xc7-${F4PGA_HASH}.tar.xz | tar -xJC $(F4PGA_INSTALL_DIR)/$(FPGA_FAM)
	wget -qO- https://storage.googleapis.com/symbiflow-arch-defs/artifacts/prod/foss-fpga-tools/symbiflow-arch-defs/continuous/install/${F4PGA_TIMESTAMP}/symbiflow-arch-defs-xc7a100t_test-${F4PGA_HASH}.tar.xz | tar -xJC $(F4PGA_INSTALL_DIR)/$(FPGA_FAM)

# Uninstall F4PGA synthesis tools
.PHONY: uninstall
uninstall:
	$(RM) -rf $(F4PGA_INSTALL_DIR) $(F4PGA_EXAMPLES_DIR)

-include ${F4PGA_EXAMPLES_DIR}/common/common.mk
