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

#define MAXLINE 1000
#define CONSOLE_WIDTH 120

/* GetLine: read a line into specified array, 
    add NULL '\0' termination character,
    return length of array
*/
int GetLine(char *lineArray, int maxLine);

/* CopyLine: copy from source array to destination array.
*/
void CopyLine(char *destination, char *source);

int main()
{
    int currentLineLength;
    int longestLineLength;
    int arrayIndex;
    char currentCharacter;
    char currentLineArray[MAXLINE];
    char longestLineArray[MAXLINE];

    longestLineLength = 0;
    currentLineLength = GetLine(currentLineArray, MAXLINE); /* get initial line */
    while(currentLineLength > 0)
    {
        if(currentLineLength > longestLineLength)
        {
            longestLineLength = currentLineLength;
            CopyLine(longestLineArray, currentLineArray);
        }

        currentLineLength = GetLine(currentLineArray, MAXLINE); /* get next line */
    }

    if(longestLineLength > 0)   /* modified this section to truncate longest line text output at CONSOLE_WIDTH columns */
    {
        if(longestLineLength > CONSOLE_WIDTH)
        {
            printf("\n\nThe longest line was %d characters (Output text truncated at %d columns):\n", longestLineLength - 1, CONSOLE_WIDTH);
            for(arrayIndex = 0; arrayIndex < CONSOLE_WIDTH; ++arrayIndex)
            {
                currentCharacter = longestLineArray[arrayIndex];
                printf("%c", currentCharacter);
            }
            printf("\n\n");
        }
        else
        {
            printf("\n\nThe longest line was %d characters:\n", longestLineLength - 1);
            printf("%s\n\n", longestLineArray);
        }
    }

    return 0;
}

int GetLine(char *lineArray, int lineMaxLength)
{
    int currentCharacter;
    int characterCount;

    currentCharacter = getchar();  /* get first character of line */
    for(characterCount = 0; characterCount < lineMaxLength - 1
        && currentCharacter != EOF && currentCharacter != '\n'; ++characterCount)
    {
        lineArray[characterCount] = currentCharacter;
        currentCharacter = getchar();  /* get next character of line */
    }

    if(currentCharacter == '\n')
    {
        lineArray[characterCount] = currentCharacter;
        ++characterCount;
    }

    lineArray[characterCount] = '\0';   /* add NULL termination character to line */
    return characterCount;
}

void CopyLine(char *destination, char *source)
{
    int arrayIndex;

    arrayIndex = 0;
    while(source[arrayIndex] != '\0')
    {
        destination[arrayIndex] = source[arrayIndex];
        ++arrayIndex;
    }
}