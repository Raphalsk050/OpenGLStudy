#!/usr/bin/env bash
set -e

echo "Setting up development environment for macOS..."

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    echo "Homebrew not found. Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    
    # Add Homebrew to PATH for Apple Silicon Macs
    if [[ $(uname -m) == "arm64" ]]; then
        echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
        eval "$(/opt/homebrew/bin/brew shellenv)"
    fi
else
    echo "Homebrew found. Updating..."
    brew update
fi

# Install build tools
echo "Installing build tools..."
brew install cmake pkg-config

# Install OpenGL dependencies
echo "Installing OpenGL dependencies..."
# macOS comes with OpenGL frameworks, but we need some tools
brew install glfw3 glew

# Install physics and utility libraries
echo "Installing physics and utility libraries..."
brew install bullet
brew install assimp
brew install boost
brew install zlib

# Install additional development tools (optional but useful)
echo "Installing additional development tools..."
brew install ninja  # Faster build system

# Create Info.plist.in file if it doesn't exist
if [ ! -f "Info.plist.in" ]; then
    echo "Creating Info.plist.in file..."
    cat > Info.plist.in << 'EOF'
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleName</key>
    <string>OpenGL Study</string>
    <key>CFBundleDisplayName</key>
    <string>OpenGL Study</string>
    <key>CFBundleIdentifier</key>
    <string>com.yourcompany.openglstudy</string>
    <key>CFBundleVersion</key>
    <string>1.0</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleSignature</key>
    <string>????</string>
    <key>CFBundleExecutable</key>
    <string>openglStudy</string>
    <key>NSHighResolutionCapable</key>
    <true/>
    <key>NSSupportsAutomaticGraphicsSwitching</key>
    <true/>
</dict>
</plist>
EOF
fi

echo
echo "Setup complete!"
echo
echo "To build the project:"
echo "  use the build.sh script"
echo
echo
echo "Note: If you're on Apple Silicon (M1/M2), the libraries are installed in /opt/homebrew"
echo "      If you're on Intel Mac, they're in /usr/local"