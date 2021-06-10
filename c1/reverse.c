/*
Exercise 1-19. 
Write a function reverse(s) that reverses the character string s. 
Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAX 1000

int get_line(char []);
int reverse(char [], int);

int main() {
	char line[MAX];
	int len;

	for(; (len = get_line(line)) >= 0 ;) {
		reverse(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int get_line(char line[]) {
	char c;
	int i;

	for(i = 0 ; (c = getchar()) != EOF && c != '\n' ; i++) line[i] = c;
	line[i] = '\0';

	if (c == '\n' && i == 0)
		return 0;
	else if (c == EOF)
		return -1;
	else 
		return (i-1);
}

void copy(char from[], char to[]) {
	for (int i = 0 ; from[i] != '\0' ; i++)
		to[i] = from[i];
}

int reverse(char line[], int tam) {
	char auxline[MAX];
	int i, pos;
	copy(line, auxline);

	for(i = tam, pos = 0 ; i >= 0 ; i--, pos++)
		line[i] = auxline[pos];

	return 0;
}