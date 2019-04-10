/* a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
int read;
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
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

/* prototypes */
void getChar();
void addChar();
int lex();
int lookup(char);
void getNonBlank();
void getLine();

int main () {
	/* open input data file */
	
	MyFile = fopen("arith.txt", "r");
	// singleLine holds the line retrieved from the data file
	
	getChar();
	do {
		lex();

	} while (nextToken != EOF);

	lex();
	fclose(MyFile);
}

int lookup (char ch) {
	switch (ch) {
		case '(':
			addChar();
			nextToken = LEFT_PAREN;
			break;
		case ')':
			addChar();
			nextToken = RIGHT_PAREN;
			break;
		case '+':
			addChar();
			nextToken = ADD_OP;
			break;
		case '-':
			addChar();
			nextToken = SUB_OP;
		case '*':
			addChar();
			nextToken = MULT_OP;
		case '/':
			addChar();
			nextToken = DIV_OP;
		default:
			addChar();
			nextToken = EOF;
			break;

	}
	return nextToken;
}

void addChar() {
	if (lexLen <= 98)  {
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
		printf("Lexeme: %s\n", lexeme );
	}
	else printf("%s\n", "Error - lexeme is too long." );
}
void getChar() {
		if ((nextChar = getc(MyFile)) != EOF) {
			if (isalpha(nextChar)) {
				charClass = LETTER;
			}

			else if (isdigit(nextChar)) {
				charClass = DIGIT;
			}
			else {
				charClass = UNKNOWN; 
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
			lookup(nextChar);
			getChar();
			break;

		case EOF:
			printf("%s\n","Token is EOF");
			nextToken = EOF;
			lexeme[0] = 'E';
			lexeme[1] = 'O';
			lexeme[2] = 'F';
			lexeme[3] = 0;
			break;

	}
	printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
	return nextToken;
}