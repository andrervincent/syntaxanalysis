/* a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
int main () {
	/* open input data file */
	FILE * MyFile;
	MyFile = fopen("arith.txt", "r");

	char singleLine[150];
	while (!feof(MyFile)) {
		fgets(singleLine, 150, MyFile);
		printf("%s\n", singleLine );
	}

	fclose(MyFile);
}