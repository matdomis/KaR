/*
Exercise 2-4. 
Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2 .
*/

#include <stdio.h>

void squeeze(char[], char[]);
int isInside(char[], char);

int main() {
	char s1[1000], s2[100];
	char c;
	int i;
	
	printf("s1: ");
	for(i = 0 ; (c = getchar()) != '\n' ; i++) s1[i] = c;
	s1[i] = '\0';
	printf("s2: ");
	for(i = 0 ; (c = getchar()) != '\n' ; i++) s2[i] = c;
	s2[i] = '\0';
	squeeze(s1, s2);
	
	printf("%s\n", s1);
	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j;
	for(i = j = 0 ; s1[i] != '\0' ; i++)
		if(!isInside(s2, s1[i]))
			s1[j++] = s1[i];
	s1[j] = '\0';

}

int isInside(char here[], char c) {
	int i;
	for(i = 0 ; here[i] != '\0' ; i++)
		if (here[i] == c)
			return 1;
	return 0;
}