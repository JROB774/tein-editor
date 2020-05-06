@echo off

REM ============================================================================
REM = Visual Studio Debugger Launch Script                                     =
REM = Authored by Joshua Robertson                                             =
REM ============================================================================

REM ============================================================================

setlocal

pushd ..\..

call build\win32\utility\findvsdev.bat
call build\win32\utility\buildvars.bat

call %VSDevPath% -no_logo -arch=%Architecture%

devenv binary\%OutputExecutable%.exe

popd

endlocal

REM ============================================================================
