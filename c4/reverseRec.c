/*
Exercise 4-13. 
Write a recursive version of the function reverse(s), 
which reverses the string s in place.
*/

int reverse(char s[], int j, int i) {
	if (i <= j)
		return 0;

	if (s[i] != '\0')
		reverse(s, j+1, i-1);

	char aux = s[j];
	s[j] = s[i];
	s[i] = aux;
	return 0;
}