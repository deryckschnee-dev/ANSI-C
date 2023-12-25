/* Revise the main routine of the longest-line program 
    so it will correctly print the length of arbitrarily 
    long input lines, and as much of the texts as possible.

    NOTE: Different from book convention, I declared arrays using
    "*name" instead of "name[]" as this made sense to clarify
    that the function can modify the specified array using a 
    pointer to that array.  This is one way arrays differ from
    other variables when dealing with function calls.

    Deryck Schnee
    Completed on 25-Oct-2023

*/

#include <stdio.h>
#include "tutorial.h"

#define MAXLINE 1000
#define CONSOLE_WIDTH 120

int main()
{
    int currentLineLength;
    int longestLineLength;
    int arrayIndex;
    char currentCharacter;
    char currentLineArray[MAXLINE];
    char longestLineArray[MAXLINE];

    longestLineLength = 0;
    currentLineLength = ds_GetLine(currentLineArray, MAXLINE); /* get initial line */
    while(currentLineLength > 0)
    {
        if(currentLineLength > longestLineLength)
        {
            longestLineLength = currentLineLength;
            ds_CopyLine(longestLineArray, currentLineArray);
        }

        currentLineLength = ds_GetLine(currentLineArray, MAXLINE); /* get next line */
    }

    if(longestLineLength > 0)   /* modified this section to truncate longest 
                                    line text output at CONSOLE_WIDTH columns */
    {
        if(longestLineLength > CONSOLE_WIDTH)
        {
            printf("\n\nThe longest line was %d characters (Output text truncated at %d columns):\n", longestLineLength - 1, CONSOLE_WIDTH);
            arrayIndex = 0;
            while(arrayIndex < CONSOLE_WIDTH)
            {
                printf("%c", longestLineArray[arrayIndex]);
                ++arrayIndex;
            }
            printf("\n\n");
        }
        else
        {
            printf("\n\nThe longest line was %d characters:\n", longestLineLength - 1);
            arrayIndex = 0;
            while(longestLineArray[arrayIndex] != '\n' 
                && longestLineArray[arrayIndex] != '\0')
            {
                printf("%c", longestLineArray[arrayIndex]);
                ++arrayIndex;
            }
            printf("\n\n");
        }
    }

    return 0;
}
