/* echo command-line arguments; 2and version */

#include <stdio.h>

void main(int argc, char *argv[]) {
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
}
