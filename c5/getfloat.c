/*
Exercise 5-2. 
Write getfloat, the floating-point analog of getint. 
What type does getfloat return as its function value?
*/

#include <ctype.h>
#include <stdio.h>
#include <math.h>

int getfloat(float *pn);

void main(void) {
    float array[5];
    int i, val;

    for(i = 0 ; i < 5 && (val = getfloat(&array[i])) != EOF ; i++) 
        printf("[%.2f],\t %s\n", array[i], val != 0 ? "number" : "not a number");
}

int getch(void);
void ungetch(int);

int getfloat(float *pn) {
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
    
    if (c == '.')
        c = getch();

    for(int i = 10 ; isdigit(c) ; c = getch(), i *= 10)
        *pn = *pn + (float)(c - '0') / i;

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