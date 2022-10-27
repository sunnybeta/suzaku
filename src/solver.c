#include "puzzle.h"
#include "solver.h"


bool solve(unsigned int *puzzle, unsigned int cell) {
	unsigned int i;
	if (cell > GRID * GRID) return true;
	if (puzzle[cell] != 0) return solve(puzzle, cell+1);
	for (i = 0; i < GRID; i++)
		if (is_valid(puzzle, cell, i+1)) {
			puzzle[cell] = i + 1;
			if (solve(puzzle, cell+1)) return true;
		}
	puzzle[cell] = 0;
	return false;
}

bool is_valid(unsigned int *puzzle, const unsigned int cell, const unsigned int number) {
	unsigned int i,r,c,x,y;
	r = cell / GRID;
	c = cell % GRID;
	x = r - r % CELL;
	y = c - c % CELL;
	for (i = 0; i < GRID; i++) {
		if (puzzle[index(r,i)]                        == number) return false;
		if (puzzle[index(i,c)]                        == number) return false;
		if (puzzle[index(x + i / CELL, y + i % CELL)] == number) return false;
	}
	return true;
}

unsigned int index(const unsigned int row, const unsigned int col) {
	return row * GRID + col;
}

#if 0
bool is_solved(unsigned int *puzzle) {
	unsigned int i,j,x,y;
	unsigned int R[GRID + 1], C[GRID + 1], B[GRID + 1];
	for (i = 0; i < GRID; i++) {
		for (j = 0; j < GRID + 1; j++) {
			R[j] = 0;
			C[j] = 0;
			B[j] = 0;
		}
		for (j = 0; j < GRID; j++) {
			x = i - i % CELL;
			y = j - j % CELL;
			if (!puzzle[index(i,j)] || R[puzzle[index(i,j)]]++) return false;
			if (!puzzle[index(j,i)] || C[puzzle[index(j,i)]]++) return false;
			if (!puzzle[index(x + i / CELL, y + j % CELL)] || B[puzzle[index(x + i / CELL, y +  j % CELL)]]++) return false;
		}
	}
	return true;
}
#endif
