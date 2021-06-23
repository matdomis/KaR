/* find pattern with command-line arguments example */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
	char line[MAXLINE];

	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while(--argc > 0 && (*++argv)[0] == '-') // <- runs through all parameters startint with '-'
		while( c = *++argv[0] )  { // runs through all characters of the current parameters until '\0'
															 // 		Note the difference between 
			switch(c) 							 //			(*++argv)[0] and *++argv[0]		
			{												 //     [] have higher precedence than *
				case 'x':							 //     so is the same as *(++argv[0])
					except = 1;					 //     Note also *(++argv[0]) = *(++*(argv+0))
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
	
		if (argc != 1)
			printf("Usage: find -x -n pattern\n");
		else
			while(get_line(line, MAXLINE) > 0) {
				lineno++;
				if (((strstr(line, *argv)) != NULL) != except)
				{
					if (number)
						printf("%ld: ", lineno);
				  printf("%s\n", line);
					found++;
				}
			}

		return found;
}

int get_line(char *line, int max) {
	char c;
	int i;
	for(i = 0 ; (c = getchar()) != '\n' && c != EOF && i < max ; i++)
		line[i] = c;
	line[i] = '\0';
	return i;
}