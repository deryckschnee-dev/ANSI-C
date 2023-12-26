/* Exercise 1-20:
    Write a program detab that replaces tabs in the input with the proper number 
    of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
    say every n columns. Should n be a variable or a symbolic parameter?

    Completed on DD-Mmm-YYYY
    Deryck S. Schnee

    My proposed program flow:
     Get current line and place into working array. Read each character from 
     working array and place into line output array with using special condition
     when encountering a tab character to replace with equivalent number of 
     spaces.

     Tab stops are every 8 columns. (Windows Powershell default)

*/

#include <stdio.h>
#include <tutorial.h>

#define TAB_STOP 8
#define MAX_LINE_LENGTH 1000

int main()
{
    int lineLength;
    int i;
    int space;
    int column;

    char character;
    char workingArray[MAX_LINE_LENGTH];
    char outputArray[MAX_LINE_LENGTH];
    
    while ((lineLength = ds_GetLine(workingArray, MAX_LINE_LENGTH)) > 0)
    {
        column = 0;
        for (i = 0; (character = workingArray[i]) != '\0'; ++i)
        {
            if (character == '\t')
            {
                for (space = column % TAB_STOP; space < (TAB_STOP - 1); ++space)
                {
                    outputArray[i] = '.';
                    ++i;
                }
                i = i - (column % TAB_STOP);
            }
            else
            {            
                outputArray[i] = workingArray[i];
            }
            ++column;
        }
        outputArray[i] = '\0';
        ++i;

        printf("%s", outputArray);
    }

    return 0;
}