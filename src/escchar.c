#include <stdio.h>

/* copy input to output and replace tabs and backslashes
    with their escape characters: \t, and \\, respectively. */

int main(void)
{
    int c;

    c = getchar();

    while (c != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else
        {
            putchar(c);
        }

        c = getchar();
    }

    return 0;
}