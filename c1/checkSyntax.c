/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
						 	 unmatched parentheses, brackets and braces. Don't forget about quotes, 
						 	 both single and double, escape sequences, and comments. 
*/

/*  Note:
		The program is only dealing with comments of type '//' and Quotes exceptions.
		The program is not dealing with the '/ * * /' type of comments.
		Might fix it later.
		Recommended input: this source code.
*/ 

#include <stdio.h>

#define MAX 10000

#define IN 1
#define OUT 0

#define OK 1
#define ERROR 0

int getsource(char s[]);
	
void main(void) {
	char src[MAX];
	char holdQuote;						// Hold the type of quote
	
	int n, i;

	int output = OK;
	int cbrack[2] = {0, 0};		// cbrack[0,1] = ('{', '}')
	int cpar[2] = {0, 0};			// cpar[0, 1] = ('(', ')')
	int cbraces[2] = {0, 0};	// cbraces[0, 1] = ('[', ']')

	int insideQuotes = OUT;
	int insideComment = OUT;

	n = getsource(src);

	for(i = 0 ; i < n ; i++) {
		if (!insideQuotes && !insideComment)
		{
			switch(src[i])
			{
				case '{':
					cbrack[0]++;
					break;
				case '}':
					cbrack[1]++;
					break;
				case '(':
					cpar[0]++;
					break;
				case ')':
					cpar[1]++;
					break;
				case '[':
					cbraces[0]++;
					break;
				case ']':
					cbraces[1]++;
					break;
				default:
					break;
			}
		}
		
		/* --------------- */
																						// This && conditional deal with
		/* Activate/Deactivate insideQuotes */	// the '\'' problem of quoting exception
		if ((src[i] == '\"' || src[i] == '\'')  && (src[i-1] != '\\' || src[i-2] == '\\') && insideQuotes == IN && src[i] == holdQuote)
		{
			holdQuote = NULL;
			insideQuotes = OUT;
		}
		
		else if ((src[i] == '\"' || src[i] == '\'')  && insideQuotes == OUT)
		{
			holdQuote = src[i];
			insideQuotes = IN;
		}
		
	
		/* Activate/Deactivate insideComment */
		if (src[i] == '/' && src[i+1] == '/' && insideQuotes == OUT)
			insideComment = IN;
		
		else if (src[i] == '\n' && insideComment == IN)
			insideComment = OUT;

		/* -------------- */

		// Unmatch brackets
		if (cbrack[1] > cbrack[0])
		{
			output = ERROR;
			break;
		}

		// Unmatch parentesis
		else if (cpar[1] > cpar[0])
		{
			output = ERROR;
			break;
		}

		// Unmatch braces
		else if (cbraces[1] > cbraces[0])
		{
			output = ERROR;
			break;
		}

	}

	// Check if syntax is balanced (Sum of all symbols must be zero)
	if (cbrack[0] - cbrack[1] != 0)
		output = ERROR;
	else if (cpar[0] - cpar[1] != 0)
		output = ERROR;
	else if ((cbraces[0] - cbraces[1]) != 0)
		output = ERROR;

	if (output)
		printf("OK\n");
	else
		printf("ERROR\n");
}

int getsource(char s[]) {
	char c;
	int i;
	for(i = 0 ; (c = getchar()) != EOF ; i++) 
		s[i] = c;
	s[i] = '\0';
	return i;
}