@echo off

set Architecture=amd64
set BuildMode=Debug

set Libraries=SDL2main.lib SDL2.lib freetype.lib opengl32.lib dinput8.lib dxguid.lib user32.lib gdi32.lib winmm.lib imm32.lib ole32.lib oleaut32.lib shell32.lib version.lib uuid.lib advapi32.lib setupapi.lib comdlg32.lib shlwapi.lib dbghelp.lib setargv.obj

set IncludeDirs=-I ..\..\third_party\freetype\include -I ..\..\third_party\freetype\include\freetype -I ..\..\third_party\glad\win32 -I ..\..\third_party\glm -I ..\..\third_party\gon -I ..\..\third_party\sdl2\include -I ..\..\third_party\stb
set LibraryDirs=

set Defines=-D PLATFORM_WIN32

if %Architecture% == x86 (
    set LibraryDirs=%LibraryDirs% -libpath:..\..\third_party\freetype\lib\win32\x86 -libpath:..\..\third_party\sdl2\lib\win32\x86
    set Defines=%Defines% -D BUILD_X86
)
if %Architecture% == amd64 (
    set LibraryDirs=%LibraryDirs% -libpath:..\..\third_party\freetype\lib\win32\x64 -libpath:..\..\third_party\sdl2\lib\win32\x64
    set Defines=%Defines% -D BUILD_X64
)

set CompilerFlags=-Zc:__cplusplus -std:c++17 -nologo -MT -Oi -Gm- -GR- -EHsc -Z7
set LinkerFlags=-opt:ref -incremental:no

set CompilerWarnings=-wd4100 -wd4505 -wd4189
set LinkerWarnings=-ignore:4099

set ResourceFile=..\..\source\resource\win32\icon.rc
set ResourcePath=..\..\source\resource\win32\
set InputResource=..\..\source\resource\win32\icon.res
set InputSource=..\..\source\main.cpp

set OutputExecutable=TheEndEditor-%Architecture%

if %BuildMode%==Release (
    set LinkerFlags=%LinkerFlags% -subsystem:windows
)
if %BuildMode%==Debug (
    set OutputExecutable=%OutputExecutable%-Debug
    set Defines=%Defines% -D BUILD_DEBUG
    set InputResource=
    set LinkerFlags=%LinkerFlags% -subsystem:console
)

if %Architecture%==x86 (
    set CompilerFlags=%CompilerFlags% -arch:IA32
    set LinkerFlags=%LinkerFlags%,5.1
)
