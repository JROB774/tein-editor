@echo off
setlocal

set vs_ent19="C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\vsdevcmd.bat"
set vs_pro19="C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\vsdevcmd.bat"
set vs_com19="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\vsdevcmd.bat"
set vs_ent17="C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\vsdevcmd.bat"
set vs_pro17="C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\vsdevcmd.bat"
set vs_com17="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\vsdevcmd.bat"

set idir=-I ..\src\external -I ..\src\external\FT2
set ldir=
set defs=
set cflg=-Zc:__cplusplus -std:c++17 -nologo -Oi -MT -WX -W4 -Gm- -GR- -EHsc -Z7
set lflg=-opt:ref -incremental:no
set cwrn=-wd4100 -wd4505 -wd4189
set lwrn=-ignore:4099
set libs=SDL2main.lib SDL2.lib freetype.lib libcurl.lib opengl32.lib dinput8.lib dxguid.lib user32.lib gdi32.lib winmm.lib imm32.lib ole32.lib oleaut32.lib shell32.lib version.lib uuid.lib advapi32.lib setupapi.lib comdlg32.lib shlwapi.lib dbghelp.lib ws2_32.lib wldap32.lib crypt32.lib setargv.obj
set resc=..\res\resources.res
set main=..\src\main.cpp
set name=TheEndEditor.exe

REM SELECT WHICH BUILD MODE YOU WANT TO DO FROM HERE BY UNCOMMENTING
REM goto build_x86_debug
REM goto build_x86_release
    goto build_x64_debug
REM goto build_x64_release

:build_x86_release
set lflg=%lflg% -subsystem:windows,5.1
goto build_x86
:build_x86_debug
set defs=%defs% -DDEBUG_BUILD
set lflg=%lflg% -subsystem:console,5.1
goto build_x86
:build_x86
set ldir=-libpath:..\lib\winnt\x86
if exist %vs_ent19% ( call %vs_ent19% -no_logo -arch=x86 )
if exist %vs_pro19% ( call %vs_pro19% -no_logo -arch=x86 )
if exist %vs_com19% ( call %vs_com19% -no_logo -arch=x86 )
if exist %vs_ent17% ( call %vs_ent17% -no_logo -arch=x86 )
if exist %vs_pro17% ( call %vs_pro17% -no_logo -arch=x86 )
if exist %vs_com17% ( call %vs_com17% -no_logo -arch=x86 )
goto build

:build_x64_release
set lflg=%lflg% -subsystem:windows
goto build_x64
:build_x64_debug
set defs=%defs% -DDEBUG_BUILD
set lflg=%lflg% -subsystem:console
goto build_x64
:build_x64
set ldir=-libpath:..\lib\winnt\x64
if exist %vs_ent19% ( call %vs_ent19% -no_logo -arch=amd64 )
if exist %vs_pro19% ( call %vs_pro19% -no_logo -arch=amd64 )
if exist %vs_com19% ( call %vs_com19% -no_logo -arch=amd64 )
if exist %vs_ent17% ( call %vs_ent17% -no_logo -arch=amd64 )
if exist %vs_pro17% ( call %vs_pro17% -no_logo -arch=amd64 )
if exist %vs_com17% ( call %vs_com17% -no_logo -arch=amd64 )
goto build

:build
if not exist bin mkdir bin
pushd bin
rc -nologo -i ..\res ..\res\resources.rc
cl %idir% %defs% %cflg% %cwrn% -Fe%name% %main% -link %lflg% %lwrn% %ldir% %libs% %resc%
del *.ilk *.res *.obj *.exp *.lib ..\res\*.res
popd
goto end

:end
endlocal
