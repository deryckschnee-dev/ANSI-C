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
    int inQSA = 0; // inside '  only one level deep
    int inQSQ = 0; // inside "  only one level deep
    int inQSP = 0; // inside ()
    int inQSB = 0; // inside {}

    char inputStream[MAX_STREAM];
    int inputStreamIdx = 0;
    int inputStreamLen = 0;

    char workingArray[MAX_STREAM];
    int workingArrayIdx = 0;

    int combinedIdx = 0;
    
    char character;
    
    int inCM = IS_FALSE; // in multi-line comment.
    int inCS = IS_FALSE; // in single-line comment.

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
    int i = 0;	// modified this function from the book version to copy from
		// a file to a character array, instead of from file to file.

    while ((c = getc(ifp)) != EOF) {
	ofp[i] = c;
	++i;
//	putc(c, ofp);
    }
}
