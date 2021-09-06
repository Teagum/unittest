#ifndef UNITTEST_H
#define UNITTEST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "assertations.h"
#include "print.h"

unsigned short n_fails;

#define EPSILON 1e-10
#define FP_EQUAL(x, y) \
    ((fabsl ((long double) x - (long double) y) < EPSILON) \
     ? true : false)


#define SETUP               \
do {                        \
    srand (time (NULL));    \
    n_fails = 0;            \
} while (0)


#define CHECK_ERROR(res)                \
    if (res == false)                   \
    {                                   \
        fputs (UT_OK_MSG, stderr);      \
    }                                   \
    else                                \
    {                                   \
        n_fails += 1;                   \
        fputs (UT_FAIL_MSG, stderr);    \
    }


#define RUN_TEST(func_name)                         \
do {                                                \
    fprintf (stderr, "\t%-50s ... ", #func_name);   \
    CHECK_ERROR(func_name ())                       \
} while (0)


#define EVALUATE                                                        \
do {                                                                    \
    if (n_fails == 0)                                                   \
    {                                                                   \
        fputs ("All tests passed", stderr);                             \
        return EXIT_SUCCESS;                                            \
    }                                                                   \
    else                                                                \
    {                                                                   \
        fprintf (stderr, "FAILURE: %d tests with errors.\n", n_fails);  \
        return EXIT_FAILURE;                                            \
    }                                                                   \
} while (0)


#endif  /* UNITTEST_H */
