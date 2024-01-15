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

int main(int argc, char *argv[]) {
    int inQSApostLvl = 0;
    int inQSQuoteLvl = 0;
    int inQSParenLvl = 0;
    int inQSBrackLvl = 0;

    char inputStream[MAX_STREAM];
    int inputStreamIdx = 0;
    int inputStreamLen = 0;

    char workingArray[MAX_STREAM];
    int workingArrayIdx = 0;

    int combinedIdx = 0;
    
    char character;
    
    int inCommentMulti = IS_FALSE;
    int inCommentSingl = IS_FALSE;

/*    while ((inputStreamLen = ds_GetLine(inputStream, MAX_STREAM)) > 0) {
        for (inputStreamIdx = 0; (character = inputStream[inputStreamIdx]) \
	!= '\0'; ++inputStreamIdx) {
	    combinedIdx = inputStreamIdx + workingArrayIdx;
	    workingArray[combinedIdx] = character;
	    ++workingArrayIdx;
        }
    }
    workingArray[workingArrayIdx] = '\0';
*/
    FILE *fp;
    void filecopy(FILE *, char *);
    
    if (argc == 1) {
	printf("No filename specified! Ex: ex1-23 filename.c\n\n");
    }
    else {
	while (--argc > 0) {
	    if ((fp = fopen(*++argv, "r")) == NULL) {
		printf("ex1-23: cannot open %s\n", *argv);
		return 1;
	    } else {
		filecopy(fp, workingArray);
		fclose(fp);
	    }
	}
    }

    workingArrayIdx = 0;
    // Begin evaluation of workingArray here.
    while ((character = workingArray[workingArrayIdx]) != '\0') {
	printf("%c", character);
	++workingArrayIdx;
    }

    return 0;
}

/* filecopy: copy file ifp to char ofp */
void filecopy(FILE *ifp, char *ofp) {
    int c;
    int i = 0;	// modified this function from the book to copy from
		// a file to a character array, instead of from file to file.

    while ((c = getc(ifp)) != EOF) {
	ofp[i] = c;
	++i;
//	putc(c, ofp);
    }
}
