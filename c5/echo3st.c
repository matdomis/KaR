#include <stdio.h>

void main(int argc, char **argv) {
	while(*(++argv)) {	
		while(**argv)
			printf("%c", *(*argv)++);
		if (*(argv+1))
			printf(" ");
	}
	printf("\n");
}