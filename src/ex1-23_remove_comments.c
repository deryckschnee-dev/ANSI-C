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
    int inQSA = IS_FALSE; // inside '  only one level deep
    int inQSQ = IS_FALSE; // inside "  only one level deep
    int inQSP = IS_FALSE; // inside ()
    int inQSB = IS_FALSE; // inside {}

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
    
    // This part copies contents of the file into workingArray.
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

    // This part evaluates workingArray and outputs to the console.
    workingArrayIdx = 0;
    while ((character = workingArray[workingArrayIdx]) != '\0') {
	// printf("%c", character);
	if (inQSA == IS_FALSE && inQSQ == IS_FALSE) {
	    if (character == '/') {
		++workingArrayIdx;
		if ((character = workingArray[workingArrayIdx]) != '\0' \
		&& character == '/') {
		    // In single-line comment.
		    ++workingArrayIdx;
		    while ((character = workingArray[workingArrayIdx]) \
		    != '\n' && character != '\0') {
			// Do nothing with comment characters. Look for end.
			++workingArrayIdx;
		    }
		} else if ((character = workingArray[workingArrayIdx]) \
		!= '\0' && character == '*') {
		    // In multi-line comment.
		    while ((character = workingArray[workingArrayIdx]) \
		    != '\0') {
			// Do nothing with comment characters. Look for end.
			if (character == '*') {
			    ++workingArrayIdx;
			    if ((character = workingArray[workingArrayIdx]) \
			    != '\0') {
				if (character == '/') { break; }
				// else continue while loop.
			    }
			}
			++workingArrayIdx;
		    }
		} else {
		    // Not in a comment.
		    --workingArrayIdx;
		    character = workingArray[workingArrayIdx];
		    printf("%c", character);
		    ++workingArrayIdx;
		    character = workingArray[workingArrayIdx];
		    printf("%c", character);
		}
	    } else {
		printf("%c", character);
	    }
	} else {
	    // check for ' or " and set state.
	}

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
