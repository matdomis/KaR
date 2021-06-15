/*
Exercise 4-1. 
Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s , or -1 if there is none.
*/
#include <stdio.h>
#include <string.h>

int strindex(char original[], char insideoriginal[]);

int main() {
	char s[] = "berinjela e bom demais";  /* example input */
	char t[] = "\0";

	printf("%d\n", strindex(s, t));
	return 0;
}

int strindex(char s[], char t[]) {
	int i, j, k;
	int index = -1;
	for(i = 0 ; s[i] != '\0' ; i++) {
		for(j = i, k = 0 ; k < strlen(t) && s[j] != '\0' ; j++, k++)
			if(s[j] != t[k])
				break;
		if(k == strlen(t))
			index = i;
	}
	
	return index;
}