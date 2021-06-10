/*
Exercise 1-7. Write a program to print the value of EOF .
*/

#include <stdio.h>

void main() {
	char c;
	for(; (c = getchar()) ;)
		if (c == EOF) {
			printf("%d\n", EOF);
			break;
		}
}