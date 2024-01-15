/* Data: Program file to test for proper evaluation of C-style comments.
 *
 * This program should contain normal single and multi-line comments, as well 
 * as characters associated with comments encapsulated by quotes and other 
 * program brackets.
 *
 * Last updated on 14-Jan-2024
 * Deryck S Schnee
 *
 */

#include <stdio.h>

int main() {
    int numer = 20;
    int denom = 4;
    int result = 0;
    
    // print first type of comment here
    printf("A C-style single-line comment looks like this: \n\n");
    printf("// This is a comment!\n\n");

    /* print second type
       of comment
       here
    */
    printf("A C-style multi-line comment looks like this: \n\n");
    printf("/* This is a\nmulti-line\ncomment! */\n\n");

    result = numer / denom;
    printf("The result of %d divided by %d is: %d", numer, denom, result);
    printf("\n\n\n"); //    Put some additional line feeds just 'cause.
		      //
    printf("End.\n");

    return 0;
}
