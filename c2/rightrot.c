/*
Exercise 2-8. 
Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/

#include <stdio.h>

// Control the quantity of BITS
#define BITS 8


unsigned rightrot(unsigned, unsigned);

int main() {
	unsigned x = 178; // 1011 0010
	unsigned result;

	unsigned n = 3;
	result = rightrot(x, n); // result shoud be 0101 0110 = 86

	printf("%u\n", result);
	return 0;
}

unsigned rightrot(unsigned x, unsigned n) {
	// Shift the last n-bits of x to the left-most first n-bits, assign this to mask.
	
	unsigned mask;
	mask = ~0;					// 1111 1111
	mask = mask << n;			// 1111 1000
	mask = ~mask;				// 0000 0111
	mask = x & mask;			// 0000 0010 (get end of n-bits)
	mask = mask << (BITS-n);	// 0100 0000 (shift to left-most side)

	// Now just bitwise or the two numbers:	  (x>>n)     (mask)
	return (x >> n) | mask;     //          0001 0110 | 0100 0000
}