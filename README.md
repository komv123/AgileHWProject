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
