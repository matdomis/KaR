/*
Exercise 4-10. 
An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define MATH 1


void printstack();
void duplicate();
void swap();
void clear();


void expandOperand(char s[]);

void push(double);
double pop();
int get_line(char s[]);

void main(void) {
	int type;
	double op2;

	// full calculator line;  Note: it only prints the result stack if '@' operand is pressed.
	char s[MAXOP];   

	get_line(s);
	char buffer[MAXOP];

	int k, i, j;
	for(i = 0 ; s[i] != '\0' ; i++) {
		for(k = i, j = 0 ; s[k] != ' ' && s[k] != '\0' && s[k] != '\t' ; k++, j++) 
			buffer[j] = s[k];
		i = k;

		if (!isdigit(buffer[0]) && buffer[1] == '\0')
			type = buffer[0];
		else if (isalpha(buffer[0]))
			type = MATH;
		else
			type = NUMBER;
		
		switch(type) {
			case NUMBER:
				push(atof(buffer));  // atof: converts num to double from stdlib
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
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
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

int get_line(char s[]) {
	int i, c;
	for(i = 0 ; (c = getchar()) != '\n' && c != EOF ; i++) s[i] = c;
	s[i] = '\0';
	return i;
}