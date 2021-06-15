/*
Exercise 2-7. 
Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned invert(unsigned, int, int);


int main() {
	unsigned x = 178; 				// 1011 0010
	unsigned result;

	int p = 7;
	int n = 3;

	result = invert(x, p, n);

	printf("%d\n", result);
	return 0;
}

unsigned invert(unsigned x, int p, int n) {
	unsigned aux, cpy, result;

	aux = ~0;
	aux = aux << (p-n);

	cpy = ~0;
	cpy = cpy << p;
	cpy = ~cpy;

	aux = aux ^ cpy; 				// 1000 1111

	aux = x & aux;   				// 1000 0010

	cpy = ~x;						// 0100 1101
	cpy = cpy & ~((~0) << p);		// 0100 1101
	cpy = cpy & ((~0) << (p-n));	// 0100 1101 & 1111 0000 = 0100 0000    
								
	result = aux | cpy;
	return result;					// result = 0100 1101
}