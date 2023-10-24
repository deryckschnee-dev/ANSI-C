/* program to test exponentiation function 
*/

#include <stdio.h>

int power(int, int);    /* function prototype */

int main()
{
    int loopIndex;

    for(loopIndex = 0; loopIndex < 10; ++loopIndex)
    {
        printf("%d %d %d\n", loopIndex, power(2, loopIndex), power(-3, loopIndex));
    }

    return 0;
}

int power(int baseNumber, int exponentNumber)   /* function definition */
{
    int loopIndex;
    int result = 1;

    for(loopIndex = 1; loopIndex <= exponentNumber; ++loopIndex)
    {
        result = result * baseNumber;
    }

    return result;

}
