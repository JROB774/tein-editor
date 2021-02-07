@echo off
setlocal

pushd ..\..

call build\win32\findvs.bat
call build\win32\config.bat

                          python tools\manifest.py
if %BuildMode%==Release ( python tools\packgpak.py )

call %VSDevPath% -no_logo -arch=%Architecture%

if not exist binary mkdir binary
pushd binary

if %BuildMode%==Release rc -nologo -i %ResourcePath% %ResourceFile%

call ..\build\win32\timer.bat "cl %IncludeDirs% %Defines% %CompilerFlags% %CompilerWarnings% -Fe%OutputExecutable% %InputSource% -link %LinkerFlags% %LinkerWarnings% %LibraryDirs% %Libraries% %InputResource%"

if %BuildMode%==Release del %ResourcePath%*.res
del *.ilk *.res *.obj *.exp *.lib

popd
popd

endlocal
