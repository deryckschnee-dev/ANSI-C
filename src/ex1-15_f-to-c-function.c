/*  Rewrite the temperature conversion program from chapter 1-2 
    using a function to perform the conversion.

    Deryck Schnee
    Completed on 23-Oct-2023
*/

#include <stdio.h>

int convertTempToC(int);  /* function prototype */

int main(void)
{
    int tempInF, tempInC;
    int lowerLimit, upperLimit, stepSize;

    lowerLimit = 0;
    upperLimit = 115;
    stepSize = 5;

    printf("   F \t   C \n");
    printf("-----\t-----\n");
    tempInF = lowerLimit;
    while (tempInF <= upperLimit)
    {
        tempInC = convertTempToC(tempInF);
        printf("%5d\t%5d\n", tempInF, tempInC);
        tempInF = tempInF + stepSize;
    }

    return 0;
}

int convertTempToC(int tempInF)     /* function definition */
{
    int result;
    
    result = 5 * (tempInF-32) / 9;
    return result;
}