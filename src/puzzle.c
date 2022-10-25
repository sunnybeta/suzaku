#include <stdbool.h>
#include <stdio.h>
#include "puzzle.h"

void print_puzzle(unsigned int *puzzle) {
	int i;
	for (i = 0; i < GRID * GRID; i++) {
		if (i % CELL == 0)				putchar(' ');
		if (i % GRID == 0)				putchar('\n');
		if (i % (GRID*CELL) == 0)		putchar('\n');
		printf("%d", puzzle[i]);
	}
	putchar('\n');
}

void print_puzzle_string(unsigned int *puzzle) {
	int i;
	for (i = 0; i < GRID * GRID; i++) printf("%d", puzzle[i]);
}
