/* Write a function that reverses the order of a character string. Use it to 
    write a program that reverses its input one line at a time.
    
    Deryck Schnee
    Completed on dd-Mmm-yyyy
    
*/

/* Program Flow:
    - read line into working array.
    - output characters from working array to console in reverse order.
    - repeat for remaining lines in input.

    Will use my function ds_GetLine to read each line into working array.

*/

#include <stdio.h>
#include <DS\tutorial.h>

#define MAX_ARRAY_SIZE 10000

int main()
{
    int lineLength = 0;
    int arrayPosition = 0;
    char workingArray[MAX_ARRAY_SIZE];
    
    lineLength = ds_GetLine(workingArray, MAX_ARRAY_SIZE);  /* Get inital line */
    while(lineLength > 0)
    {

        lineLength = ds_GetLine(workingArray, MAX_ARRAY_SIZE); /* Get next line*/
    }

    return 0;
}