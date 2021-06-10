/*
Exercise 1-21. 
Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. 
Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, 
which should be given	preference?
*/

#include <stdio.h>

#define TABWIDHT 5

void main() {
	int b = 0;
	char c;

	for(; (c = getchar()) != EOF ;) {
		if (c == ' ') {
			b++;
			if (b == TABWIDHT) {
				putchar('\t');
				b = 0;
			}
		}
		else {
			for(int i = 0 ; i < b ; i++)
				putchar(' ');
			putchar(c);
			b = 0;
		}
	}
}