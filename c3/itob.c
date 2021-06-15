/*
Exercise 3-5. ]
Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. 
In particular, itob(n,s,16) formats s as a hexadecimal integer in s .
*/

#include <stdio.h>
#include <string.h>

int itob(int, char [], int);
void reverse(char[]);

int main() {
	char s[100];
	int n, b;

	printf("Input the integer: "); scanf("%d", &n);
	printf("Input the base: "); scanf("%d", &b);

	itob(n, s, b);

	printf("%s\n", s);
	return 0;
}

// Assume the limit of input as 0 < base < 16
int itob(int n, char s[], int b) {
	int rest, sign;
	int i = 0;
	char hexnumbers[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	if ((sign = n) < 0)
		n = -n;
	
	do {
		rest = n % b;
		if (rest >= 10)
			s[i++] = hexnumbers[rest-10];
		else
			s[i++] = rest + '0';	
	} while((n /= b) > 0);


	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return 0;
}

void reverse(char s[]) {
	int i, j;
	char c;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}