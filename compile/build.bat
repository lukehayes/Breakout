@echo off

del "bin/app.exe"

REM --- Output Settings
set OUTPUT_DIR=bin
MKDIR %OUTPUT_DIR%

REM --- Compiler Flags
set COMPILE_FLAGS=/MD /Febin\app.exe

REM --- Link Libraries Directory
set LOCAL_LIBS_DIR=C:\Dev\Libraries

REM --- Includes Directories
set INCLUDES= -I include -I %LOCAL_LIBS_DIR%\SDL2\include

REM --- Library Directories
set LIBS_DIR= /LIBPATH:%LOCAL_LIBS_DIR%\SDL2\libs

REM --- Libraries
set LIBS=gdi32.lib user32.lib opengl32.lib kernel32.lib ucrt.lib shell32.lib msvcrt.lib

REM --- Project Sources
set AX_SYSTEM_SRC=
set ALL_SRC=%AX_SYSTEM_SRC% 

REM --- Run Compiler
cl main.c %ALL_SRC% %COMPILE_FLAGS% %INCLUDES% /link %LIBS% %LIBS_DIR% /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

REM --- Delete All Object Files
del *.obj

REM --- Run Binary
REM bin\app.exe

