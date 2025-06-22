#!/bin/bash

set -e  # Exit on any error

echo "Generating version files..."
./scripts/generate_version.sh --release

# ===== Configure =====
echo "Running configuration..."
./configure

# ===== Build =====
echo "Building Watchix..."
make clean
make 

# ===== Post-Build =====
echo "Build completed successfully."

exit 0
