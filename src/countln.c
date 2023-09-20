#include <stdio.h>

/* count lines in input */

int main (void)
{
    int c, newline;

    newline = 0;

    c = getchar();
    while (c != EOF)
    {
        if (c == '\n')
        {
            ++newline;
        }
        c = getchar();
    }
    printf("%d\n", newline);

    return 0;
}