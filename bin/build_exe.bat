@echo off

echo ***** Compile all include sourcefiles to object files *****
clang -c -g -std=c89 -IS:\development\repos\ANSI-C\src\includes\ S:\development\repos\ANSI-C\src\includes\DS\*.c || exit /b
echo.

echo ***** Compile main application sourcefile to object file *****
clang -c -g -std=c89 -IS:\development\repos\ANSI-C\src\includes\ S:\development\repos\ANSI-C\src\%1.c || exit /b
echo.

echo ***** Link all object files and build application executable *****
clang -g -std=c89 -IS:\development\repos\ANSI-C\src\includes\ S:\development\repos\ANSI-C\bin\*.o -o S:\development\repos\ANSI-C\bin\%1.exe || exit /b
echo.

echo Build of %1.exe completed successfully!
exit /b
