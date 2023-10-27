/* Personal library of functions created while
    working through the book, exercises and 
    other spontaneous rabbit-holes.

    Deryck Schnee
*/


#include <stdio.h>
#include "tutorial.h"

/* #####    FUNCTION DEFINITIONS                ##### 
*/

int ds_Test(int firstNumber, int secondNumber)
{
    int result;
    result = firstNumber + secondNumber;

    return result;
}

int ds_TestTwo(int firstNumber, int secondNumber)
{
    int result;
    result = firstNumber * secondNumber;

    return result;
}

int ds_ConvertTempToC(int tempInF)
{
    int result;
    
    result = 5 * (tempInF-32) / 9;
    return result;
}

int ds_GetLine(char *lineArray, int lineMaxLength)  /* Requires: stdio.h */
{
    int character;
    int characterCount;

    character = getchar();  /* get first character of line */
    for(characterCount = 0; characterCount < lineMaxLength - 1
        && character != EOF && character != '\n'; ++characterCount)
    {
        lineArray[characterCount] = character;
        character = getchar();  /* get next character of line */
    }

    if(character == '\n')
    {
        lineArray[characterCount] = character;
        ++characterCount;
    }

    lineArray[characterCount] = '\0';   /* add NULL termination character to line */
    return characterCount;
}

void ds_CopyLine(char *destination, char *source)
{
    int arrayIndex;

    arrayIndex = 0;
    while(source[arrayIndex] != '\0')
    {
        destination[arrayIndex] = source[arrayIndex];
        ++arrayIndex;
    }
}

void ds_AppendLine(char *destination, char *source, int offsetIndex, int maxSize)
{
    int arrayIndex;

    arrayIndex = 0;
    while(source[arrayIndex] != '\0' && offsetIndex < maxSize)
    {
        destination[offsetIndex] = source[arrayIndex];
        ++arrayIndex;
        ++offsetIndex;
    }
}
