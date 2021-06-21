/*

Exercise 4-3. 
Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

Exercise 4-4. 
Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.

Exercise 4-5. 
Add access to library functions like sin , exp , and pow . See <math.h> in
Appendix B, Section 4.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define MATH 1


/* Ex 4-4 */

void printstack();
void duplicate();
void swap();
void clear();

/* ----- */

/* Ex 4-5 */

void expandOperand(char s[]);

/* ----- */

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

			/* Ex 4-3 */
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			/* ----- */
			case '@':
				printstack();
				break;
			case '&':
				duplicate();
				break;
			case '~':
				swap();
				break;
			case '!':
				clear();
				break;
			case MATH:
				expandOperand(s);
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

void printstack() {
	printf("____\n");
	for(int i = sp-1 ; i >= 0 ; i--) 
		printf("| %g |\n", val[i]);
	printf("____\n");
}

void duplicate() {
	for(int i = 0 ; i < sp ; i++) val[i] *= 2;
}

void swap() {
	double aux = val[sp-1];
	val[sp-1] = val[sp-2];
	val[sp-2] = aux;
}

void clear() {
	sp = 0;
}

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

void expandOperand(char s[]) {
	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0) {
		double op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("%s is not a supported function", s);
}

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) {
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if (!isdigit(c) && c != '.' &&  c != '-' && !isalpha(c))
		return c;			/* its a operand */

	i = 0;

	/* Changes for Ex 4-5 */
	if (isalpha(c)) {
		for(i = 1 ; isalpha(c = getch()) ; i++)
			s[i] = c;
		s[i] = '\0';
		ungetch(c);
		return MATH;
	}
	
	/* Changes for Ex 4-3 */
	if (c == '-') {
		c = getch();
		if (isdigit(c)) {
			s[++i] = c;
			while(isdigit( s[++i] = c = getch() ));
		}
		else {
			ungetch(c);
			return s[0];
		}
	}

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