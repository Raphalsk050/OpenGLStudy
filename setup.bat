@echo off
rem ============================================================
rem  setup.bat — install VS Build Tools, vcpkg, and generate VS solution with MSVC
rem ============================================================

rem -- Ensure running as Administrator --
net session >nul 2>&1 || (
  echo Please run this script as Administrator.
  pause
  exit /b 1
)

rem -- Install Visual Studio Build Tools 2022 with C++ workload --
echo Installing Visual Studio 2022 Build Tools with C++...
choco install -y visualstudio2022buildtools --package-parameters="--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended --passive --locale en-US"
if errorlevel 1 (
  echo Failed to install VS Build Tools. Exiting.
  exit /b 1
)

rem -- Load VS Developer environment --
set "VS_DEV_CMD=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat"
if exist "%VS_DEV_CMD%" (
  call "%VS_DEV_CMD%" -arch=amd64 >nul
) else (
  echo VS Developer Command Prompt not found. Ensure VS Build Tools installed.
  exit /b 1
)

rem -- Clone and bootstrap vcpkg if missing --
if not exist "vcpkg" (
  echo Cloning vcpkg...
  git clone https://github.com/microsoft/vcpkg.git vcpkg
)
pushd vcpkg
call bootstrap-vcpkg.bat >nul
call vcpkg integrate install >nul
popd

rem -- Create vcpkg manifest if missing --
if not exist "vcpkg.json" (
  echo Writing vcpkg.json manifest...
  (
    echo {
    echo   "name": "openglstudy",
    echo   "version": "0.1.0",
    echo   "dependencies": [
    echo     "assimp",
    echo     "boost-thread",
    echo     "boost-system",
    echo     "zlib",
    echo     "bullet3",
    echo     "glfw3"
    echo   ]
    echo }
  )> vcpkg.json
)

rem -- Generate Visual Studio solution with MSVC --
echo Generating VS2022 solution (MSVC)...
cmake -B build -S . -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE="vcpkg\scripts\buildsystems\vcpkg.cmake" -DVCPKG_FEATURE_FLAGS=manifests -DVCPKG_TARGET_TRIPLET=x64-windows
if errorlevel 1 (
  echo CMake configuration failed.
  exit /b 1
)

rem -- Build the project in Release --
echo Building project (Release)...
cmake --build build --config Release
if errorlevel 1 (
  echo Build failed.
  exit /b 1
)

echo.
echo Setup and build complete! Solution available in build\
