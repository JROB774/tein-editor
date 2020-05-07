@echo off

REM ============================================================================
REM = RemedyBG Debugger Launch Script                                          =
REM = Authored by Joshua Robertson                                             =
REM ============================================================================

REM ============================================================================

setlocal

pushd ..\..

call build\win32\utility\buildvars.bat

start remedybg binary\%OutputExecutable%.rdbg

popd

endlocal

REM ============================================================================
