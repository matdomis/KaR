/*
Exercise 3-6. 
Write a version of itoa that accepts three arguments instead of two. 
The third argument is a minimum field width; 
the converted number must be padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <string.h>

void itoa(int, char[], int);
void reverse(char[]);

int main() {
	int n;
	char s[100];

	scanf("%d", &n);
	itoa(n, s, 6);

	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[], int f) {
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	for(i = 0 ; i < f ; i++)
		s[i] = ' ';

	i = 0;
	
	do {
		s[i++] = (n % 10) + '0';
	} while((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	
	if(i < f)
		s[f] = '\0';
	else
		s[i] = '\0';

	reverse(s);
}

void reverse(char s[]) {
	char c; 
	int i, j; 
	for(i = 0, j = strlen(s)-1 ;  i < j ; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}