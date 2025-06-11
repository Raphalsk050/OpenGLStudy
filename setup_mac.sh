#!/usr/bin/env bash
set -e

# 1. Check for and install Homebrew if missing
if ! command -v brew &> /dev/null; then
  echo "Homebrew not found. Installing Homebrew..."
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

# 2. Update Homebrew
echo "Updating Homebrew..."
brew update

# 3. Install OpenGL/utilities
# On macOS OpenGL is provided by the framework, but we can install GLUT and GLEW
echo "Installing freeglut, glew and pkg-config..."
brew install freeglut glew pkg-config

# 4. X11 (via XQuartz) and related X.Org libraries
echo "Installing XQuartz (X11) and X.Org libraries..."
brew install --cask xquartz
# After installing XQuartz, you may need to run:
# open /Applications/Utilities/XQuartz.app
# and add to your environment:
# export PATH="/opt/X11/bin:$PATH"
# export LDFLAGS="-L/opt/X11/lib"
# export CPPFLAGS="-I/opt/X11/include"
brew install libx11 libxrandr libxinerama libxcursor libxi libxkbcommon wayland wayland-protocols

# 5. Physics and utility libraries
echo "Installing Bullet, Assimp and Boost..."
brew install bullet assimp boost

echo
echo "✅ Setup complete!"
