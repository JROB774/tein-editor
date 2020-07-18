:: Source Code Line Count Launcher Script

@echo off
setlocal

pushd ..\..\tools
python linecount.py
popd

endlocal
