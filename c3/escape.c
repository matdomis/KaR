/*
Exercise 3-2. 
Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. 
Write a function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdio.h>

#define MAX 1000

int escape(char [], char []);
int getstring(char[]);

int main() {
	char s[MAX];
	char t[MAX];

	getstring(t);
	escape(s, t);
	printf("%s\n", s);
	return 0;
}

int getstring(char t[]) {
	char c;
	int i;
	
	for(i = 0 ; i < MAX && (c = getchar()) != EOF ; i++) t[i] = c;
	t[i] = '\0';
	return i-1;
}

int escape(char s[], char t[]) {
	int i, j;
	
	for(i = 0, j = 0 ; t[i] != '\0' ; i++, j++)
		switch(t[i]) 
		{
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			default:
				s[j] = t[i];
				break;
		}
	s[j] = '\0';
	return 0;
}