/* Exercise 1-22:
 *   Write a program to "fold" long input lines into two or 
 *   more shorter lines after the last non-blank character 
 *   that occurs before the n-th column of input. Make sure 
 *   your program does something intelligent with very long 
 *   lines, and if there are no blanks or tabs before the 
 *   specified column.
 *
 *   Completed on 01-Jan-2024
 *   Deryck S. Schnee
 * 
 */

#include <stdio.h>
#include <tutorial.h>

#define SCREEN_COLUMNS 80
#define TAB_STOP 8
#define MAX_LINE_LENGTH 100000
#define IS_TRUE 1
#define IS_FALSE 0

int main()
{	
	char currentLine[MAX_LINE_LENGTH];
	int currentLineIdx = 0;
	int currentLineLength = 0;
	char currentWord[MAX_LINE_LENGTH - 1]; // Allow for null terminator.
	int currentWordIdx = 0;
	int outputIdx = 0;
	int outputWordLength = 0;
	char character = ' ';
	int inWord = IS_FALSE;
	int columnsRemaining = SCREEN_COLUMNS;

	while ((currentLineLength = ds_GetLine(currentLine, MAX_LINE_LENGTH)) > 0) {
		for (currentLineIdx = 0; (character = currentLine[currentLineIdx]) != '\0'; ++currentLineIdx) {
			if (inWord == IS_TRUE) {
				if (character == '\t' || character == ' ' || character == '\n') {
					// output current word to console
					if (currentWordIdx < columnsRemaining) {
						// It fits.
						outputWordLength = currentWordIdx;
						for (outputIdx = 0; outputIdx < outputWordLength; ++outputIdx) {
							printf("%c", currentWord[outputIdx]);
							--columnsRemaining;
						}
						if (columnsRemaining == 0) {
							printf("\n");
							columnsRemaining = SCREEN_COLUMNS;
						}
					} else {
						// It doesn't fit.
						if (columnsRemaining < SCREEN_COLUMNS) {
							printf("\n");
							columnsRemaining = SCREEN_COLUMNS;
						}
						outputWordLength = currentWordIdx;
						for (outputIdx = 0; outputIdx < outputWordLength; ++outputIdx) {
							if (columnsRemaining == 0) {
								printf("\n");
								columnsRemaining = SCREEN_COLUMNS;
							}
							printf("%c", currentWord[outputIdx]);
							--columnsRemaining;
						}
					}
					inWord = IS_FALSE;
					currentWordIdx = 0;

					// evaluate current character
					if (character == '\t') {
						if (columnsRemaining <= TAB_STOP) {
							printf("\n");
							columnsRemaining = SCREEN_COLUMNS;
						} else {
							printf("\t");
							columnsRemaining = columnsRemaining - (columnsRemaining % TAB_STOP);
						}
					}
					else if (character == ' ') {
						if (columnsRemaining < 1) {
							printf("\n");
							columnsRemaining = SCREEN_COLUMNS;	
						} else {
							printf(" ");
							--columnsRemaining;
						}
					}
					else if (character == '\n') {
						printf("\n");
						columnsRemaining = SCREEN_COLUMNS;
					}
				}
				else {
					currentWord[currentWordIdx] = character;
					++currentWordIdx;
				}
			}
			else {
				// inWord == IS_FALSE
				// evaluate current character
				if (character == '\t') {
					if (columnsRemaining <= TAB_STOP) {
						printf("\n");
						columnsRemaining = SCREEN_COLUMNS;
					} else {
						printf("\t");
						columnsRemaining = columnsRemaining - (columnsRemaining % TAB_STOP);
					}
				}
				else if (character == ' ') {
					if (columnsRemaining < 1) {
						printf("\n");
						columnsRemaining = SCREEN_COLUMNS;	
					} else {
						printf(" ");
						--columnsRemaining;
					}
				}
				else if (character == '\n') {
					printf("\n");
					columnsRemaining = SCREEN_COLUMNS;
				}
				else {
					currentWordIdx = 0;
					currentWord[currentWordIdx] = character;
					++currentWordIdx;
					inWord = IS_TRUE;
				}
			}
		}
	}
	return 0;
}