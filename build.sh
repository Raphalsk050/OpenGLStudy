#!/usr/bin/env bash

DIR="build"
CORES=$(nproc)

if [ ! -d "$DIR" ]; then
  echo "The directory '$DIR' does not exist."
  echo "Creating directory '$DIR'."
  mkdir "$DIR"
fi

cd "$DIR"
echo "Changing to directory '$DIR'."

cmake .. -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release

Ninja -j "$CORES"
echo "Build complete!"

echo "Opening the generated binary..."
open OpenGLStudy.app/Contents/MacOS/OpenGLStudy