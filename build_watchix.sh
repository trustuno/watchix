#!/bin/bash

set -e  # Exit on any error

# ===== Configuration =====
TOOLCHAIN=gcc
CFLAGS="-Wall -Wextra -Iinclude"
OBJ_DIR="obj"
INSTALL_DIR="install"
OUTPUT_DIR="output"

# ===== Print Build Info =====
echo "========== Watchix Build Script =========="
echo "Toolchain:     $TOOLCHAIN"
echo "CFLAGS:        $CFLAGS"
echo "Object Dir:    $OBJ_DIR"
echo "Install Dir:   $INSTALL_DIR"
echo "Output Dir:    $OUTPUT_DIR"
echo "=========================================="

# ===== Configure =====
echo "Running configuration..."
./configure TOOLCHAIN=$TOOLCHAIN OBJ_DIR=$OBJ_DIR INSTALL_DIR=$INSTALL_DIR OUTPUT_DIR=$OUTPUT_DIR

# ===== Build =====
echo "Building Watchix..."
make -j$(nproc)

# ===== Post-Build =====
echo "Build completed successfully."
echo "Executable is in: $INSTALL_DIR/watchix"

# ===== Copy to Output =====
mkdir -p $OUTPUT_DIR
cp $INSTALL_DIR/watchix $OUTPUT_DIR/

echo "Executable copied to $OUTPUT_DIR."

exit 0
