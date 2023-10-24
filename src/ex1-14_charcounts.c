/* Write a program that takes user input and outputs a 
   histogram showing # of character occurences. 
   
   Deryck Schnee
   Completed on 23-Oct-2023
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ARRAY_SIZE 26   /* for 26-letter Alphabet */

int isCharacterAlpha(char checkedCharacter)
{
    if((checkedCharacter >= 65 && checkedCharacter <= 90)
    || (checkedCharacter >= 97 && checkedCharacter <= 122))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    char character;
    int arrayCharacterCount[ARRAY_SIZE]; /* character count array for letters A-Z, not case-sensitive */
    int arrayIndex;

    /* initialize arrayCharacterCount with zeros */
    for(arrayIndex = 0; arrayIndex < ARRAY_SIZE; ++arrayIndex)
    {
        arrayCharacterCount[arrayIndex] = 0;
    }
    
    /* evaluate character and update counts */
    character = getchar();

    while(character != EOF)
    {
        if(isCharacterAlpha(character) == TRUE)
        {
            if(character > 90)
            {
                character = character - 32;      /* convert lower-case to upper case decimal value */
            }

            arrayIndex = character - 65;        /* remove ASCII table offset to place A at position 0 in array */

            arrayCharacterCount[arrayIndex]++;  /* increment count value for current character */
            
        }

        character = getchar();
    }

    /* display histogram on console */
    printf("\n");
    printf("Character : Occurrences\n");
    printf("--------------------------------------------------------------------------------\n");

    for(arrayIndex = 0; arrayIndex < ARRAY_SIZE; ++arrayIndex)
    {        
        int barLength = arrayCharacterCount[arrayIndex];
        int barEnd = arrayCharacterCount[arrayIndex];
        int barLoopIndex;

        if (barLength > 71)
        {
            barLength = 71; /* limit bar length to fit 80-column console width */
        }

        printf("%c: ", (arrayIndex + 65)); /* Draw left-hand legend */

        for(barLoopIndex = 0; barLoopIndex < barLength; ++barLoopIndex)
        {
            printf("#");   /* Draw bar segments */
        }

        printf(" (%d)\n", arrayCharacterCount[arrayIndex]); /* Draw bar end */
    }
    printf("\n");

    return 0;
}
