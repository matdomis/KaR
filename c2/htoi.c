/*
Exercise 2-3. 
Write a function htoi(s) , which converts a string of hexadecimal digits
(including an optional 0x or 0X ) into its equivalent integer value. 
The allowable digits are 0 through 9 , a through f , and A through F .
*/

#include <stdio.h>
#include <math.h>

int htoi(char[]);

int main() {
	char s[100];
	char c;
	int i, integer;
	printf("Digite o número hexadecimal: ");
	for(i = 0 ; (c = getchar()) != '\n' ; i++) 	s[i] = c;
	integer = htoi(s);
	printf("%d\n", integer);
	return 0;
}

int htoi(char s[]) {
	int i, len, integer;
	integer = 0;
	
	for(len = 0 ; s[len] != '\0' ; len++); // get len of s
	len--;
	
	for(i = 0 ; s[i] != '\0' ; i++) {
		if ((s[i] >= 'A' && s[i] <= 'F'))
			integer += pow(16, len) * (s[i] - 'A' + 10);
		else if ((s[i] >= 'a' && s[i] <= 'f'))
			integer += pow(16, len) * (s[i] - 'a' + 10);
		else
			integer += pow(16, len) * (s[i] - '0');
		len--;
	}
	
	return integer;
}