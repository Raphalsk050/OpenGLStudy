@echo off
REM =====================================================================================
REM Windows setup script: installs and configures vcpkg and all required libs via vcpkg
REM =====================================================================================

REM Exit on error
setlocal enableextensions enabledelayedexpansion
if not defined VCPKG_ROOT set VCPKG_ROOT=%~dp0\vcpkg

REM 1) Check if Git is available
git --version >nul 2>&1
if errorlevel 1 (
    echo ERROR: Git not found in PATH. Please install Git and try again.
    pause
    exit /b 1
)

REM 2) Clone vcpkg if it doesn't already exist
if not exist "%VCPKG_ROOT%" (
    echo Cloning vcpkg into %VCPKG_ROOT% ...
    git clone https://github.com/microsoft/vcpkg.git "%VCPKG_ROOT%"
    if errorlevel 1 (
        echo Failed to clone vcpkg.
        pause
        exit /b 1
    )
)

REM 3) Bootstrap vcpkg
pushd "%VCPKG_ROOT%"
echo Bootstrapping vcpkg...
bootstrap-vcpkg.bat
if errorlevel 1 (
    echo Bootstrapping vcpkg failed.
    popd
    pause
    exit /b 1
)

REM 4) Integrate vcpkg with Visual Studio/CMake
echo Integrating vcpkg with Visual Studio/CMake...
.\vcpkg integrate install
if errorlevel 1 (
    echo Failed to integrate vcpkg.
    popd
    pause
    exit /b 1
)

REM 5) Install required libraries via vcpkg
echo Installing required packages via vcpkg...
.\vcpkg install ^
    assimp:x64-windows ^
    boost-thread:x64-windows ^
    boost-system:x64-windows ^
    zlib:x64-windows ^
    bullet3:x64-windows ^
    glfw3:x64-windows ^
    tinyexr:x64-windows

if errorlevel 1 (
    echo Failed to install one or more packages.
    popd
    pause
    exit /b 1
)

popd

echo.
echo ============================
echo Setup complete!
echo - Libraries installed via vcpkg:
echo     assimp, boost-thread, boost-system, zlib, bullet3, glfw3, tinyexr

REM Persist VCPKG_ROOT so CMake can automatically find the toolchain later
echo Setting VCPKG_ROOT environment variable for future terminals...
setx VCPKG_ROOT "%VCPKG_ROOT%" >nul

REM Also keep VCPKG_ROOT available in the current session
endlocal & set VCPKG_ROOT=%VCPKG_ROOT%

echo - Use CMake with:
echo     -DCMAKE_TOOLCHAIN_FILE="%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake"
echo   to automatically find these dependencies.
echo ============================

pause
