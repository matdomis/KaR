/*
Exercise 2-9. 
In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x . Explain why. Use this observation to write a faster version of bitcount.
*/

#include <stdio.h>

int bitcount(unsigned);

int main() {
	unsigned x;
	x = 100; 			// 1100100
	int n;
	n = bitcount(x);
	printf("%d\n", n); 	// 3
	return 0;
}

int bitcount(unsigned x) {
	int i;
	for(i = 0 ; x != 0 ; i++) x &= (x-1);
	return i;
}