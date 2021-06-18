/*
Exercise 3-3. 
Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.
*/

// Note: this program just works when a-b if (a <= b) - else they just remove the trio ("a-b") and move on.
//       maybe fix it later. 

#include <stdio.h>
#include <ctype.h>

#define MAX 100

void getstring(char[]);
void expand(char[], char[]);

int main() {
	char s1[MAX];
	char s2[MAX];

	getstring(s1);
	expand(s1, s2);

	printf("%s\n", s2);
	return 0;
}

void getstring(char s[]) {
	char c;
	int i;
	for(i = 0 ; i < MAX && (c = getchar()) != EOF && c != '\n' ; i++) s[i] = c;
	s[i] = '\0';
}

void expand(char s1[], char s2[]) {
	int i, j, jump, count;
	int pos = 0;

	for(i = 0 ; s1[i] != '\0' ; i++) {
		jump = 2;
		count = i; // useless - just to format a more readbly code. 

		// case letter
		if (isalpha(s1[count+jump-2]) && s1[count+jump-1] == '-' && isalpha(s1[count+jump])) {
			while(isalpha(s1[count+jump-2]) && s1[count+jump-1] == '-' && isalpha(s1[count+jump])) jump+=2;
			jump-=2;

			for(j = 0 ; j <= (s1[count+jump] - s1[count]) ; j++)
				s2[pos++] = s1[count] + j;
			
			i += jump;
		}
		// case number
		else if (isdigit(s1[count+jump-2]) && s1[count+jump-1] == '-' && isdigit(s1[count+jump])) {
			while(isdigit(s1[count+jump-2]) && s1[count+jump-1] == '-' && isdigit(s1[count+jump])) jump+=2;
			jump-=2;

			for(j = 0 ; j <= (s1[count+jump] - s1[count]) ; j++)
				s2[pos++] = s1[count] + j; 
		
			i += jump;
		}
		// case not (a-b or 0-9)
		else
			s2[pos++] = s1[i];

	}
	s2[pos] = '\0';
}