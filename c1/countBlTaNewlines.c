/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

void main() {
	char c;
	int nb, nt, nn;
	nb = nt = nn = 0;
	for(; (c = getchar()) != EOF ;)
		if (c == ' ') ++nb;
		else if (c == '\t') ++nt;
		else if (c == '\n') ++nn;

	printf("blanks = %d, tabs = %d, newlines = %d\n", nb, nt, nn);
}