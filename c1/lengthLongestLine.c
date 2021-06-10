/*
Exercise 1-16. 
Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.
*/

#include <stdio.h>

#define MAX 1000

int get_line(char[]);
void copy(char[], char[]);

int main() {
	char line[MAX], longest[MAX];
	int n, max;
	
	max = 0;
	for(; (n = get_line(line)) > 0 ;)
		if (n > max) {
			max = n;
			copy(line, longest);
		}
		
	printf("\nlongest line was:\n\"%s\"\nhis length is %d\n", longest, max);
	return 0;
}

int get_line(char s[]) {
	char c;
	int i;

	for(i = 0 ; (c = getchar()) != '\n' ; i++)
		s[i] = c;
	s[i] = '\0';

	return i;
}

void copy(char from[], char to[]) {
	int i;
	for(i = 0 ; from[i] != '\0' ; i++)
		to[i] = from[i];
	to[i] = '\0';
}
