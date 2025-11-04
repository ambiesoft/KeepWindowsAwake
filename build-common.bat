
IF "%1"=="" (
  echo No Input, Run 'build-debug' or 'build-release'
  pause
  exit /b
)
call envllvm
call envcmake
call envninja

if not exist %~dp0build\%1 (
  cmake -B build/%1 -G "Ninja" -DCMAKE_BUILD_TYPE=%1
)
cmake --build build\%1
pause
