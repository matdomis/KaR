#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 100
#define MAXLEN 1000

int get_line(char *);

int main(int argc, char *argv[]) {
	char *p[MAXLINES];

	// Allocation of each pointer
	for(int i = 0 ; i < MAXLINES ; i++)
		p[i] = malloc(sizeof(char) * MAXLEN);
	
	// Get input lines and store each line to a pointer in array p
	// i = number of lines read by input
	int i, len;
	for(i = 0 ; (len = get_line(p[i])) > 0 ; i++);

	// Get the value of -n if there is one and do the difference
	int n_attribute;
	int diff;

	if (argc > 1) {
		++argv;
		if((*argv)[0] == '-' && (*argv)[1] == 'n') {
			++argv;
			n_attribute = atoi(*argv);
			diff = i-n_attribute; 
		}
		else
			printf("Invalid parameter: tail set 10 by default\n");
	}
	// Default -n
	else {
		diff = i-10;
	}
	
	if (diff > 0) 
		for(int j = diff ; j < i ; j++)
			printf("%s\n", p[j]);
	else
		for(int j = 0 ; j < i ; j++)
			printf("%s\n", p[j]);

	// Free memory
	for(i = 0 ; i < MAXLINES ; i++)
		free(p[i]);

	return 0;
}

/* Get_line works until EOF */ 
int get_line(char *line) {
	char c;
	int i;
	for (i = 0 ; (c = getchar()) != EOF && c != '\n' && i < MAXLINES ; i++) 
		line[i] = c;
	line[i] = '\0';

	if (c == EOF)
		return -1;
	return i;
}