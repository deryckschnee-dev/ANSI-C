/* Write a function that reverses the order of a character string. Use it to 
    write a program that reverses its input one line at a time.
    
    Deryck Schnee
    Completed on 12-Dec-2023
    
*/

/* Program Flow:
    - read line into working array.
    - output characters from working array to console in reverse order.
    - repeat for remaining lines in input.

    Will create new function ds_ReverseLine to read each line into temp array, 
    reverse the character order writing to working array.

*/

#include <stdio.h>
#include "tutorial.h"

#define MAX_ARRAY_SIZE 10000
#define MAX_LINE_LENGTH 200


int main()
{
    int lineLength = 0;
    int arrayPosition = 0;
    char workingArray[MAX_ARRAY_SIZE];

    lineLength = ds_ReverseLine(workingArray, MAX_LINE_LENGTH);  /* Get inital line */
    while(lineLength > 0)
    {
        for(arrayPosition = 0; workingArray[arrayPosition] != '\0'; ++arrayPosition)
        {
            putchar(workingArray[arrayPosition]);
        }

        lineLength = ds_ReverseLine(workingArray, MAX_LINE_LENGTH); /* Get next line*/
    }
    
    return 0;
}