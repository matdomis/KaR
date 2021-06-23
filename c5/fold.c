/*
Exercise 5-15. 
Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 100

void get_line(char *);
void readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// Array of pointers to char
char *lineptr[MAXLINES];
// Global function pointer variable (used instead of a parameter)
int (*comp)(void *, void *);

void quicksort(void *lineptr[], int left, int right);

int numcmp(const char *, const char *);


// Command-lines parameters
int numeric = 0;
int reverse = 0;
int fold = 0;

int main(int argc, char *argv[]) {

	// Check command-line parameters
	while(argc-- > 1 && (*(++argv))[0] == '-') {
			while(*++(*argv)) {
				if (**argv == 'n')
					numeric = 1;
				else if (**argv == 'r')
					reverse = 1;
				else if (**argv == 'f')
					fold = 1;
				else {
					printf("Invalid parameter!\n");
					return 1;
				}
			}
	}

	int nlines;
	printf("Number of lines: ");
	scanf("%d\n", &nlines);

	if (nlines > MAXLINES) {
		printf("Input too big to sort\n");
		return 1;
	}
			 	 
	// Read, sort, write lines	
	if (nlines > 0) {
		readlines(lineptr, nlines);					 

		comp = (numeric ? (int (*) (void *, void *))numcmp : (fold ? (int (*) (void *, void *))strcasecmp : ((int (*) (void *, void *))strcmp)));
		quicksort((void**) lineptr, 0, nlines-1);
		
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
		if (reverse) {
			if ( (*comp)(lineptr[j], pivot) > 0 ) {
				i++;
				swap(lineptr, i, j);
			}
		} else {
			if ( (*comp)(lineptr[j], pivot) < 0 ) {
				i++;
				swap(lineptr, i, j);
			}
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

