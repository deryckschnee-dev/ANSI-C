/* Exercise 1-20:
    Write a program detab that replaces tabs in the input with the proper number 
    of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
    say every n columns. Should n be a variable or a symbolic parameter?

    Completed on 26-Dec-2023
    Deryck S. Schnee

    My proposed program flow:
     Get current line and place into working array. Read each character from 
     working array and place into line output array with using special condition
     when encountering a tab character to replace with equivalent number of 
     spaces.

     Tab stops are every 8 columns.

*/

#include <stdio.h>
#include <tutorial.h>

#define TAB_STOP 8
#define MAX_LINE_LENGTH 1000

int main()
{
    int lineLength;
    int i;
    int j;
    int spaces;
    int column;

    char character;
    char workingArray[MAX_LINE_LENGTH];
    char outputArray[MAX_LINE_LENGTH];
    
    while ((lineLength = ds_GetLine(workingArray, MAX_LINE_LENGTH)) > 0)
    {
        column = 0;
        j = 0;
        for (i = 0; (character = workingArray[i]) != '\0'; ++i)
        {
            if (character == '\t')
            {
                spaces = TAB_STOP - (column % TAB_STOP);

                while (spaces > 0)
                {
                    outputArray[j] = '.';
                    ++column;
                    ++j;
                    --spaces;
                }
            }
            else
            {            
                outputArray[j] = character;
                ++column;
                ++j;
            }
        }
        outputArray[j] = '\0';

        printf("%s", outputArray);
    }

    return 0;
}