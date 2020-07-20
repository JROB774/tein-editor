:: Source Code Line Count Launcher Script

@echo off
setlocal

pushd ..\..\tools
python linecount.py -d -e ../source/external/ -e ../source/opengl/ -e ../source/utility/ ../source/
popd

endlocal
