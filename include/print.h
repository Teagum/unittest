#ifndef UT_PRINT_H
#define UT_PRINT_H


#define UT_OK   "OK\n"
#define UT_FAIL "FAILED\n"
#define UT_ERR_CNT "[%3d/%3d]"

#define UT_CLEAR   "\x1b[0m"
#define UT_GREEN   "\x1b[32m"
#define UT_RED     "\x1b[31m"

#ifdef _UT_NO_COLOR
    #define UT_OK_MSG   UT_OK
    #define UT_FAIL_MSG UT_FAIL
#else
    #define UT_OK_MSG   UT_GREEN UT_OK   UT_CLEAR
    #define UT_FAIL_MSG UT_RED   UT_FAIL UT_CLEAR
#endif


#endif  /* UT_PRINT_H */
