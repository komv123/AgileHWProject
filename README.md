# Real time mandelbrot visualization

## Introduction

This project aims to develop a general purpose visualizer, that outputs image thorugh a VGA port.
The first milestone is to create a Mandelbrot fractial visualizer, with modular compute units.
The hardware is described in Chisel and implemented on FPGA.

## Setup
This project uses the [Nix](https://github.com/NixOS/nix) package manager.
You can use the Flake provided in this repository to install all dependencies in a development environment:
```shell
nix develop
```
If you also want the synthesis tools in your development environment you can those the openxc7 shell instead:

```shell
nix develop .#openxc7
```

## Configuration file
You can configure the repository to match what you want to do.
Create a file in the root of the repository called `config.mk`.
Here is an example of how it can look:
```make
MILL = ./mill # Use another install of mill
SYNTH_TOOL = openxc7 # can be either openxc7 or f4pga

# Set the top module for verilog generation
TOP_MODULE = Visualizer

# Set the FPGA target
FAMILY  = artix7
PART    = xc7a35tcpg236-1
BOARD   = basys3
```

## Testing
Open a terminal in the directory and run:
```bash
mill _.test
```
This will run all the tests.

You can also see which test are available by running:
```bash
mill resolve _.test
```
You can then run a specific test with:

```bash
mill Visualizer.test
```
This specific test and some other tests generate a visual output which you can see here:
```bash
open out/Visualizer/test/test.dest/sandbox/frame-0.png
```

## Synthesis
This repository contains supports two different open-source synthesis flows for generating bitstreams for an FPGA.
The one provided in the developement environment is called openXC7 and works very well but supports only a few FPGAs.
The other one is F4PGA which is tedious to work with and has to be manually installed but it supports a larger set FPGAs.
This README contains a [section](#installing-f4pga) on how to install the F4PGA tools.
You can set the synthesis tool in the `config.mk` file and then run.

## Generating SystemVerilog from Chisel
Right now most synthesis tools only accepts less abstract HDLs like SystemVerilog.
This means the Chisel code needs to be converted to SystemVerilog representation in order to synthesize it.
This can be done with the command:

```shell
make rtl
```

This will create a directory called ```rtl/``` where the SystemVerilog files are located.

## Synthesizing the design
Right now, this repository supports [Basys3](https://digilent.com/reference/programmable-logic/basys-3/reference-manual) and [Nexys A7](https://digilent.com/reference/programmable-logic/nexys-a7/start) board.
To synthsize the design just run following command:

```shell
make synth
```

This will create the directory ```synth/build/<target-fpga>``` with a bitstream among other files.

## Programming the FPGA
The build directory contains a lot of files but the most interesting one is the ```Visualizer.bit``` which is the bitstream file.
This is the file that is used programmed to the FPGA when it is programmed.
To program the FPGA plug in your FPGA via USB and run following command:

```shell
make program
```

If you encounter problems you try running it as root or see [Troubleshooting](#troubleshooting) if you prefer not to run random programs as root.

## Installing F4PGA
In order to synthesize with [F4PGA](https://f4pga.org/) it needs to be installed.
This reposistory can install the tools automatically since these cannot be managed with Nix.
First set the synthesis tool `SYNTH_TOOL = f4pga` in `config.mk`.
To install the tool run:

```shell
make install
```

This will create the directory ```synth/f4pga/tools``` and ```synth/f4pga/f4pga-examples``` which contains all the neccessary tools.
The tools only needs to be installed once.
If you already have the tools installed see [Tips](#Tools)

## Tips
### Tools
The tools take up rougly 6GB of storage so you might be interested in deleting them.
If you ever want to delete the tools just run:

```shell
make uninstall
```

### Makefile
The Makefile is written such that dependencies are resolved.
This means if you made a change to the Chisel code and want to reprogram your FPGA you can just run:

```shell
make program
```

Which will automatically generate SystemVerilog which will then be synthesized to a bitstream file that will be programmed to the FGPA.
You do not need to manually run the whole chain of commands showed earlier.

## Troubleshooting
### Error: unable to open ftdi device
Check that your device is properly plugged in and shows up when you run the ```lsusb``` command.
If the device shows up the problem is most likely permission issues for USB devices.
On some Linux distrubutions normal users does not get permissions to USB devices by default.
Trying to program an FPGA will result in an error since it is via USB.
To fix this run the commands:
```shell
sudo bash -c 'echo ATTRS{idVendor}==\"0403\", ATTRS{idProduct}==\"6010\", MODE=\"666\", TAG+=\"uaccess\" > /etc/udev/rules.d/99-ftdi.rules'
sudo udevadm control --reload-rules && sudo udevadm trigger
```
You might need to change the ```idVendor``` and ```idProduct``` to another ID.
You can get these from running ```lsusb``` while your FPGA board is plugged in.
My Basys 3 board looks like this:

```plain
Bus 001 Device 004: ID 0403:6010 Future Technology Devices International, Ltd FT2232C/D/H Dual UART/FIFO IC
```
