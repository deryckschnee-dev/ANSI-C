#include <stdio.h>

int main()
{
    int character = 0;
    int insideWord = 0;
    int lengthOfWord = 0;

    character = getchar();

    while (character != EOF)
    {
        if (character == ' ' || character == '\t' || character == '\n')
        {
            insideWord = 0;
        }
        else
        {
            insideWord = 1;
            lengthOfWord++;
            
        }
        
        
        
        putchar(character);

        character = getchar();

    }

    return 0;
}