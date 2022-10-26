#include <stdio.h>
#include <stdarg.h>
#include "util.h"

#define ANSI_BLACK   "\x1b[30m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

void debug(const char *msg, ...) {
	va_list args;
	va_start(args, msg);
	printf(ANSI_BLUE);
	printf("%s", "[DEBUG] ");
	vfprintf(stdout, msg, args);
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
