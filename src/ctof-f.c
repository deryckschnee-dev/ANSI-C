#include <stdio.h>

/* print Celsius-Farenheit table
    for celsius = 0, 20, ..., 300; floating-point version */

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;   // lower limit of temperature table
    upper = 45;    // upper limit of temperature table
    step = 3;      // step size

    // print temperature table
    printf("\n");
    printf("   C \t   F \n");
    printf("-----\t------\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (celsius * 1.8) + 32;          // F = (C x 1.8) + 32
        printf("%5.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}