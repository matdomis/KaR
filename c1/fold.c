/*
Exercise 1-22. 
Write a program to "fold" long input lines into two or more shorter lines after
the last non-blank character that occurs before the n -th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

#include <stdio.h>

#define MAX 1000
#define N 10

int get_line(char[]);
int fold(char[], int);
void copy(char[], char[]);

int main() {
	char line[MAX+1]; 
	int i;

	get_line(line);

	for(i = 0 ;	line[i] != '\0' ; i++) {
		if ((i+1) % N == 0) {
			fold(line, i);
		}
	}

	printf("%s\n", line);
}

/* 	Scheme of fold():
	The main objective is to add '\n' character
	after the last non-blank char before the
	n-th element, with in this case is each 10
	elements.

	Algorithm:
	Creates v[MAX] as a aux vector to copy
	the elements of line[n...MAX] to line[n+1...MAX+1]
	replacing the element n with '\n'.

	Simulates some kind of dinamic vector with normal vector.
*/

/* 
	  obs: the program are folding before the
		last non-blank character
*/

int fold(char line[], int foldpos) {
	char v[MAX+1];
	int i, j;

	copy(line, v);

	while(line[foldpos] == ' ' || line[foldpos] == '\t') 
		foldpos--;

	line[foldpos] = '\n';	
	
	for(i = foldpos+1 , j = foldpos ; v[j] != '\0' ; i++, j++)
		line[i] = v[j];
	line[i] = '\0';

	return 0;
}

void copy(char from[], char to[]) {
	int i;
	for(i = 0 ; from[i] != '\0' ; i++)
		to[i] = from[i];
	to[i] = '\0';
}

int get_line(char line[]) {
	char c;
	int i;
	for(i = 0 ; (c = getchar()) != EOF && c != '\n' ; i++) line[i] = c;
	line[i] = '\0';
	return i;
}