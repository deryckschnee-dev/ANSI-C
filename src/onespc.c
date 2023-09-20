#include <stdio.h>

/* copy input to output and replace multiple spaces with one space */

int main(void)
{
    int c;

    // get initial character.
    c = getchar();
    
    // get remaining characters, until EOF.
    while (c != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while (c == ' ')
            {
                c = getchar();
            }
            putchar(c);
            
        } else {
            putchar(c);
        }
        
        c = getchar();
    }

    return 0;
}