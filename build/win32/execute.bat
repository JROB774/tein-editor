@echo off

REM ============================================================================
REM = Output Program Execution Script                                          =
REM = Authored by Joshua Robertson                                             =
REM ============================================================================

REM ============================================================================

setlocal

pushd ..\..

call build\win32\utility\buildvars.bat

pushd binary
%OutputExecutable%
popd

popd

endlocal

REM ============================================================================
