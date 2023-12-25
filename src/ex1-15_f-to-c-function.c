/*  Rewrite the temperature conversion program from chapter 1-2 
    using a function to perform the conversion.

    Deryck Schnee
    Completed on 23-Oct-2023
*/

#include <stdio.h>
#include "tutorial.h"

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
        tempInC = ds_ConvertTempToC(tempInF);
        printf("%5d\t%5d\n", tempInF, tempInC);
        tempInF = tempInF + stepSize;
    }

    return 0;
}
