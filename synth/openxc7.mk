# Default target board
FAMILY  ?= artix7
PART    ?= xc7a35tcpg236-1
BOARD   ?= basys3

DBPART = $(shell echo ${PART} | sed -e 's/-[0-9]//g')
SPEEDGRADE = $(shell echo ${PART} | sed -e 's/.*\-\([0-9]\)/\1/g')

BOARDDIR ?= $(SYNTHDIR)/boards
SYNTHBUILDDIR ?= $(SYNTHDIR)/build
CHIPDB ?= $(SYNTHDIR)/chipdb

PYPY3 ?= pypy3

# Check with openFPGALoader --list-boards
BOARD ?= UNKNOWN
JTAG_LINK ?= --board ${BOARD}

XDC ?= ${BOARDDIR}/${BOARD}.xdc

.PHONY: all
synth: $(SYNTHBUILDDIR)/${TOP_MODULE}.bit

.PHONY: program
program: $(SYNTHBUILDDIR)/${TOP_MODULE}.bit
	openFPGALoader ${JTAG_LINK} --bitstream $<

$(SYNTHBUILDDIR)/${TOP_MODULE}.json: $(RTL_SOURCES)
	mkdir -p $(SYNTHBUILDDIR)
	yosys -p "synth_xilinx -flatten  -abc9 ${SYNTH_OPTS} -arch xc7 -top ${TOP_MODULE}; write_json -noscopeinfo $(SYNTHBUILDDIR)/${TOP_MODULE}.json" ${RTL_SOURCES}

${CHIPDB}/${DBPART}.bin:
	mkdir -p ${CHIPDB}
	${PYPY3} ${NEXTPNR_XILINX_PYTHON_DIR}/bbaexport.py --device ${PART} --bba ${DBPART}.bba
	bbasm -l ${DBPART}.bba ${CHIPDB}/${DBPART}.bin
	rm -f ${DBPART}.bba

$(SYNTHBUILDDIR)/${TOP_MODULE}.fasm: $(SYNTHBUILDDIR)/${TOP_MODULE}.json ${CHIPDB}/${DBPART}.bin ${XDC}
	nextpnr-xilinx --chipdb ${CHIPDB}/${DBPART}.bin --xdc ${XDC} --json $(SYNTHBUILDDIR)/${TOP_MODULE}.json --fasm $@ ${PNR_ARGS}
	
$(SYNTHBUILDDIR)/${TOP_MODULE}.frames: $(SYNTHBUILDDIR)/${TOP_MODULE}.fasm
	fasm2frames --part ${PART} --db-root ${PRJXRAY_DB_DIR}/${FAMILY} $< > $@

$(SYNTHBUILDDIR)/${TOP_MODULE}.bit: $(SYNTHBUILDDIR)/${TOP_MODULE}.frames
	xc7frames2bit --part_file ${PRJXRAY_DB_DIR}/${FAMILY}/${PART}/part.yaml --part_name ${PART} --frm_file $< --output_file $@
