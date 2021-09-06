#ifndef UNITTEST_H
#define UNITTEST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "assertations.h"
#include "print.h"


size_t UT_N_FAILS;

#define UT_SUCCESS 0
#define UT_FAILURE 1


#define SETUP               \
do {                        \
    srand (time (NULL));    \
    UT_N_FAILS = 0;         \
} while (0)


#define CHECK_ERROR(res)                \
    if (res == UT_SUCCESS)              \
    {                                   \
        fputs (UT_OK_MSG, stderr);      \
    }                                   \
    else                                \
    {                                   \
        UT_N_FAILS++;                   \
        fputs (UT_FAIL_MSG, stderr);    \
    }


#define RUN_TEST(func_name)                         \
do {                                                \
    fprintf (stderr, "\t%-50s ... ", #func_name);   \
    CHECK_ERROR(func_name ())                       \
} while (0)


#define EVALUATE                                                            \
do {                                                                        \
    if (UT_N_FAILS == 0)                                                    \
    {                                                                       \
        fputs ("All tests passed", stderr);                                 \
        return EXIT_SUCCESS;                                                \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        fprintf (stderr, "FAILURE: %d tests with errors.\n", UT_N_FAILS);   \
        return EXIT_FAILURE;                                                \
    }                                                                       \
} while (0)


#endif  /* UNITTEST_H */
