/*
Exercise 1-13. 
Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>

#define MAXWORDSIZE 10
#define MAXWORDS 1000
#define IN 1
#define OUT 0

void main() {
	char c;

	int lengths[MAXWORDS];
	int wordstart = OUT;
	int pos = 0;

	int i = 0;

	for(; (c = getchar()) != EOF ;) {
		if ((c == ' ' || c == '\t' || c == '\n') && (wordstart == IN)) {
			lengths[pos++] = i;
			i = 0;
			wordstart = OUT;
		}
		if (c != ' ' && c != '\n' && c != '\t')
			wordstart = IN;
		if (wordstart)
			i++;
	}

	for(i = 1 ; i <= MAXWORDSIZE+1 ; i++) {
		if (i <= MAXWORDSIZE)
			printf("%3d |", i);
		else
			printf(">10 |");

		for(int j = 0 ; j < pos ; j++) {
			if ((i <= MAXWORDSIZE) && (lengths[j] == i))
				putchar('*');
			if ((i > MAXWORDSIZE) && (lengths[j] > MAXWORDSIZE))
				putchar('*');
		}

		printf("\n");
	}
}