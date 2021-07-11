/* Example code from section 6.4 */
/* Note: I modified the keywords because the original was too long to type. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
	char *word;
	int count;
};

struct key keytabs[] = {{"char", 0}, {"double", 0}, 
						{"float", 0}, {"int", 0}, 
						{"long", 0}, {"short", 0}};
							
#define MAXWORD 100
#define NKEYS (sizeof keytabs / sizeof(struct key))

int getword(char *, int);
struct key *binsearch(char *, struct key [], int);

/* count C keywords; pointer version */
int main() {
	char word[MAXWORD];
	struct key *p;
	
	while(getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ( (p = binsearch(word, keytabs, NKEYS)) != NULL )
				p->count++;
	printf("\n");
	for(p = keytabs ; p < keytabs + NKEYS ; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

/* binsearch: find word in keytab[0]...keytab[n-1] */
struct key *binsearch(char *word, struct key keytabs [], int n) {
	int cond;
	struct key *low = &keytabs[0];
	struct key *high = &keytabs[n];
	struct key *mid;

	while(low < high) {
		mid = low + (high-low)/2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if ((cond > 0))
			low = mid+1;
		else
			return mid;
	}

	return NULL;
}

int getch(void);
void ungetch(int c);

/* getword: get next word or character from input */
int getword(char *word, int lim) {
	int c;
	char *w = word;

	while(isspace(c = getch()));

	if (c != EOF)
		*w++ = c;

	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for( ; --lim > 0 ; w++)
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
} 

/* stuff for getch and ungetch from Chapter 4 */
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