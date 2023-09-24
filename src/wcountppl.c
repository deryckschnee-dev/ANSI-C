#include <stdio.h>

#define IN  1       /* inside a word */
#define OUT 0       /* outside a word */

/* print words from input, one word per line */

main()
{
    int character;
    int state;

    character = getchar(); 
    state = OUT;

    while (character != EOF)
    {
        if (character == ' ' || character == '\t' || character == '\n')
        {
            while (character == ' ' || character == '\t' || character == '\n')
            {
                character = getchar();
            }
            printf("\n");
            putchar(character);
            
        } else {
            putchar(character);
        }
        
        character = getchar();
    }
}