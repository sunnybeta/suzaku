#include <stdio.h>
#include <stdarg.h>
#include "util.h"

void debug(const char *msg, ...) {
	va_list args;
	va_start(args, msg);
	printf(ANSI_BLUE);
	printf("%s", "[DEBUG] ");
	vfprintf(stdout, msg, args);
	printf(ANSI_RESET);
	putchar('\n');
	printf(ANSI_RESET);
	va_end(args);
}

void warn(const char *msg, ...) {
	va_list args;
	va_start(args, msg);
	printf(ANSI_YELLOW);
	printf("%s", "[WARNING] ");
	vfprintf(stdout, msg, args);
	printf(ANSI_RESET);
	putchar('\n');
	va_end(args);
}

void error(const char *msg, ...) {
	va_list args;
	va_start(args, msg);
	printf(ANSI_MAGENTA);
	printf("%s", "[ERROR] ");
	vfprintf(stdout, msg, args);
	printf(ANSI_RESET);
	putchar('\n');
	va_end(args);
}
