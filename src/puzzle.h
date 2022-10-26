#ifndef PUZZLE_H
#define PUZZLE_H

#include <stdbool.h>

#define CELL 3
#define GRID (CELL * CELL)

void print_puzzle        (unsigned int *);
void print_puzzle_string (unsigned int *);
void print_puzzle_json   (unsigned int *);

#endif /* PUZZLE_H */
