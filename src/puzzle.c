#include <stdbool.h>
#include <stdio.h>
#include "puzzle.h"

void print_puzzle(unsigned int *puzzle) {
	int i;
	puts("*---+---+---*");
	for (i = 0; i < GRID * GRID; i++) {
		if (i % GRID == 0) putchar('|');
		printf("%d", puzzle[i]);
		if ((i+1) % CELL == 0) putchar('|');
		if ((i+1) % GRID == 0)
			putchar('\n');
		if ((i+1) % (GRID*CELL) == 0) {
			if (i == 80) puts("*---+---+---*");
			else         puts("+---+---+---+");
		}
	}
}

void print_puzzle_string(unsigned int *puzzle) {
	int i;
	for (i = 0; i < GRID * GRID; i++) printf("%d", puzzle[i]);
}

void print_puzzle_json(unsigned int *puzzle) {
	int i;
	printf("{\"puzzle\":\"");
	for (i = 0; i < GRID * GRID; i++) printf("%d", puzzle[i]);
	printf("\"}");
}
