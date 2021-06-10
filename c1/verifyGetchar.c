/*
Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/

#include <stdio.h>

void main() {
	char c;
	int n;
	for(; (n = (c = getchar() != EOF)) ;)
		printf("%d\n", n);
}