#ifndef SOLVER_H
#define SOLVER_H

#include <stdbool.h>

bool         solve     (unsigned int *, unsigned int);
bool         is_solved (unsigned int *);
bool         is_valid  (unsigned int *, const unsigned int, const unsigned int);
unsigned int index     (const unsigned int, const unsigned int);

#endif /* SOLVER_H */
