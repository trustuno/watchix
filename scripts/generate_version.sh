#!/bin/bash

set -e

VERSION_FILE="VERSION"
VERSION_HEADER_FILE="include/version.h"

# Get current git commit ID
BUILD_ID=$(git rev-parse --short=6 HEAD)

# Check if version.h has changes
if git diff --quiet "$VERSION_HEADER_FILE" && git diff --cached --quiet "$VERSION_HEADER_FILE"; then
    echo "$VERSION_HEADER_FILE is clean."
else
    echo "Reverting changes in $VERSION_HEADER_FILE..."
    git restore "$VERSION_HEADER_FILE"
fi

# Check if VERSION File has changes
if git diff --quiet "$VERSION_FILE" && git diff --cached --quiet "$VERSION_FILE"; then
    echo "$VERSION_FILE is clean."
else
    echo "Reverting changes in $VERSION_FILE..."
    git restore "$VERSION_FILE"
fi

# Calculate current minor version: YYMM
YEAR=$(date +%y)
WEEK=$(date +%V)
CURRENT_MINOR=$((10#$YEAR * 100 + 10#$WEEK))  # Force decimal to avoid octal issues

# If version.txt doesn't exist, create initial version
if [ ! -f "$VERSION_FILE" ]; then
    echo "0.$CURRENT_MINOR.0" > "$VERSION_FILE"
    echo "Initialized version.txt to 0.$CURRENT_MINOR.0"
fi

# Read existing version
EXISTING_VERSION=$(cat "$VERSION_FILE")
EXISTING_MAJOR=$(echo "$EXISTING_VERSION" | cut -d '.' -f1)
EXISTING_MINOR=$(echo "$EXISTING_VERSION" | cut -d '.' -f2)
EXISTING_HOTFIX=$(echo "$EXISTING_VERSION" | cut -d '.' -f3)

if [ "$CURRENT_MINOR" -ne "$EXISTING_MINOR" ]; then
    # New week -> reset hotfix
    HOTFIX=0
else
    # Same week -> hotfix + 1
    HOTFIX=$((EXISTING_HOTFIX + 1))
fi



# Write back to version.txt (always update)
echo "${EXISTING_MAJOR}.${CURRENT_MINOR}.${HOTFIX}" > "$VERSION_FILE"
echo "Updated VERSION to ${EXISTING_MAJOR}.${CURRENT_MINOR}.${HOTFIX}"

# Generate version.h
echo "Generating $VERSION_HEADER_FILE..."
mkdir -p $(dirname "$VERSION_HEADER_FILE")
cat > "$VERSION_HEADER_FILE" <<EOL
#ifndef VERSION_H
#define VERSION_H

#define WATCHIX_MAJOR ${EXISTING_MAJOR}
#define WATCHIX_MINOR ${CURRENT_MINOR}
#define WATCHIX_HOTFIX ${HOTFIX}
#define WATCHIX_BUILD_ID "${BUILD_ID}"

#endif // VERSION_H
EOL

echo "Generated $VERSION_HEADER_FILE with version: ${EXISTING_MAJOR}.${CURRENT_MINOR}.${HOTFIX}.${BUILD_ID}"
