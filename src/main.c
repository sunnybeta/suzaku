#include <stdbool.h>
#include "arguments.h"
#include "puzzle.h"
#include "solver.h"
#include "utils.h"
#include "read.h"

const char *argp_program_version     = "Suzaku 1.0";
const char *argp_program_bug_address = "<sunnybeta@protonmail.com>";
const char args_doc[]               = "[FILE|PUZZLE_STRING]";
const char doc[]                    = "suzaku -- SuDoKu solver";

struct argp_option options[] = {
	{"json",     'j', 0,               0, "Print a JSON formatted output", 0},
	{"filename", 'f', "FILENAME",      0, "Get puzzle from file", 1},
	{"string",   's', "PUZZLE STRING", 0, "Input string", 0},
	{0}
};

int main (int argc, char **argv) {
	struct arguments arguments;
	unsigned int p[GRID*GRID];
	bool solved;
	struct argp argp = {options, parse_opt, args_doc, doc, NULL, NULL, NULL};
	if (argc == 1) {
		error("No input.");
		return 0;
	}
	arguments.json = false;
	arguments.filename = "";
	arguments.string = "";
	argp_parse(&argp, argc, argv, 0, 0, &arguments);
	if (arguments.filename[0] != '\0') {
		if(!read_from_file(p, arguments.filename)) {
			error("Could not read file %s. :(", arguments.filename);
			return 0;
		}
	}
	else if (arguments.string[0] != '\0')
		if(!read_from_string(p, arguments.string)) {
			error("Could not read string. :(");
			return 0;
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
