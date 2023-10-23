/* count lines, words and characters in input
*/

#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

main()
{
    int character, numLines, numWords, numCharacters, state;

    state = OUT;
    numLines = numWords = numCharacters = 0;

    while ((character = getchar()) != EOF)
    {
        ++numCharacters;

        if (character == '\n')
        {
            ++numLines;
        }

        if (character == ' ' || character == '\n' || character == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++numWords;
        }
    }
    printf("%d %d %d\n", numLines, numWords, numCharacters);
}