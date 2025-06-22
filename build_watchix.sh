#!/bin/bash

set -e  # Exit on any error

# ===== Configure =====
echo "Running configuration..."
./configure

# ===== Build =====
echo "Building Watchix..."
make clean
make -j$(nproc)

# ===== Post-Build =====
echo "Build completed successfully."

exit 0
