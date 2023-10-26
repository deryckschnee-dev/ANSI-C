/* Personal library of functions created while
    working through the book, exercises and 
    other spontaneous rabbit-holes.

    Deryck Schnee
*/

#pragma once

/* #####    FUNCTION DECLARATIONS                       #####
*/

/* ds_Test: add two integers, return sum. 
*/  int ds_Test(int firstNumber, int secondNumber);

/* ds_TestTwo: multiply two integers, return product. 
*/  int ds_TestTwo(int firstNumber, int secondNumber);

/* ds_ConvertTempToC: takes Fahrenheit, perform
    conversion, return Celsius.
*/  int ds_ConvertTempToC(int);

/* ds_GetLine: read a line into specified array, 
    add NULL '\0' termination character,
    return length of array.
*/  int ds_GetLine(char *lineArray, int maxLine);

/* ds_CopyLine: copy source array to destination array.
*/  void ds_CopyLine(char *destination, char *source);
