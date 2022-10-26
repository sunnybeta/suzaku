#include <argp.h>
#include <stdio.h>
#include <stdbool.h>
#include "puzzle.h"
#include "solver.h"
#include "util.h"


int main(int argc, char **argv) {
	unsigned int p[GRID*GRID], counter;
	char c;
	FILE *fptr;
	bool solved;
	counter = 0;
	(void) argc;
	fptr = fopen(argv[1], "r");
	c = 0;
	while(counter < GRID * GRID && c != EOF) {
		c = fgetc(fptr);
		if (c >= '0' && c <= '9') p[counter++] = c - 48;
	}
	fclose(fptr);
	if (counter != GRID * GRID) {
		debug("INVALID FILE");
		return 0;
	}
	solved = solve_puzzle(p,0);
	if (solved) debug("Puzzle Solved Successfully");
	else        warn("Puzzle is Invalid");
	print_puzzle(p);
	return 0;
}
