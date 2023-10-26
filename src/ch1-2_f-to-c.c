/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 
*/

#include <stdio.h>

int main(void)
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      // lower limit of temperature table
    upper = 115;    // upper limit of temperature table
    step = 5;      // step size

    // print temperature table
    printf("   F \t   C \n");
    printf("-----\t-----\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr-32) / 9;
        printf("%5d\t%5d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
