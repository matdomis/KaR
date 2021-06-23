/*
Exercise 5-10. 
Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. 
For example, expr 2 3 4 + *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOPERANDS 10

int pop();		// Pop the last element in the stack
void push(int);	// Push the last element in the stack

int main(int argc, char *argv[]) {

	int result;	    
	while(--argc > 0 && *++argv) // reason of *(++argv) is to increment argv to the next string 
	{
		
		/* When next element is '-' checks if is a number or a operand */
		if ( (*argv)[0] == '-' ) {
			
			/* Is a number */
			if ( isdigit((*argv)[1]) )
				push(atoi((*argv)));
	
			/* Is a operand */
			else {
				int temp = pop();
				result = pop() - temp;
				push(result);
			}
		}
	
		else if ( (*argv)[0] == '+' ) {
			result = pop() + pop();
			push(result);
		}

		// For some reason cant put '*' for the compared parameter to multiplication, so M it is.
		else if ( (*argv)[0] == 'M' ) {
			result = pop() * pop();
			push(result);
		}
	
		else if ( isdigit((*argv)[0]) )
			push(atoi(*argv));
	
		else
			printf("Invalid command argument!\n");
	}


	printf("RESULT=%d\n", pop());
}

int stack[MAXOPERANDS];
int si = 0;

int pop() {
	if (si > 0) 
		return stack[--si];
	printf("Error no operands\n");		
	return 0;
}

void push(int n) {
	stack[si++] = n;
}