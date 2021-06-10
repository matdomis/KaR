/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAX 1000

int get_line(char[]);

int main() {
	char line[MAX];
	int n;
	
	for(; (n = get_line(line)) > 0 ;)
		if (n > 80) {
			printf("%s\n", line);
		}
		
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