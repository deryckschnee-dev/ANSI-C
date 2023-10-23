/* count lines, tabs, and spaces in input
*/

#include <stdio.h>

int main (void)
{
    int c, newline, tab, space;

    newline = 0;
    tab = 0;
    space = 0;

    c = getchar();
    while (c != EOF)
    {
        if (c == '\n')
        {
            ++newline;
        }
        else if (c == '\t')
        {
            ++tab;
        }
        else if (c == ' ')
        {
            ++space;
        }
        
        c = getchar();
    }
    printf("Lines: %d\n", newline);
    printf("Tabs: %d\n", tab);
    printf("Spaces: %d\n", space);

    return 0;
}