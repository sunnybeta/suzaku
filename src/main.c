#include <stdio.h>
#include <argp.h>
#include "solver.h"
#include "puzzle.h"


int main(int argc, char **argv) {
	unsigned int p[81];
	char c;
	int counter;
	FILE *fptr;
	counter = 0;
	(void) argc;
	fptr = fopen(argv[1], "r");
	c = 0;
	while(counter < 81 && c != EOF) {
		c = fgetc(fptr);
		if (c >= '0' && c <= '9') p[counter++] = c - 48;
	}
	fclose(fptr);
	if (counter != 81) {
		printf("INVALID FILE");
		return 0;
	}
	solve_puzzle(p,0);
	print_puzzle_string(p);
	return 0;
}
