#ANSI-C Tutorial

This repository is me working through the turorial and exercises in the book "The C Programming Language, Second Edition" by Brian Kernighan and Dennis Ritchie. ISBN: 0-13-110362-8

I am using the ANSI-C (C89) standard with Clang compiler version 12.0.0 on Windows 10 64-bit.

Clang command string to create an executable for a single sourcefile in \bin (run in /src):
    
```
clang.exe -std=c89 -g _sourcefile.c_ -o ..\bin\run.exe
```

-ds