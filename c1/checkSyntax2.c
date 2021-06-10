/*
Exercise 1-24. 
Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)
*/

#include <stdio.h>

#define MAX 10000

#define IN 1
#define OUT 0

#define ERROR 0
#define SUCCESS 1

void getsource(char[]);
int checksyntax(char[]);

void main(void) {
    char source[MAX];

    getsource(source);

    if(checksyntax(source))
        printf("OK!");
    else
        printf("NOP!\n");

}

void getsource(char s[]) {
    int i;
    char c;
    for(i = 0 ; (c = getchar()) != EOF ; i++) s[i] = c;
    s[i] = '\0';
}

int checksyntax(char source[]) {
  int parentheses = 0;
  int brackets = 0;
  int braces = 0;

  // In and out variables
  int quotes = OUT;
  int comments = OUT;
  
  char typeOfQuote;
  char lastc;
  char c;
  for(int i = 0 ; source[i] != '\0' ; i++) {
  	c = source[i];

		// Check comments
		if (!quotes && lastc == '/' && c == '*')
			comments = IN;
		else if (!quotes && lastc == '*' && c == '/')
			comments = OUT;

		// Check quotes
		if (!comments && !quotes && (c == '\"' || c == '\'')) {
			typeOfQuote = c;
			quotes = IN;
		}
		// note: source[i+1] is for handling the '\'' cases like in this source code
		else if (quotes && c == typeOfQuote && source[i+1] != '\'') 
			quotes = OUT;

		// Count each one of the keychars
		if (!comments && !quotes) {
			if (source[i] == '(')
				parentheses++;
			else if (source[i] == ')')
				parentheses--;
		
			if (source[i] == '[')
				brackets++;
			else if (source[i] == ']')
				brackets--;

			if (source[i] == '{')
				braces++;
			else if (source[i] == '}')
				braces--;
		}

		// Check if there is one closing keychar disbalanced
		if ((parentheses < 0) || (braces < 0) || (brackets < 0))
			return ERROR;

  	lastc = c;	 
  }
 		 
	// Check if the keychars are balanced (sum of each keychars is equal to 0)
	// If not returns ERROR
	if ((parentheses != 0) || (braces != 0) || (brackets != 0))
  			return ERROR;
	return SUCCESS;

}
