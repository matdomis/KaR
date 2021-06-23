/*
Exercise 5-5. 
Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. 
Full descriptions are in Appendix B.
*/

#include <stdio.h>

// copy the n-th first elements of orig to dest
void strncpy(char *dest, char *orig, int size);	 

// join the n-th first elements of orig to dest 
void strncat(char *dest, char *orig, int size);	 

// compare strings; if s1<s2 return <0; if s1=s2 return 0; if s1>s2 return >0
int strncmp(char *dest, char *orig, int size);	  

void main(void) {
	char str0[5] = "Luigi";
	char str1[5] = "Mario";
	char str2[5] = " 64";

	// Copy all elements of str1 to str0
	strncpy(str0, str1, 5);
	printf("%s\n", str0);

	// Concatenate str2 to the end of str0
	strncat(str0, str2, 3);
	printf("%s\n", str0);

	// Compare s1 with s2; 0 if equal not 0 if different
	int n;
	char s1[5] = "Mario";
	char s2[5] = "Maroi";
	n = strncmp(s1, s2, 5);

	// Note that it returns -6 because the comparison stops at ('i' == 'o')
	// and returns ('i'-'o') which is -6 in ASCII integers.
	printf("%d -> The strings are differents\n", n);
	n = strncmp(s1, s2, 3);

	// Note that will return 0 because it compare char by char until the 3-th element
	// and returns ('r'-'r') which is 0 in ASCII integers
	printf("%d -> The strings are equal\n", n);
}


void strncpy(char *d, char *o, int n) {
	while(n > 0 && *o != '\0') {
		*(d++) = *(o++);
		n--;
	}
	*d = '\0';
}

void strncat(char *d, char *o, int n) {
	while(*d != '\0') 
		d++;
	
	while(n > 0 && *o != '\0') {
		*d++ = *o++;
		n--;
	}
	*d = '\0';
}

int strncmp(char *d, char *o, int n) {
	while(n > 0 && *d == *o && *d != '\0') {
		d++;
		o++;
		n--;
	}

	if (n == 0)
		return (*(--d) - *(--o));
	else
		return (*d - *o);
}