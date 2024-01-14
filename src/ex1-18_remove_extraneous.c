/* Write a program to remove trailing blanks and tabs from each line of input, 
    and to delete entirely blank lines. 
    
    Deryck Schnee
    Completed on 30-Oct-2023
    
*/

/* Program Flow:
    -Read character and evaluate. (regular character is any except tab or space)

        If character is tab, discard. Read next character.

        If character is space, keep count of continuous spaces. Read next 
            character.

        If character is newline, check if previous character was newline, and if
            so, discard. Read next character. 

        If regular character, check for continuous spaces > 0, write continuous 
            spaces to array, write character to array. Read next character.

    -Output working array to console.

*/

#include <stdio.h>

#define MAX_ARRAY_SIZE 100
#define TRUE 1
#define FALSE 0

int main()
{
    int continuousSpaces = 0;
    int currentArraySize = 0;   /* track array size to prevent overflow */
    int arrayOverflow = FALSE;
    int workingArrayIndex = 0;

    char currentCharacter;
    // test comment
    char previousCharacter = '\0';
    char workingArray[MAX_ARRAY_SIZE];

    currentCharacter = getchar();   /* get initial character */
    while(currentArraySize < MAX_ARRAY_SIZE && currentCharacter != EOF)
    {
        if(currentCharacter == '\t')
        {
            /* discard */
        }
        else if(currentCharacter == ' ')
        {
            /* count spaces */
            ++continuousSpaces;
        }
        else    /* is a regular character or newline */
        {
            /* if previous character was newline, discard current */
            if(currentCharacter == '\n' && previousCharacter == '\n')
            {
                /* discard */
            }
            else
            {
                /* write space(s) to working array */
                while(continuousSpaces > 0)
                {
                    if(currentArraySize >= MAX_ARRAY_SIZE -2) /* overflow check */
                    {
                        workingArray[MAX_ARRAY_SIZE -2] = '\n';
                        workingArray[MAX_ARRAY_SIZE -1] = '\0';
                        currentArraySize = MAX_ARRAY_SIZE;
                        continuousSpaces = 0;
                        arrayOverflow = TRUE;
                    }
                    else
                    {
                        workingArray[workingArrayIndex] = ' ';
                        --continuousSpaces;
                        ++currentArraySize;
                        ++workingArrayIndex;
                    }
                }
                
                /* write regular character to working array */
                if(currentArraySize >= MAX_ARRAY_SIZE -2)   /* overflow check */
                {
                    workingArray[MAX_ARRAY_SIZE -2] = '\n';
                    workingArray[MAX_ARRAY_SIZE -1] = '\0';
                    currentArraySize = MAX_ARRAY_SIZE;
                    arrayOverflow = TRUE;
                }
                else
                {
                    workingArray[workingArrayIndex] = currentCharacter;
                    ++currentArraySize;
                    ++workingArrayIndex;
                }
            }
        }

        previousCharacter = currentCharacter;
        currentCharacter = getchar();
    }

    /* terminate array properly */
    if(currentArraySize < MAX_ARRAY_SIZE)
    {
        workingArray[workingArrayIndex] = '\0';
    }

    /* Output working array contents to console */
    workingArrayIndex = 0;
    printf("Output: \n\n");
    while(workingArrayIndex < MAX_ARRAY_SIZE 
    && workingArray[workingArrayIndex] != '\0')
    {
        putchar(workingArray[workingArrayIndex]);
        ++workingArrayIndex;
    }

    if(arrayOverflow == TRUE)
    {
        printf("\nARRAY OVERFLOW: Output truncated at %d characters.\n",
                MAX_ARRAY_SIZE -2);
    }

    return 0;
}
