```
                8888888888 .d88888b.  8888888b. 88888888888 8888888888
                888       d88P" "Y88b 888   Y88b    888     888       
                888       888     888 888    888    888     888       
                8888888   888     888 888   d88P    888     8888888   
                888       888     888 8888888P"     888     888       
                888       888     888 888 T88b      888     888       
                888       Y88b. .d88P 888  T88b     888     888       
                888        "Y88888P"  888   T88b    888     8888888888
                                                                      
                         FRACTAL OTIMIZED REAL TIME ENGINE            
                                                                      
                  ┌───────────────────────────────────────────────┐   
                  │ ┌──────────────────┐    ┌───────────────────┐ │   
                  │ │                  │    │                   │ │   
                  │ │       VGA        ◄────┼   FRAME BUFFER    │ │   
                  │ │    CONTROLLER    │    │                   │ │   
                  │ │                  │    └────────▲──────────┘ │   
                  │ └────────┬─────────┘             │            │   
                  └──────────┼────────────┐ ┌────────┴──────────┐ │   
                             │            │ │                   │ │   
                             │            │ │ MEMORY MANAGEMENT │ │   
                             │            │ │       UNIT        │ │   
                    ┌────────▼─────────┐  │ │                   │ │   
                    │                  │  │ └────────▲──────────┘ │   
                    │     DISPLAY      │  │          │            │   
                    │                  │  │ ┌────────┴──────────┐ │   
                    └──────────────────┘  │ │                   │ │   
                                          │ │     TILELINK      │ │   
                                          │ │       XBAR        │ │   
                                          │ │                   │ │   
                                          │ └─▲───▲───▲───▲───▲─┘ │   
                                          │   │   │   │   │   │   │   
                                          │   │   │   │   │   │   │   
                                          │ ┌─┴───┴───┴───┴───┴─┐ │   
                                          │ │┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐│ │   
                                          │ ││C│ │C│ │C│ │C│ │C││ │   
                                          │ ││U│ │U│ │U│ │U│ │U││ │   
                                          │ │└─┘ └─┘ └─┘ └─┘ └─┘│ │   
                                          │ │┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐│ │   
                                          │ ││C│ │C│ │C│ │C│ │C││ │   
                                          │ ││U│ │U│ │U│ │U│ │U││ │   
                                          │ │└─┘ └─┘ └─┘ └─┘ └─┘│ │   
                                          │ │┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐│ │   
                                          │ ││C│ │C│ │C│ │C│ │C││ │   
                                          │ ││U│ │U│ │U│ │U│ │U││ │   
                                          │ │└─┘ └─┘ └─┘ └─┘ └─┘│ │   
                                          │ └───────────────────┘ │   
                                          └───────────────────────┘   
                
```

This project aims to develop a general-purpose visualizer that outputs images through a VGA port. The primary milestone is to create a hardware-accelerated Mandelbrot fractal visualizer using a modular architecture. The hardware is described in **Chisel** (Scala) and implemented on FPGA.

## Table of Contents
- [Architecture & Module Deep Dive](#architecture--module-deep-dive)
- [Controls](#controls)
- [Setup](#setup)
- [Configuration](#configuration-file)
- [Testing](#testing)
- [Synthesis](#synthesis)
- [Troubleshooting](#troubleshooting)

---

## Architecture & Module Deep Dive

The project is structured into several modular components, each handling a specific part of the visualization pipeline. Below is a detailed technical explanation of each module:

### 1. **Visualizer (Top Level)**
The **Visualizer** is the top-level module that acts as the entry point for the hardware design.
- **Clock Generator**: It manages the distinct clock domains—the high-speed system clock (used for the heavy Mandelbrot computation) and the pixel clock (required for strict VGA timing).
- **IO Mapping**: It instantiates the sub-modules and maps their inputs/outputs to the physical FPGA pins defined in the constraints file (Clock, Reset, VGA HSync/VSync, RGB pins, and Buttons).
- **Input Handling**: It debounces and interprets the button inputs to control the viewport (x, y, zoom) before passing these parameters to the Compute Engine.
- **Integration**: It connects the data pipeline from the `ComputeModule` -> `Pipeline` -> `VideoBuffer` -> `VGA` output.

### 2. **ComputeModule**
This is the mathematical core of the fractal generator.
- **Algorithm**: It implements the iterative Mandelbrot formula: $Z_{n+1} = Z_n^2 + C$.
- **Fixed-Point Arithmetic**: To save FPGA resources compared to floating-point, this module uses high-precision fixed-point math to perform complex number squaring and addition.
- **Parallelism**: Depending on the configuration, multiple compute units can run in parallel to calculate multiple pixels simultaneously, ensuring the hardware keeps up with the video stream.

### 3. **Pipeline**
The **Pipeline** module orchestrates the flow of data through the system.
- **Coordinate Generation**: It generates a stream of $(x, y)$ screen coordinates and maps them to the complex plane $(Cr, Ci)$ based on the current zoom level and offset provided by the top-level controller.
- **Back-pressure Handling**: It implements `Decoupled` interfaces (Ready-Valid handshakes) to manage data flow. If the `VideoBuffer` is full, it pauses the compute units; if the buffer is empty, it signals that pixels are not ready. This ensures no data is dropped even if the computation takes variable time per pixel.

### 4. **VGA**
The **VGA** module is the display controller responsible for driving the monitor.
- **Timing Generation**: It consists of counters that generate the standard VESA timing signals (Front Porch, Sync Pulse, Back Porch, Active Video) for the target resolution of 640x480.
- **Pixel Requesting**: As the "beam" moves across the screen, it sends read requests to the `VideoBuffer` to fetch the color data for the current pixel.
- **Signal Output**: It drives the physical DAC pins (Red, Green, Blue) and the synchronization signals (HSync, VSync).

### 5. **VideoBuffer**
The **VideoBuffer** serves as a specialized FIFO (First-In-First-Out) or line buffer between the compute logic and the display logic.
- **Domain Decoupling**: Since Mandelbrot calculations take a variable amount of time (some pixels finish in 1 cycle, others take 100+), and the VGA display requires a constant pixel rate, this buffer absorbs the jitter.
- **Dual-Port Memory**: It typically uses Block RAM (BRAM) to allow the Compute module to write results at one speed while the VGA module reads them at the pixel clock speed.

### 6. **MMU (Memory Management Unit)**
The **MMU** handles data storage when the image is too large to fit entirely in the on-chip Line Buffer.
- **Interface**: It acts as the bridge between the internal processing pipeline and larger memory storage (potentially external RAM or larger BRAM blocks).
- **Caching**: It helps manage read/write operations to ensure that the visualization remains smooth, preventing screen tearing or artifacts when the compute units fall behind.

### 7. **Common**
This directory serves as a library for shared logic across the project.
- **Global Constants**: Defines system-wide parameters like screen resolution (`640x480`), color depth (`RGB565`), and fixed-point bit width.
- **Custom Bundles**: Contains Chisel `Bundles` that define the standardized interfaces used to connect modules (e.g., `PixelData`, `ComplexNumber`).

### 8. **c_model**
A software reference implementation written in C.
- **Golden Reference**: This is used to verify the hardware. The output of the hardware simulation can be compared pixel-by-pixel against this C model to ensure the Mandelbrot math is strictly correct.

### 9. **synth**
Contains the build scripts and makefiles for the physical synthesis tools (`OpenXC7` or `F4PGA`). It manages the translation of the generated Verilog into the bitstream that programs the FPGA board.

---

## Controls

The Mandelbrot set navigation is handled via the physical buttons on the board.

| Button | Action |
| :--- | :--- |
| **BTNU** | Move Up (Y-axis) |
| **BTND** | Move Down (Y-axis) |
| **BTNL** | Move Left (X-axis) |
| **BTNR** | Move Right (X-axis) |
| **BTNC + BTNU** | **Zoom In** |
| **BTNC + BTND** | **Zoom Out** |

*Note: You must hold the Center button (BTNC) while pressing Up or Down to trigger the zoom function.*

---

## Setup

You can set up the development environment using **Nix** (recommended) or by manually installing dependencies and using the provided `mill` script.

### Option 1: Using Nix (Recommended)
This project uses the [Nix](https://github.com/NixOS/nix) package manager. This guarantees that all tools (Mill, Verilator, Synthesis tools) are installed with the correct versions.

To enter the development environment:
```bash
nix develop
```

If you want the **synthesis tools** (OpenXC7) included in your environment:
```bash
nix develop .#openxc7
```

### Option 2: Manual Installation (Using `./mill`)
If you do not use Nix, you must ensure the following dependencies are installed on your system:

**Prerequisites:**
1.  **Java Development Kit (JDK)**: Version 11 or 17 is recommended.
2.  **Make**: Required for running build scripts.
3.  **Verilator**: Required for running hardware simulations.
4.  **GTKWave** (Optional): Useful for viewing simulation waveforms.

Once dependencies are installed, you can use the `mill` script included in the root of this repository to run tasks. You may need to make it executable first:
```bash
chmod +x mill
./mill --version
```

*Note: For synthesis, you will also need to manually install Vivado, F4PGA, or OpenXC7 if you are not using the Nix environment.*

---

## Configuration file
You can configure the repository to match what you want to do.
Create a file in the root of the repository called `config.mk`.

For the **Nexys A7 100T Board**, your configuration should look like this:

```makefile
MILL = ./mill # or "mill" if using Nix
SYNTH_TOOL = f4pga # or "openxc7" if installed

# Set the top module for verilog generation
TOP_MODULE = Visualizer

# Set the FPGA target for Nexys A7 100T
BOARD = arty_100
```

## Testing
Open a terminal in the directory and run:
```bash
mill _.test
```
This will run all the tests.

You can also see which tests are available by running:
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
This repository supports two different open-source synthesis flows for generating bitstreams for an FPGA.
- **openXC7**: Provided in the Nix development environment. Works very well but supports only a few FPGAs.
- **F4PGA**: Supports a larger set of FPGAs but is more tedious to install.

You can set the synthesis tool in the `config.mk` file.
### Installing F4PGA
In order to synthesize with [F4PGA](https://f4pga.org/) it needs to be installed.
First set the synthesis tool `SYNTH_TOOL = f4pga` in `config.mk`.
To install the tool run:
```bash
make install
```
This will create the directory `synth/f4pga/tools` and `synth/f4pga/f4pga-examples`.

F4PGA take up roughly 6GB of storage. If you ever want to delete the tools just run:
```bash
make uninstall
```

## Generating SystemVerilog from Chisel
Right now most synthesis tools only accept less abstract HDLs like SystemVerilog.
This means the Chisel code needs to be converted to SystemVerilog representation in order to synthesize it.
This can be done with the command:
```bash
make rtl
```
This will create a directory called `rtl/` where the SystemVerilog files are located.

## Synthesizing the design
To synthesize the design, in the root directory of the project run:
```bash
make synth
```
This will create the directory `synth/build/<target-fpga>` with a bitstream among other files.

## Programming the FPGA
The build directory contains a lot of files but the most interesting one is `Visualizer.bit` (the bitstream file).
To program the FPGA plug in your FPGA via USB and run the following command:
```bash
make program
```
If you encounter problems, try running it as root or see [Troubleshooting](#troubleshooting).

## Tips
### Makefile
The Makefile is written such that dependencies are resolved.
This means if you made a change to the Chisel code and want to reprogram your FPGA you can just run:
```bash
make program
```
Which will automatically generate SystemVerilog, synthesize it to a bitstream, and program the FPGA.

## Troubleshooting
### Error: unable to open ftdi device
Check that your device is properly plugged in and shows up when you run the `lsusb` command.
If the device shows up, the problem is most likely permission issues.
To fix this run the commands:
```bash
sudo bash -c 'echo ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6010", MODE="666", TAG+="uaccess" > /etc/udev/rules.d/99-ftdi.rules'
sudo udevadm control --reload-rules && sudo udevadm trigger
```
*Note: The Nexys A7 100T uses standard FTDI drivers. Ensure your USB cable is data-capable.*
