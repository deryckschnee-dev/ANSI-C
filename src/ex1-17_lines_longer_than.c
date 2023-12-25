/* Write a program to print all input lines 
    that are longer than 80 characters. 
    
    Deryck Schnee
    Completed on 26-Oct-2023
    
*/

/* Program Flow:
    -Read line into working array and determine length.
    -For lines that exceed 80 characters in length, append to combined array.
    -Output lines in combined array.
*/

#include <stdio.h>
#include "tutorial.h"

#define MIN_LINE_LENGTH 80
#define MAX_LINE_LENGTH 1000
#define MAX_COMBINED_SIZE 100000

int main()
{
    int currentLineLength;
    int combinedLinesIndex;

    char character;
    char currentLineArray[MAX_LINE_LENGTH];
    char combinedLinesArray[MAX_COMBINED_SIZE];

    currentLineLength = ds_GetLine(currentLineArray, MAX_LINE_LENGTH);
    combinedLinesIndex = 0;

    while(currentLineLength > 0)
    {
        if (currentLineLength > MIN_LINE_LENGTH)
        {
            /* copy to combined array */
            ds_AppendLine(combinedLinesArray, currentLineArray, combinedLinesIndex, 
                MAX_COMBINED_SIZE);

            combinedLinesIndex = combinedLinesIndex + currentLineLength;
        }

        currentLineLength = ds_GetLine(currentLineArray, MAX_LINE_LENGTH);
    }

    /* Output appended lines to screen */
    printf("\nLines over %d characters in length:\n\n", MIN_LINE_LENGTH);
    combinedLinesIndex = 0;
    character = combinedLinesArray[combinedLinesIndex];
    while(character != '\0')
    {
        putchar(character);

        ++combinedLinesIndex;
        character = combinedLinesArray[combinedLinesIndex];
    }
    printf("\n");

    return 0;
}