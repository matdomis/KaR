/*
Exercise 6-1. Our version of getword does not properly handle underscores, 
string constants, comments, or preprocessor control lines. Write a better version.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
	char *word;
	int count;
};

#define MAXWORD 100
#define NKEYS 6

int getword(char *, int);
int binsearch(char *, struct key [], int);

/* Note: the strcmp function compares the first letters individually, this is important to
         binsearch works */
int main() {
	struct key keytabs[] = {{"char", 0}, {"double", 0}, 
							{"float", 0}, {"int", 0}, 
							{"long", 0}, {"short", 0}};
	
	int n;
	char word[MAXWORD];

	while(getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ( (n = binsearch(word, keytabs, NKEYS)) >= 0 )
				keytabs[n].count++;
	printf("\n");
	for(int i = 0 ; i < NKEYS ; i++)
		printf("%s\t%d\n", keytabs[i].word, keytabs[i].count);

	return 0;
}

/* binsearch: find word in keytab[0]...keytab[n-1] */
int binsearch(char *word, struct key keytabs[], int n) {
	int cond;
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low <= high) {
		mid =(low+high)/2;
		if ((cond = strcmp(word, keytabs[mid].word)) < 0)
			high = mid-1;
		else if ((cond > 0))
			low = mid+1;
		else
			return mid;
	}

	return -1;
}

int getch(void);
void ungetch(int c);

int getword (char *word, int lim) {
	int	c, d;
	char *w = word;

	for (;;) {


		while (isspace(c = getch()));

		/* Skip preprocessor operations using '#' */
		if (c == '#') {
			while ((c = getch()) != '\n')
				if (c == EOF)
					return EOF;
			continue;
		}

		/* Skip comments. */
		if (c == '/') {
			if ((d = getch()) != '*') { 
				ungetch(d);
			}
			else {
				for (;;)
					if ((c = getch()) != '*') {
						if (c == EOF)
							return EOF;
						continue;
					} 
					else if ((c = getch()) != '/') {
						if (c == EOF) 
							return EOF;
						ungetch(c);
						continue;
					} 
					else {
						break;
					}
			}

			continue;
		}

		/* Skip character and string constants */
		if (c == '\'') {
			if ((c = getch()) == '\\') {
				ungetch(c);
				c = getch();
			}
			if ((c = getch()) != '\'') { 
				ungetch(c);
				return EOF;
			}
			else {
				continue;
			}
		}
		else if (c == '\"') {

			for (;;)
				if ((c = getch()) == '\"')
					break;
				else if (c == '\\') {
					ungetch(c);
					c = getch();
				}
				else if (c == EOF)
					return EOF;

			continue;
		}

		/* Ignore all other characters. */
		if (!isalpha(c)) {
			if (c == EOF)
				return c;
		} else
			break;
	}

	/* Read a word. */
	for (*w++ = c; --lim > 1; w++)
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
		
	*w = '\0';
	return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}