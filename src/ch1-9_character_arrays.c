/*  program that reads a set of text lines and
    prints the longest
*/

#include <stdio.h>

#define MAXLINE 1000

/* function prototypes */
int GetLine(char lineArray[], int maxLine);
void CopyLine(char to[], char from[]);

int main()
{
    int currentLineLength;
    int longestLineLength;
    char currentLineArray[MAXLINE];
    char longestLineArray[MAXLINE];

    longestLineLength = 0;
    currentLineLength = GetLine(currentLineArray, MAXLINE);
    while(currentLineLength > 0)
    {
        if(currentLineLength > longestLineLength)
        {
            longestLineLength = currentLineLength;
            CopyLine(longestLineArray, currentLineArray);
        }

        currentLineLength = GetLine(currentLineArray, MAXLINE);
    }

    if(longestLineLength > 0)
    {
        printf("\n\nThe longest line was:\n");
        printf("%s", longestLineArray);
    }

    return 0;
}

int GetLine(char lineArray[], int lineMaxLength)    /* GetLine: read a line into lineArray, return length */
{
    int character;
    int characterCount;

    character = getchar();  /* first character of line */
    for(characterCount = 0; characterCount < lineMaxLength - 1
        && character != EOF && character != '\n'; ++characterCount)
    {
        lineArray[characterCount] = character;
        character = getchar();  /* next character of line */
    }

    if(character == '\n')
    {
        lineArray[characterCount] = character;
        ++characterCount;
    }

    lineArray[characterCount] = '\0';
    return characterCount;
}

void CopyLine(char to[], char from[])
{
    int characterArrayIndex;

    characterArrayIndex = 0;
    while(from[characterArrayIndex] != '\0')
    {
        to[characterArrayIndex] = from[characterArrayIndex];
        ++characterArrayIndex;
    }
}