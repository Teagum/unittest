#ifndef UNITTEST_H
#define UNITTEST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "print.h"

#define VERSION "0.0.1"

size_t UT_N_FAILS = 0;

enum UT_DEFAULTS {
    UT_DEFAULT_TEST_RUNS = 100,
};

#ifndef _UT_TEST_RUNS
    #define UT_TEST_RUNS UT_DEFAULT_TEST_RUNS
#else
    #define UT_TEST_RUNS _UT_TEST_RUNS
#endif

#define SETUP               \
do {                        \
    srand (time (NULL));    \
} while (0)


#define CHECK_ERROR(cnt)                                            \
    if (cnt[0] == UT_TEST_RUNS && cnt[1] == 0)                      \
    {                                                               \
        fprintf (stderr, UT_OK_MSG, cnt[0], UT_TEST_RUNS);          \
        UT_N_FAILS++;                                               \
    }                                                               \
    else                                                            \
    {                                                               \
        fprintf (stderr, UT_FAIL_MSG, cnt[0], UT_TEST_RUNS);        \
    }


#define RUN_TEST(func_name)                                         \
do {                                                                \
    int err_cnt[2] = { 0u, 0u };                                    \
    fprintf (stderr, "\t%-50s ... ", #func_name);                   \
    for (size_t i = 0; i < UT_TEST_RUNS; i++)                       \
    {                                                               \
        func_name () == UT_SUCCESS ? err_cnt[0]++ : err_cnt[1]++;   \
    }                                                               \
    CHECK_ERROR (err_cnt);                                          \
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
