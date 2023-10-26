/* Write a program that takes user input and outputs a 
   histogram of lengths of words entered. 
   
   Deryck Schnee
   Completed on 23-Oct-2023
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ARRAY_SIZE 20   /* for words up to 19 characters long */

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
    int barIndex;
    int arrayIndex;
    int character = 0;
    int insideWord = 0;
    int currentWordLength = 0;
    int wordLengthCount[ARRAY_SIZE];
    int exceptionWordTooLarge = 0;

    // initialize array with 0's
    for (arrayIndex = 0; arrayIndex < ARRAY_SIZE; ++arrayIndex){
        wordLengthCount[arrayIndex] = 0;
    }

    printf("Type in a list of words separated by spaces. Enter ^Z on a blank ");
    printf("line to end program.\n");
    printf("> ");

    character = getchar();

    while(character != EOF)
    {
        if (insideWord == 0)    /* was outside word on last character */
        {
            // words are composed of the characters [A-Z,a-z]
            if(isCharacterAlpha(character) == TRUE)
            {
                insideWord = 1;
                currentWordLength++;
            }
            else
            {
                insideWord = 0;
            }
        }
        else    /* was inside word on last character */
        {
            if(isCharacterAlpha(character) == TRUE)
            {
                insideWord = 1;
                currentWordLength++;
            }
            else
            {
                insideWord = 0;
                if(currentWordLength > (ARRAY_SIZE - 1))
                {   /* Array size exceeded. Discard word length result */
                    exceptionWordTooLarge = 1;
                    currentWordLength = 0;
                }
                else
                {   /* record word length */
                    wordLengthCount[currentWordLength]++;
                    currentWordLength = 0;
                }
            }
        }
        
        character = getchar();
    }
    
    printf("\n-=- Word Histograph -=-\n\n");
    printf("Char\n");
    printf("Count   Occurences\n");
    printf("======= ===============\n");
    
    for(arrayIndex = 1; arrayIndex < ARRAY_SIZE; ++arrayIndex)
    {   
        /* Print left-hand legend */
        printf("    %2d: ", arrayIndex);

        /* Print bar */
        for(barIndex = 0; barIndex < wordLengthCount[arrayIndex]; ++barIndex)
        {
            printf("#");
        }
        
        /* Print bar ending detail */
        if(wordLengthCount[arrayIndex] != 0)
        {
            printf(" (%d)", wordLengthCount[arrayIndex]);
        }
        printf("\n");
    }

    printf("\n");

    if(exceptionWordTooLarge == 1)
    {
        printf("NOTE: Counts of words larger than %d characters were discarded.\n\n", (ARRAY_SIZE - 1));
    }

    return 0;
}