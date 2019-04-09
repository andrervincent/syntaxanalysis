/* a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int main () {
	/* open input data file */
	FILE * MyFile;
	MyFile = fopen("arith.txt", "r");
	// singleLine holds the line retrieved from the data file
	char singleLine[150];
	while (!feof(MyFile)) {
		fgets(singleLine, 150, MyFile);
		printf("%s\n", singleLine );
	}

	fclose(MyFile);
}