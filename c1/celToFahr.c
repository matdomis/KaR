/*
Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

void main() {
	float fahr, celsius;

	scanf("%f", &celsius);
	fahr = (celsius/(5.0/9.0)) + 32.0;
	printf("%2.1f", fahr);	
}