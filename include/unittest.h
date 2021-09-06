#ifndef UNITTEST_H
#define UNITTEST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "assertations.h"

unsigned short n_fails;


#define EPSILON 1e-10
#define FP_EQUAL(x, y) \
    ((fabsl ((long double) x - (long double) y) < EPSILON) \
     ? true : false)


#define STV(_str_) #_str_

#define SETUP do {          \
    srand (time (NULL));    \
    n_fails = 0;            \
} while (0)


#define CHECK_ERROR(_res_)      \
    if (_res_ == false)         \
    {                           \
        printf ("OK\n");        \
    }                           \
    else                        \
    {                           \
        n_fails += 1;           \
        printf ("FAILED\n");    \
    }

#define RUN_TEST(_func_)                        \
    do {                                        \
        printf ("\t%-50s ... ", STV(_func_));   \
        CHECK_ERROR(_func_ ())                  \
    } while (0)


#define EVALUATE do {                                                       \
    if (n_fails == 0)                                                       \
    {                                                                       \
        puts ("All tests passed");                                          \
        return EXIT_SUCCESS;                                                \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        fprintf (stdout, "FAILURE: %d tests with errors.\n", n_fails);      \
        return EXIT_FAILURE;                                                \
    }                                                                       \
} while (0)


#endif  /* UNITTEST_H */
