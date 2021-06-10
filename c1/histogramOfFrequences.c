/*
Exercise 1-14. 
Write a program to print a histogram of the frequencies of different characters
in its input.
*/

// Note: This resolution only deals with alphabet characters like 'a' and 'A'.

#include <stdio.h>

#define NUMOFCHARS 26

void main() {
	int charsFrequence[NUMOFCHARS];
	char c;
	int i;

	for(i = 0 ; i < NUMOFCHARS ; i++)	
		charsFrequence[i] = 0;

	for(; (c = getchar()) != EOF ;)
		if ((c >= 'a') && (c <= 'z'))
			charsFrequence[c-'a']++;
		else if ((c >= 'A') && (c <= 'Z'))
			charsFrequence[c-'A']++;

	printf("\nHistogram\n");
	
	for(i = 0 ; i < NUMOFCHARS ; i++) {
		printf("|%c%c|", 'A'+i, 'a'+i);
		for(int j = 0 ; j < charsFrequence[i] ; j++)
			putchar('*');
		printf("\n");
	}
}