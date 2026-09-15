#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#define CHECK(cond)                                                     \
    do {                                                                \
        if (!(cond)) {                                                  \
            fprintf(stderr, "FAILED: %s  (%s:%d)\n",                    \
                    #cond, __FILE__, __LINE__);                         \
            exit(1);                                                    \
        }                                                               \
    } while (0)

#endif
