#include <stdio.h>

/* count number of each digit [0-9], white space, oth ers */

main()
{
    int character;
    int i;
    int numWhitespace;
    int numOther;
    int numDigit[10];

    numWhitespace = 0;
    numOther = 0;

    for (i = 0; i < 10; ++i)
    {
        numDigit[i] = 0;
    }

    character = getchar();
    while (character != EOF)
    {
        if (character >= '0' && character <= '9')
        {
            ++numDigit[character - '0'];
        }
        else if (character == ' ' || character == '\n' || character == '\t')
        {
            ++numWhitespace;
        }
        else
        {
            ++numOther;
        }

        character = getchar();
    }

    printf("digits =");
    for (i = 0; i < 10; ++i)
    {
        printf(" %d", numDigit[i]);
    }
    printf(", whitespace = %d, other = %d\n", numWhitespace, numOther);

}