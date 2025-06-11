echo Building project (Release)...
cmake --build build --config Release
if errorlevel 1 (
  echo Build failed.
  exit /b 1
)

echo.
echo Setup and build complete! Solution available in build\