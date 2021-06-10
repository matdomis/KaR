/*
Exercise 1.15 
Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.
*/

#include <stdio.h>

float converse(int);

void main() {
	int C;
	float F;
	scanf("%d", &C);
	F = converse(C);
	printf("%3.2f\n", F);
}

float converse(int C) {
	return ((C/(5.0/9.0)) + 32);
}