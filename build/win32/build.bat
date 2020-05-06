@echo off

REM ============================================================================
REM = Program Build Process Script                                             =
REM = Authored by Joshua Robertson                                             =
REM ============================================================================

REM ============================================================================

setlocal

pushd ..\..

call build\win32\utility\findvsdev.bat
call build\win32\utility\buildvars.bat

                          python tools\manifest.py
if %BuildMode%==Release ( python tools\packgpak.py )

call %VSDevPath% -no_logo -arch=%Architecture%

if not exist binary mkdir binary
pushd binary

if %BuildMode%==Release rc -nologo -i %ResourcePath% %ResourceFile%

echo Compiling %OutputExecutable%.exe...
cl %IncludeDirs% %Defines% %CompilerFlags% %CompilerWarnings% ^
   -Fe%OutputExecutable% %InputSource% -link %LinkerFlags%    ^
   %LinkerWarnings% %LibraryDirs% %Libraries% %InputResource%
echo Compilation complete!

if %BuildMode%==Release del %ResourcePath%*.res
del *.ilk *.res *.obj *.exp *.lib

popd
popd

endlocal

REM ============================================================================
