/* a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
int lexLen;
char nextChar;
int nextToken;
FILE * MyFile;

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

#define IDENT 11
#define INT_LIT 10

/* prototypes */
void getChar();
void addChar();
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

void addChar() {
	if (lexLen <= 98)  {
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else printf("%s\n", "Error - lexeme is too long." );
}
void getChar() {
		if ((nextChar = getc(MyFile)) != EOF) {
			if (isalpha(nextChar)) {
				charClass = LETTER;
				printf("%s\n", "This a letter." );
				printf("%c\n", nextChar);
			}

			else if (isdigit(nextChar)) {
				charClass = DIGIT;
				printf("%s\n", "This a digit" );
				printf("%c\n", nextChar);
			}
			else {
				charClass = UNKNOWN; 
				printf("%s\n", "Unknown character." );
				printf("%c\n", nextChar);
			}
		}
		else 
			charClass = EOF;
	}
// Function to skip over spaces	
void getNonBlank() {
	while (isspace(nextChar))
		getChar();
}	

int lex() {
	lexLen = 0;
	getNonBlank();
	switch (charClass) {
		/* possible parse identifiers */
		case LETTER:
			addChar();
			getChar();
			while (charClass == LETTER || charClass == DIGIT) {
				addChar();
				getChar();
			}
		nextToken = IDENT;
		break;

		case DIGIT:
			addChar();
			getChar();
			while (charClass == DIGIT) {
				addChar();
				getChar();
			}
			nextToken = INT_LIT;
			break;

		case UNKNOWN:
			//lookup(nextChar);
			getChar();
			break;
		case EOF:
			nextToken = EOF;
			lexeme[0] = 'E';
			lexeme[1] = 'O';
			lexeme[2] = 'F';
			lexeme[3] = 0;
			break;

	}
	
	return 0;
}