#include <stdio.h>
#include <DS\tutorial.h>

#define NUM_1 5
#define NUM_2 16

int main()
{
    int result;

    result = Test(NUM_1, NUM_2);
    printf("%d + %d = %d\n", NUM_1, NUM_2, result);

    result = TestTwo(NUM_1, NUM_2);
    printf("%d * %d = %d\n", NUM_1, NUM_2, result);

    return 0;
}