#include <stdbool.h>
#include "arguments.h"

error_t parse_opt(int key, char *arg, struct argp_state *state) {
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

