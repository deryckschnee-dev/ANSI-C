/*  print Farenheit-Celsius table; float, for-loop version 
*/

#include <stdio.h>

int main(void)
{
    int fahr;

    printf("\n");
    printf("   F \t   C \n");
    printf("-----\t------\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%5d\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }

    return 0;
}