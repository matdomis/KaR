/* 
Exercise 5-7. 
Rewrite readlines to store lines in an array supplied by main , rather than
calling alloc to maintain storage. How much faster is the program?
*/

#include <stdio.h>
#include <string.h>

void writelines(char **, int);
int readlines(char **, char *);
int get_line(char *);

int sort(char **, int);

#define NUMOFLINES 5									
#define MAXLENGTH 1000								

void main(void) {
	char *pointers[NUMOFLINES];			// Array of pointers to string
	char buffer[NUMOFLINES*MAXLENGTH];	// Buffer where the lines will be stored
	
	int nlines;													

	nlines = readlines(pointers, buffer);
	sort(pointers, nlines);
	writelines(pointers, nlines);
	
}

/* 
Note
Pointers prints an array of characters, a.k.a buffer,
until the '\0' appears. The '\0' is important when
treating with pointers and strings.

In sum: p -> buffer[0...'\0'  .....'\0']
                    0     n  n+1	n+x
*/
int readlines(char *pointers[], char *buffer) {
	char line[MAXLENGTH];
	
	char *p = buffer;

	int iptr, len;

	for(iptr = 0 ; iptr < NUMOFLINES && (len = get_line(line)) > 0 && len < MAXLENGTH ; iptr++) {				
			strcpy(p, line);	// copy the line to the array, ending in len-th position
			pointers[iptr] = p; // Pass current adress 'p' to the respectively index of pointers
			p += len+1;			// Next free adress in buffer
	}

	return iptr;
}

/* Print the lines with the respectivelly size */
void writelines(char *pointers[], int nlines) {
	while(nlines-- > 0) {
		printf("[%ld] %s\n", strlen(*pointers), *pointers);
		pointers++;
	}
}

int get_line(char *line) {
	char c;
	int i;
	for(i = 0 ; (c = getchar()) != '\n' && i < MAXLENGTH ; i++)
		line[i] = c;
	line[i] = '\0';
	return i;
}

void swapAdress(int, int, char **);

/* Simple insertion sort */
int sort(char *pointers[], int nlines) {
	int i, j, key;
	for(i = 1 ; i < nlines ; i++) {
		key = i;
		for(j = i-1 ; j >= 0 ; j--)
			if(strlen(pointers[key]) < strlen(pointers[j]))
			{
				swapAdress(key, j, pointers);
				key--;
			}
	}
}

void swapAdress(int key, int j, char *pointers[]) {
	char *temp;
	temp = *(pointers+key);
	*(pointers+key) = *(pointers+j);
	*(pointers+j) = temp;

	/* Alternatively could be like this:

	temp = pointers[key];
	pointers[key] = pointers[j];
	pointers[j] = temp;
	*/
}