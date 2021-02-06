@echo off
setlocal

pushd ..\..
call build\win32\config.bat
pushd binary
%OutputExecutable%
popd
popd

endlocal
