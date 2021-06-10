/*
Exercise 1-9. 
Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
*/

#include <stdio.h>

void main() {
	char c, lastchar;

	for(; (c = getchar()) != EOF ;) {
		if ((c == ' ' && lastchar != ' ') || (c != ' ' && lastchar != ' ') || (c != ' ' && lastchar == ' '))
			putchar(c);
		lastchar = c;
	}
}