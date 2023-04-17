# use for compile/run cycles
cmake --build build;
if ($LASTEXITCODE -eq 0) {
  .\build\Debug\CMakeSFMLProject.exe;
  if ($LASTEXITCODE -ne 0) {
    echo "APP EXIT FAILURE"
  }
}

