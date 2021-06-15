/*
Exercise 2-5. 
Write the function any(s1,s2) , which returns the first location in a string s1
where any character from the string s2 occurs, 
or -1 if s1 contains no characters from s2.
*/

#include <stdio.h>

int any(char[], char[]);
int isInside(char[], char);

int main() {
	char s1[1000], s2[100];
	char c;
	int i, location;
	
	printf("s1: ");
	for(i = 0 ; (c = getchar()) != '\n' ; i++) s1[i] = c;
	printf("s2: ");
	for(i = 0 ; (c = getchar()) != '\n' ; i++) s2[i] = c;

	location = any(s1, s2);

	printf("%d\n", location);
	return 0;
}

int any(char s1[], char s2[]) {
	for(int i = 0 ; s1[i] != '\0' ; i++)
		if (isInside(s2, s1[i]))
			return i;
	return -1;
}

int isInside(char here[], char c) {
	for(int i = 0 ; here[i] != '\0' ; i++)
		if (here[i] == c)
			return 1;
	return 0;
}