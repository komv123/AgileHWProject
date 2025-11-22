# Real-time visualization - 02201 Agile HW Design

## Group 4

- Adam (s215236)
- Karl (s203852)
- Filippo (s250237)
- William (s204740)
- Rumle (s200621)

## Introduction

This project aims to develop a general purpose visualizer, that outputs image thorugh a VGA port. The first milestone is to create a Mandelbrot fractial visualizer, with modular compute units. Then modify the hardware for general purpose visualizations. The hardware is described in Chisel and implemented on FPGA.

## Goals

Features:

- Render Mandelbrot set at 640×480 resolution
- Zoom in/out functionality
- Optional: support other fractals/algorithms (Julia set, Game of Life)

Implementation:

- VGA test pattern
- Single CU Mandelbrot computation
- Parallel CUs for full frame
- Zoom logic & user input

Verification:

- Compare output with reference Mandelbrot images
- Simulation + FPGA testbench

Maintenance:

- Extend with new algorithms (Julia set, Game of Life)
- Improve performance (coloring, deeper zoom)

## Setup
This project uses the [Nix](https://github.com/NixOS/nix) package manager. You can use the Flake provided in this repository to install all dependencies in a development environment:
```shell
nix develop
```

For first-time run, open a terminal in the folder where this project is cloned and run:
```bash
./mill _.test
```

_JVM_ and _Verilator_ should be installed to be able to run the tests. Mill is a local script that downloads a local binary for the build tool.

This only works on POSIX compliant systems, so for windows, a global installation of mill is needed

## Installing tools for F4PGA

The synthesis this is done with [F4PGA](https://f4pga.org/) which needs to be installed.
This reposistory can install the tools automatically.
To install the tool run:

```shell
make install
```

This will create the directory ```f4pga/tools``` and ```f4pga/f4pga-examples``` which contains all the neccessary tools.
The tools only needs to be installed once.
If you already have the tools installed see [Tips](#Tools)

## Checks before running the code
For now the top module is set to be ```Visualizer/Visualizer.scala``` for testing the workflow because we still don't have a VGA top module. It can be later changed in the ```config.mk``` file:

```shell
TOPMOD = NewTop
MILL_TARGET = AgileHWProject.runMain NewTopMain
```
The new top scala module will have to have:

- A Chisel module class set like:

```scala
class NewTop extends Module {
  val io = IO(new Bundle {
    ...
  })
}
```

- A main object that emits SystemVerilog like:

```scala
object NewTopMain extends App {
  ChiselStage.emitSystemVerilogFile(
    new NewTop,
    args = Array("--target-dir", "rtl"),
    firtoolOpts = Array("--lowering-options=disallowLocalVariables,disallowPackedArrays")
  )
}
```


## Generating SystemVerilog from Chisel
Right now most synthesis tools only accepts less abstract HDLs like SystemVerilog.
This means the Chisel code needs to be converted to SystemVerilog representation in order to synthesize it.
This can be done with the command:

```shell
make rtl
```

This will create a directory called ```rtl/``` where the SystemVerilog files are located.


## Synthesizing the design
Right now, this repository only supports the [Nexys A7](https://digilent.com/reference/programmable-logic/nexys-a7/start) board.
So it not strictly neccessary to make the configuration file as the project defaults to Nexys A7.
To synthsize the design just run following command:

```shell
make synth
```

This will create the directory ```synth/build/nexys-a7-100t/```.

## Programming the FPGA
The build directory contains a lot of files but the most interesting one is the ```<TopModule>.bit``` which is the bitstream file.
This is the file that is used programmed to the FPGA when it is programmed.
To program the FPGA plug in your FPGA via USB and run following command:

```shell
make program
```

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