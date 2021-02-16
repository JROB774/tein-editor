@echo off
setlocal

pushd ..\..
call build\win32\config.bat
pushd binary\win32
%OutputExecutable%
popd
popd

endlocal
