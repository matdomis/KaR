/*
Exercise 4-12. 
Adapt the ideas of printd to write a recursive version of itoa ; that is, convert
an integer into a string by calling a recursive routine.
*/

// Note: variable 'calls' is for the porpouse of reuse the function more times as the static calls retain your value

int itoa(int n, char s[]) {
	static int i = 0;
	static int calls = 0; // flow control
	calls++;
	
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	
	if (n/10)
		itoa(n/10, s);
	
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	
	if (calls == 0)
		i = 0;
	
	return 0;
}
