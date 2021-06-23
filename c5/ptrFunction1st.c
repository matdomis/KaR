/* Example code K&R's book Chapter 5.11
   I have reformulate the example code in K&R's book page 106/107
   The example is used to explain functions pointers.
   I remade the example because the original was very bloated to me.

   The changes is exclusively in the QuickSort's parameter, where the book used a short if
   with casting and passed the function pointer as a parameter to QuickSort.
   So, instead that hole mess, I created a global function pointer variable that handles
   everything. It is defined with a cast, explained more or less in the code.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 100

// Functions to format input and output
void get_line(char *);
void readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// Declaration of array of pointers to string lines with max length of MAXLEN
char *lineptr[MAXLINES];

// Declaration of variable function pointer
int (*comp)(void *, void *);

// Basic QuickSort function declaration
void quicksort(void *lineptr[], int left, int right);

// new comparison "-n": numcmp
int numcmp(const char *, const char *);


int main(int argc, char *argv[]) {

	int nlines;
	printf("Number of lines: ");
	scanf("%d\n", &nlines);

	// Check if numeric order or not
	int numeric = 0;
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if (nlines > MAXLINES) {
		printf("Input too big to sort\n");
		return 1;
	}
			 	 
	// Read, sort, write lines	
	if (nlines > 0) {
		readlines(lineptr, nlines);					 

		/* Note:
		   there is a cast in "numcmp" and in "strcmp" to follow the same conditions 
		   of the pointer function "comp".
		*/

		comp = (numeric ? (int (*) (void *, void *))numcmp : (int (*) (void *, void *))strcmp);
		quicksort((void**) lineptr, 0, nlines-1);

		/* Note:
		   There is a cast "(void**) lineptr" because *lineptr needs to be a void pointer if
		   in case the object that the pointer points to is transformed to a double
		   because of the "-n" condition.
		*/
		
		writelines(lineptr, nlines);
	}

	// Free allocated memory
	for(int i = 0 ; i < nlines ; i++)
		free(lineptr[i]);
	
	return 0;
}


void swap(void *lineptr[], int i, int j) {
	void *temp;
	temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
}


int partition(void *[], int, int);

void quicksort(void *lineptr[], int left, int right) {
	if (left > right)
		return;

	int pi = partition(lineptr, left, right);
	
	quicksort(lineptr, left, pi-1);
	quicksort(lineptr, pi+1, right);
}


int partition(void *lineptr[], int left, int right) {
	char *pivot = lineptr[right];

	int j;
	int i = left-1;
	for(j = left ; j <= right ; j++) {
		// Use of the global function pointer
		if ( (*comp)(lineptr[j], pivot) < 0 ) {
			i++;
			swap(lineptr, i, j);
		}
	}
	swap(lineptr, i+1, right);
	return i+1;
}


int numcmp(const char *s1, const char *s2) {
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}


void readlines(char *lineptr[], int nlines) {
	for(int i = 0 ; i < nlines ; i++) {
		lineptr[i] = malloc(sizeof(char) * MAXLEN); // Alocate space to each pointer in *lineptrs[]
		get_line(lineptr[i]);
	}
}


void writelines(char *lineptr[], int nlines) {
	for(int i = 0 ; i < nlines ; i++) printf("%d. %s\n", i+1, lineptr[i]);
} 


void get_line(char *line) {
	int i;
	char c;
	for(i = 0 ; (c = getchar()) != '\n' ; i++)
		line[i] = c;
	line[i] = '\0';
}