#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <argp.h>
#include <stdbool.h>

struct arguments {
  bool  json;
  char *filename;
  char *string;
};

error_t parse_opt(int, char *, struct argp_state *);

#endif /* ARGUMENTS_H */
