/* echo command-line arguments; 1st version */

#include <stdio.h>

void main(int argc, char *argv[]) {
	for(int i = 1 ; i < argc ; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	printf("\n");
}