/* a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
int lexLen;
char nextChar;
FILE * MyFile;

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* prototypes */
void getChar();
int lex();
void getNonBlank();
int main () {
	/* open input data file */
	
	MyFile = fopen("arith.txt", "r");
	// singleLine holds the line retrieved from the data file
	char singleLine[150];
	getChar();
	fclose(MyFile);
}

void getChar() {
		if ((nextChar = getc(MyFile)) != EOF) {
			if (isalpha(nextChar)) {
				charClass = LETTER;
				printf("%s\n", "This a letter." );
			}

			else if (isdigit(nextChar)) {
				charClass = DIGIT;
				printf("%s\n", "This a digit" );
			}
			else {
				charClass = UNKNOWN; 
				printf("%s\n", "Unknown character." );
			}
		}
		else 
			charClass = EOF;
	}
void getNonBlank() {
	while (isspace(nextChar))
		getChar();
}	
int lex() {
	lexLen = 0;
	getNonBlank();
	return 0;
}