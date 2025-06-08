#!/bin/bash
# Generate IBL maps using Filament's cmgen tool.
# Usage: ./Scripts/generate_ibl.sh <input_hdr> <output_dir>
set -e
if [ $# -lt 2 ]; then
    echo "Usage: $0 <input_hdr> <output_dir>"
    exit 1
fi
INPUT=$1
OUT=$2
FILAMENT_DIR="$(dirname "$0")/../ThirdParty/filament"
CMGEN="$FILAMENT_DIR/bin/cmgen"
if [ ! -f "$CMGEN" ]; then
    echo "cmgen not found, attempting to download prebuilt tools..."
    mkdir -p "$FILAMENT_DIR/bin"
    TMPDIR=$(mktemp -d)
    VERSION="v1.36.0"
    DATE="20231218"
    ARCHIVE="$TMPDIR/filament.tgz"
    wget -O "$ARCHIVE" "https://github.com/google/filament/releases/download/$VERSION/filament-$DATE-linux.tgz"
    tar -xzf "$ARCHIVE" -C "$TMPDIR" filament/bin/cmgen
    mv "$TMPDIR/filament/bin/cmgen" "$CMGEN"
    rm -rf "$TMPDIR"
    chmod +x "$CMGEN"
fi
mkdir -p "$OUT"
"$CMGEN" --type=ktx --format=rgb32f --ibl-ld="$OUT/prefilter" --ibl-irradiance="$OUT/irradiance" "$INPUT"
