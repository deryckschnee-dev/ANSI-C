#include <stdio.h>

/* copy input to output. edit */

int main (void)
{
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }

    return 0;
}