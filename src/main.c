#include <argp.h>
#include <stdio.h>
#include <stdbool.h>
#include "puzzle.h"
#include "solver.h"
#include "util.h"

const char *argp_program_version     = "suzku 1.0";
const char *argp_program_bug_address = "<sunnybeta@protonmail.com>";
static char args_doc[]               = "[FILE|PUZZLE_STRING]";
static char doc[]                    = "suzku -- A simple program to solve a SuDoKu puzzle";

struct arguments {
  bool  json;
  char *filename;
  char *string;
};

static struct argp_option options[] = {
	{"json",     'j', 0,               0, "Print a JSON formatted output", 0},
	{"filename", 'f', "FILENAME",      0, "Get puzzle from file", 1},
	{"string",   's', "PUZZLE STRING", 0, "Input string", 0},
	{0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;
	switch (key) {
		case 'j':
			arguments->json = true;
			break;
		case 'f':
			arguments->filename = arg;
			break;
		case 's':
			arguments->string = arg;
			break;
		case ARGP_KEY_ARG:
			if (state->arg_num) argp_usage(state);
			break;
		case ARGP_KEY_END:
			if (state->arg_num) argp_usage(state);
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, NULL, NULL, NULL};

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

int main (int argc, char **argv) {
	struct arguments arguments;
	unsigned int p[GRID*GRID];
	bool solved;
	/* Fix the below check of no arguments */
	if (argc == 1) {
		error("No input.");
		return 0;
	}
	/* Set argument defaults */
	arguments.json = false;
	arguments.filename = "";
	arguments.string = "";
	/* Where the magic happens */
	argp_parse (&argp, argc, argv, 0, 0, &arguments);
	/* Print argument values */
	if (arguments.filename[0] != '\0') {
		if(!read_from_file(p, arguments.filename)) {
			error("Could not read file %s. :(", arguments.filename);
			return 0;
		}
	}
	else if (arguments.string[0] != '\0') {
		if(!read_from_string(p, arguments.string)) {
			error("Could not read string. :(");
			return 0;
		}
	}
	solved = solve(p,0);
	if (solved) {
		printf(ANSI_GREEN);
		if (arguments.json) print_puzzle_json(p);
		else                print_puzzle(p);
		printf(ANSI_RESET);
	}
	else {
		error("Puzzle is insolvable. Please recheck puzzle.");
		printf(ANSI_YELLOW);
		print_puzzle(p);
		printf(ANSI_RESET);
	}
	return 0;
}
