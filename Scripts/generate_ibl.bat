@echo off
REM -----------------------------------------------------------------------------
REM Generate IBL maps using Filament's cmgen tool (Windows version).
REM Usage: generate_ibl.bat ^<input_hdr^> ^<output_dir^>
REM -----------------------------------------------------------------------------

setlocal enableextensions enabledelayedexpansion

REM --- 1) Check arguments ---
if "%~1"=="" (
    echo Usage: %~nx0 ^<input_hdr^> ^<output_dir^>
    exit /b 1
)
if "%~2"=="" (
    echo Usage: %~nx0 ^<input_hdr^> ^<output_dir^>
    exit /b 1
)

set "INPUT=%~1"
set "OUT=%~2"

REM --- 2) Locate Filament dir relative to this script ---
set "SCRIPT_DIR=%~dp0"
REM remove trailing backslash
if "%SCRIPT_DIR:~-1%"=="\" set "SCRIPT_DIR=%SCRIPT_DIR:~0,-1%"
set "FILAMENT_DIR=%SCRIPT_DIR%\..\ThirdParty\filament"
set "CMGEN=%FILAMENT_DIR%\bin\cmgen.exe"

REM --- 3) If cmgen.exe não existe, baixe e extraia a versão Windows ---
if not exist "%CMGEN%" (
    echo cmgen.exe nao encontrado, baixando ferramentas prebuilt...
    mkdir "%FILAMENT_DIR%\bin" 2>nul

    REM gera um temp dir
    call :mktemp TMPDIR

    set "VERSION=v1.36.0"
    set "DATE=20231218"
    set "ARCHIVE=%TMPDIR%\filament-windows.zip"

    echo Downloading Filament v%VERSION% for Windows...
    curl -L -o "%ARCHIVE%" "https://github.com/google/filament/releases/download/%VERSION%/filament-%DATE%-windows.zip"
    if errorlevel 1 (
        echo Erro ao baixar "%ARCHIVE%"
        rd /s /q "%TMPDIR%"
        exit /b 1
    )

    echo Extraindo cmgen.exe...
    powershell -noprofile -command "Expand-Archive -Path '%ARCHIVE%' -DestinationPath '%TMPDIR%' -Force"
    move /Y "%TMPDIR%\filament\bin\cmgen.exe" "%CMGEN%" >nul
    rd /s /q "%TMPDIR%"
)

REM --- 4) Cria pasta de saída se não existir ---
if not exist "%OUT%" mkdir "%OUT%"

REM --- 5) Executa cmgen ---
echo Gerando IBL maps em "%OUT%"...
"%CMGEN%" --type=ktx --format=rgb32f --ibl-ld="%OUT%\prefilter" --ibl-irradiance="%OUT%\irradiance" "%INPUT%"
if errorlevel 1 (
    echo ERRO: cmgen retornou código %ERRORLEVEL%
    exit /b %ERRORLEVEL%
)

echo Concluído com sucesso.
exit /b 0

REM -----------------------------------------------------------------------------
REM Função simples para criar um temp dir
REM   Usage: call :mktemp VAR_NAME
REM   Resulta em VAR_NAME=<path>
REM -----------------------------------------------------------------------------
:mktemp
  setlocal
  set "_tmpdir=%TEMP%\tmp_%RANDOM%_%RANDOM%_%RANDOM%"
  mkdir "%_tmpdir%"
  endlocal & set "%~1=%_tmpdir%"
  exit /b