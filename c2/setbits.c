 /*	
Exercise 2-6. 
Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y , leaving the other bits unchanged. 
*/

#include <stdio.h>

unsigned setbits(unsigned, int, int, unsigned);

// Examples:
// 178 = 1011 0010 (x)
// 219 = 1101 1011 (y)
// 218 = 1101 1010 (z)

int main() {
	unsigned x = 178;
	unsigned y = 219;
	unsigned z;

	// change what's inside the brackets to what's inside the parenthesis
	// x = 1[0110]010 ; y = 1101(1011) 
	
	int p = 7;
	int n = 4;

	z = setbits(x, p, n, y);

	printf("%u\n", z);
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	int mask;
	int aux;
	
	// First part: set 0 all the n-bits from x starting from position p.
	mask = 0;				// 0000 0000
	mask = ~mask;			// 1111 1111
	mask = mask << p;		// 1000 0000
	
	aux = ~0;				// 1111 1111
	aux = aux << (p-n);		// 1111 1000
	aux = ~aux;				// 0000 0111
	
	mask = mask | aux;		// 1000 0111

	x = x & mask; 			// 1011 0010 & 1000 0111 = 1000 0010

	// Second part: shift the right most n-bits from y to respective n-bits from x.
	mask = ~0;
	mask = mask << n;
	mask = ~mask;
	y = y & mask;
	y = y << (p-n);

	return (x | y);
}

