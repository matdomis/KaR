/*
Exercise 1-5. 
Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.
*/

#include <stdio.h>

void main() {
	float fahr;

	printf("°F\t°C\n");
	for(fahr = 300.0 ; fahr >= 0 ; fahr-=20)
		printf("%3.0f\t%2.1f\n", fahr, (5.0/9.0) * (fahr-32));
}