/*  print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version
*/

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 115;    /* upper limit of temperature table */
    step = 5;       /* step size */

    /* print temperature table */
    printf("\n");
    printf("   F \t   C \n");
    printf("-----\t------\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%5.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}