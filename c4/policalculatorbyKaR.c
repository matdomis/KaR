/*	Polish calculator by KaR's book */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */

void push(double);
double pop();

int getop(char[]);

void main(void) {
	int type;
	double op2;
	
	char s[MAXOP]; // the next operator (number or operand) 

	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));  // atof: converts num to double from stdlib
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				(op2 != 0.0) ? (push(pop()/op2)) : printf("error: zero divisor\n");
				break;
			case '*':
				push(pop() * pop());
				break;
			case '\n':
				printf("\t%.4g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n\n", s);
				break;
		}
	}
}

/* STACK VARIABLES, PUSH AND POP */

#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop() {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) {
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	// its operand
	if (!isdigit(c) && c != '.')
		return c;			

	/* its num */

	i = 0;
	// collect integer part
	if (isdigit(c))
		while(isdigit( s[++i] = c = getch() ));
	
	// collect fractional part
	if (c == '.')
		while(isdigit( s[++i] = c = getch() ));
	s[i] = '\0';
	
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
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