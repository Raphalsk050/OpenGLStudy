# OpenGLStudy

This project integrates the Bullet Physics engine through CMake. Only the core
libraries (`BulletDynamics`, `BulletCollision` and `LinearMath`) are used. If
the machine has no network access you can provide a pre-downloaded Bullet source
by passing `-DBULLET_ROOT=/path/to/bullet3` when running CMake.
OpenGLStudy is a small research project that explores OpenGL rendering with support for Bullet Physics.  The codebase is cross‑platform and uses CMake to generate build files.

## Prebuilt dependencies
## Highlights

The repository used to contain the full sources of Bullet, Assimp and Boost.
These have been replaced by the precompiled packages available on the system.
Before configuring the project make sure the following packages are installed:
- C++20 project structured into `Core/` and `Program/` modules
- Optional Bullet Physics integration
- Physically based rendering (PBR) with directional, point and spot lights
- Assets (models, shaders, textures) are copied next to the executable after build

## Directory layout

```
sudo apt install libbullet-dev libassimp-dev libboost-thread-dev libboost-system-dev
Core/     Engine implementation
Program/  Application layer and entry point
Assets/   Models, shaders and textures bundled with the executable
Scripts/  Helper scripts (Windows only: generate_ibl.bat)
ThirdParty/  OpenGL related dependencies as submodules
```

The `setup.sh` script now installs these packages automatically.
## Dependencies

Linux builds rely on system packages for some libraries while others are shipped as submodules.  Required runtime libraries are:

- [Bullet](https://github.com/bulletphysics/bullet3)
- [Assimp](https://www.assimp.org/)
- [Boost](https://www.boost.org/) (threads and system)

On Windows these dependencies are pulled using `vcpkg`; on Linux they are searched via `find_package`.  See **Setup** below for how to install them automatically.

## Setup

### Linux (`setup.sh`)

The `setup.sh` script installs development packages through `apt` so the project can be configured with CMake immediately.  It installs OpenGL headers, X11/Wayland utilities and the prebuilt physics and utility libraries listed above.

```bash
./setup.sh
cmake -S . -B build
cmake --build build
```

### Windows (`setup.bat`)

The Windows script automates installation of Visual Studio Build Tools via Chocolatey and sets up [vcpkg](https://github.com/microsoft/vcpkg).  It also generates a Visual Studio solution already configured to use vcpkg as the CMake toolchain.

```bat
setup.bat
```

Running the script results in a `build\` folder containing the `.sln` file and Release binaries.

## Building manually

If you prefer to configure manually, run CMake yourself.  You may set `-DUSE_BULLET=OFF` to disable physics or specify `-DBULLET_ROOT=/path/to/bullet3` when offline.

```bash
cmake -S . -B build -DUSE_BULLET=ON
cmake --build build
```

## Optional utilities

The repository provides `Scripts/generate_ibl.bat` to create prefiltered image-based lighting (IBL) maps using Filament's `cmgen` tool.  This script downloads the Windows prebuilt tool automatically if it is missing.

## Possible improvements

The renderer now supports physically based rendering (PBR) with directional,
point and spot lights. Lights are represented by a `LightComponent` and are
uploaded to the shaders every frame.
- Add continuous integration to verify builds for Linux and Windows
- Provide prebuilt binaries or vcpkg artifacts to speed up setup
- Expand documentation with examples of the engine API

## License

This project is distributed under the Apache 2.0 License.  See `LICENSE` for details.
