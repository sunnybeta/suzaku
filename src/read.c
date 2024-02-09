#include <stdio.h>
#include "utils.h"
#include "read.h"
#include "puzzle.h"

bool read_from_file(unsigned int *p, const char *filename) {
	FILE *fptr;
	unsigned int counter;
	char c;
	fptr = fopen(filename, "r");
	counter = 0;
	c = 0;
	while((counter < GRID * GRID) && (c != EOF)) {
		c = fgetc(fptr);
		if (c >= '0' && c <= '9') p[counter++] = c - 48;
	}
	fclose(fptr);
	if (counter != GRID * GRID) {
		error("Puzzle file is invalid. Expected %d numbers for input. Received &d numbers", GRID * GRID, counter);
		return false;
	}
	return true;
}

bool read_from_string(unsigned int *p, const char *string) {
	unsigned int i;
	for (i = 0; (i < GRID * GRID) && (string[i] != '\0'); i++) {
		if (string[i] >= '0' && string[i] <= '9') p[i] = string[i] - 48;
		else {
			warn("Invalid string. Character %c at %d is not a number.", string[i], i+1);
			return false;
		}
	}
	if (i != GRID * GRID) {
		error("Invalid Puzzle String. Expected %d numbers for input. Received &d numbers", GRID*GRID, i);
		return false;
	}
	return true;
}
