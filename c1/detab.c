/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
			   of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
			   Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define MAX 1000

int get_line(char[]);

int main() {
	char line[MAX];
	int len, i, j;
	
	len = get_line(line);

	for(i = 0 ; i < len ; i++)
		if (line[i] == '\t') {
			for(j = i+1 ; line[j] != '\t' && line[j] != '\0' ; j++);
			
			if (line[j] == '\0')
				line[i] = '0';
			else
				line[i] = '0' + (j-i);
		}

	printf("%s\n", line);

	return 0;
}

int get_line(char line[]) {
	char c;
	int i;

	for(i = 0 ; (c = getchar()) != EOF && c != '\n' ; i++)
		line[i] = c;
	line[i] = '\0';

	return i;
}