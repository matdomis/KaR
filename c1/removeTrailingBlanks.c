/*
Exercise 1-18. 
Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAX 1000

int get_line(char []);

int main() {
	char line[MAX];
	int n;

	for(; (n = get_line(line)) != -1 ;)
		if (n > 0)
			printf("%s\n", line);
	return 0;
}

int get_line(char line[]) {
	char c, lastchar;
	int len;

	len = 0;
	for(; (c = getchar()) != EOF && c != '\n' ;) {
		if ((c == ' ' || c == '\t') && (lastchar == ' ' || lastchar == '\t')) continue;
		else
			line[len++] = c;

		lastchar = c;
	}
	
	line[len] = '\0';

	if (c == '\n' && len == 0)
		return 0;
	else if (c == EOF)
		return -1;
	else
		return len;
}