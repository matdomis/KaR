/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or || . */

#include <stdio.h>

#define MAX 1000

int main() {
	char s[MAX];
	char c;
	int i;

	for (i=0 ; i < lim-1 ; ++i)
		if ((c = getchar()) != '\n')
			if (c != EOF)
				s[i] = c;
		else
			break;

	return 0;
}