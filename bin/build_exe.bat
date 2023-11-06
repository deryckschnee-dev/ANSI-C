@echo off

REM compile includes
:compinc
clang ^
-c ^
-g ^
-std=c89 ^
-IS:\development\repos\ANSI-C\src\includes\ ^
S:\development\repos\ANSI-C\src\includes\DS\*.c

REM compile main source file
:compsrc
clang ^
-c ^
-g ^
-std=c89 ^
-IS:\development\repos\ANSI-C\src\includes\ ^
S:\development\repos\ANSI-C\src\%1.c

REM link object files
:linkobj
clang ^
-g ^
-std=c89 ^
-IS:\development\repos\ANSI-C\src\includes\ ^
S:\development\repos\ANSI-C\bin\*.o ^
-o S:\development\repos\ANSI-C\bin\%1.exe

echo Batchfile completed.
exit /b
