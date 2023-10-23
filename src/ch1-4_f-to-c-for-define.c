/* print Farenheit-Celsius table; float, for-loop version with DEFINE STATEMENTS!
*/

#include <stdio.h>

#define LOWER   0       // lower limit of table
#define UPPER   300     // upper limit of table
#define STEP    20      // Farenheit step size

int main(void)
{
    int fahr;

    printf("\n");
    printf("   F \t   C \n");
    printf("-----\t------\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%5d\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }

    return 0;
}