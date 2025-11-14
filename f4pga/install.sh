#!/usr/bin/env bash
set -e  # stop on first error
set -o pipefail

# --- Configurable parameters ---
F4PGA_INSTALL_DIR="$PWD/tools"
FPGA_FAM="xc7"
F4PGA_CONDA_DIR="$F4PGA_INSTALL_DIR/$FPGA_FAM/conda"
F4PGA_EXAMPLES_DIR="f4pga-examples"

# --- Clone examples repository ---
if [ ! -d "$F4PGA_EXAMPLES_DIR" ]; then
    echo "[INFO] Cloning F4PGA examples..."
    git clone https://github.com/chipsalliance/f4pga-examples
else
    echo "[INFO] f4pga-examples already exists, skipping clone."
fi

pushd "$F4PGA_EXAMPLES_DIR" > /dev/null

# --- Conda installation ---
# If you run this script inside a Docker container install conda before or this will cause problems.
# set the environment variable F4PGA_SKIP_CONDA_INSTALL=1 in the dockerfile so it won't install again.
if [ "${F4PGA_SKIP_CONDA_INSTALL}" = "1" ]; then
    echo "[INFO] Skipping Miniconda installation (F4PGA_SKIP_CONDA_INSTALL=1)."
else
    echo "[INFO] Installing Miniconda (Linux x86_64)..."
    wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh -O conda_installer.sh
    bash conda_installer.sh -u -b -p "$F4PGA_CONDA_DIR"
    rm conda_installer.sh
fi

# --- Source Conda environment ---
if [ -f "$F4PGA_CONDA_DIR/etc/profile.d/conda.sh" ]; then
    source "$F4PGA_CONDA_DIR/etc/profile.d/conda.sh"
else
    echo "[ERROR] Conda not found at $F4PGA_CONDA_DIR. Aborting."
    exit 1
fi

# --- Create Conda environment ---
echo "[INFO] Creating F4PGA Conda environment..."
conda env create -f "$FPGA_FAM/environment.yml" || conda env update -f "$FPGA_FAM/environment.yml"

# --- Install prebuilt packages ---
echo "[INFO] Installing F4PGA packages..."
export F4PGA_PACKAGES="install-xc7 xc7a100t_test"
mkdir -p "$F4PGA_INSTALL_DIR/$FPGA_FAM"

F4PGA_TIMESTAMP="20220920-124259"
F4PGA_HASH="007d1c1"

for PKG in $F4PGA_PACKAGES; do
  echo "[INFO] Downloading package: $PKG ..."
  wget -qO- "https://storage.googleapis.com/symbiflow-arch-defs/artifacts/prod/foss-fpga-tools/symbiflow-arch-defs/continuous/install/${F4PGA_TIMESTAMP}/symbiflow-arch-defs-${PKG}-${F4PGA_HASH}.tar.xz" | \
  tar -xJC "$F4PGA_INSTALL_DIR/$FPGA_FAM"
done

popd > /dev/null
echo "[INFO] F4PGA installation complete."

