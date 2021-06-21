/*
Exercise 4-2. 
Extend atof to handle scientific notation of the form
123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.
*/
#include <stdio.h>
#include <ctype.h>

double atof(char []);
double mypow(int, int);
int abs(int);

int main() {
	char s[] = "100.568e-2"; // Input
	double d;
	d = atof(s);
	printf("%0.6f\n", d);
	return 0;
}

double atof(char s[]) {
	double val, power;
	int i, sign;
	double e;

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

	i++; // found 'e' char
	
	if(s[i] == '+') {
		i++;
		for(e = 0 ; isdigit(s[i]) ; i++)
			e = 10 * e + (s[i] - '0');
		e = mypow(10, e);
	}
	else if(s[i] == '-') {
		i++;
		for(e = 0 ; isdigit(s[i]) ; i++)
			e = 10 * e + (s[i] - '0');
		e *= -1;
		e = mypow(10, e);
	}
	
	return sign * val/power * e;
}

double mypow(int this, int that) {
	int power = this;
	for(int i = 1 ; i <= abs(that) ; i++) 
		power *= this;
	
	power /= this;

	if(that < 0)
		return (1.0/power);
	else if(that == 0)
		return 1;
	return power;
}

int abs(int n) {
	if(n > 0)
		return n;
	else
		return n * (-1);
}