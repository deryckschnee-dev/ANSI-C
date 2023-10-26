/* Write a program to print all input lines 
    that are longer than 80 characters. 
    
    Deryck Schnee
    Completed on dd-Mmm-yyyy
    
*/

/* Program Flow:
    -Read line into working array and determine length.
    -For lines that exceed 80 characters in length, append to combined array.
    -Output lines in combined array.
*/

#include <stdio.h>
#include <DS\tutorial.h>

#define MIN_LINE_LENGTH 80
#define MAX_LINE_LENGTH 1000

int characterIndex;
int lineLength;

char character;
char workingArray[1000];
char combinedArray[100000];

int main()
{
    characterIndex = 0;
    

    character = getchar();         /* get initial character */
    lineLength = 0; /* TODO: GetLine function */
    while(/* TODO: GetLine > 0 */)
    {
        
        
        character = getchar();     /* get next character */
        characterIndex++;
    }

    return 0;
}