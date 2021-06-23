/*
Exercise 5-1. 
As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
*/

#include <ctype.h>
#include <stdio.h>

int getint(int *pn);

void main(void) {
    int array[5];
    int i, val;

    for(i = 0 ; i < 5 && (val = getint(&array[i])) != EOF ; i++) 
        printf("[%d],\t %s\n", array[i], val != 0 ? "number" : "not a number");
}

int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;

    while(isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        //ungetch(c);               /* if return to the input the array is fill with thrash */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c) && c != EOF) {
            ungetch(c);
            return 0;
        }
    }

    for(*pn = 0 ; isdigit(c) ; c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}