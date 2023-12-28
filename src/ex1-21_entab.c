/* Exercise 1-21:
    Write a program entab that replaces strings of blanks by the minimum number 
    of tabs and blanks to achieve the same spacing. Use the same tab stops as 
    for detab. When either a tab of a single blank would suffice to reach a tab 
    stop, which should be given preference?

    Completed on 27-Dec-2023
    Deryck S. Schnee

    My proposed program flow:
     Get current line and place into working array. Read each character from 
     working array and place into line output array with using special condition
     when encountering strings of blanks.

     Simplest should be to leave tabs as is, and replace 8 consecutive spaces
     THAT ARE ALIGNED WITH A TAB STOP with a tab character.

     Tab stops are every 4 columns.

*/

#include <stdio.h>
#include <tutorial.h>

#define TAB_STOP 8
#define MAX_LINE_LENGTH 1000

int main()
{
    char lineIn[MAX_LINE_LENGTH];
    char lineOut[MAX_LINE_LENGTH];

    char character;

    int lineInLength;
    int indexLineIn;
    int indexLineOut;
    int spaces;
    int indexColumn;

    while ((lineInLength = ds_GetLine(lineIn, MAX_LINE_LENGTH)) > 0)
    {
        indexLineIn = 0;
        indexLineOut = 0;
        indexColumn = 0;

        while ((character = lineIn[indexLineIn]) != '\0')
        {
            if (character == ' ') 
            {
                spaces = 0;
                while ((character = lineIn[indexLineIn]) == ' ' && spaces <= TAB_STOP)
                {
                    ++indexLineIn;
                    ++indexColumn;
                    ++spaces;
                }

                if (spaces == TAB_STOP && indexColumn % TAB_STOP == 0)
                {
                    lineOut[indexLineOut] = '\t';
                    ++indexLineOut;
                    spaces = 0; 
                }
                else
                {
                    while (spaces > 0)
                    {
                        lineOut[indexLineOut] = ' ';
                        ++indexLineOut;
                        --spaces;
                    }
                }
            }
            else
            {
                lineOut[indexLineOut] = character;
                ++indexLineIn;
                ++indexLineOut;
                ++indexColumn;
            }
        }
        lineOut[indexLineOut] = '\0';
        printf("%s", lineOut);
    }

    return 0;
}