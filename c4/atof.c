/* atof copy from the book */

#include <stdio.h>
#include <ctype.h>

double atof(char []);

int main() {
	char s[] = "100.568";
	double d;
	d = atof(s);
	printf("%0.3f\n", d);
	return 0;
}

double atof(char s[]) {
	double val, power;
	int i, sign;

	for(i = 0 ; isspace(s[i]) ; i++);
	sign = (s[i] == '-') ? -1 : 1;
	
	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0 ; isdigit(s[i]) ; i++)
		val = 10.0 * val + (s[i] - '0');
	
	i++; // found dot char

	for(power = 1.0 ; isdigit(s[i]) ; i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val/power;
}