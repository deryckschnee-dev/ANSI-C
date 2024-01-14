/* Exercise 1-23
    Write a program to remove comments from a C program. 
    
    Completed on DD-Mmm-YYYY 
    Deryck S Schnee
    
*/

#include <stdio.h>
#include <tutorial.h>

#define MAX_STREAM 100000
#define IS_FALSE 0
#define IS_TRUE 1

int main() {

    int inQSApostLvl = 0;
    int inQSQuoteLvl = 0;
    int inQSParenLvl = 0;
    int inQSBrackLvl = 0;

    char inputStream[MAX_STREAM];
    int inputStreamIdx = 0;
    int inputStreamLen = 0;

    char character;
    
    int inCommentMulti = IS_FALSE;
    int inCommentSingl = IS_FALSE;

    while ((inputStreamLen = ds_GetLine(inputStream, MAX_STREAM)) > 0) {
        for (inputStreamIdx = 0; (character = inputStream[inputStreamIdx]) != '\0'; ++inputStreamIdx) {

            printf("%c", character);	// Test line to print all characters as read from line.

        }
    }

    return 0;
}
