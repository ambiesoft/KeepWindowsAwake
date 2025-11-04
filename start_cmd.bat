@echo off
REM Is this a second launch
IF "%1"=="2ndlaunch" (
  goto justlaunch
) ELSE (
  goto docontinue
)

:justlaunch
REM Env
:: clink is advanced command prompt, see https://mridgers.github.io/clink/
if exist C:\LegacyPrograms\clink\clink.batZZZ (
  C:\LegacyPrograms\clink\clink.bat
  exit /b
) else (
  :: start powershell
  :: start cmd /k
  start powershell
)
exit

:docontinue
IF NOT "%1"=="" exit

REM always launch 64bit cmd
set "SystemPath=%SystemRoot%\System32"
if not "%ProgramFiles(x86)%"=="" (
    if exist %SystemRoot%\Sysnative\* set "SystemPath=%SystemRoot%\Sysnative"
)

call envninja
call envllvm
call envcmake

REM always launch 64bit cmd
REM echo start %SystemPath%\cmd.exe /k %~dp0%~nx0 2ndlaunch
start %SystemPath%\cmd.exe /k %~dp0%~nx0 2ndlaunch

