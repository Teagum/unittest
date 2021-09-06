#ifndef UT_ASSERTATIONS_H
#define UT_ASSERTATIONS_H


#define EPSILON 1e-10
#define FP_EQUAL(lhs, rhs) \
    ((fabsl ((long double) lhs - (long double) rhs) < EPSILON) \
     ? true : false)

#define ASSERT_EQUAL(val, comp) (FP_EQUAL (val, comp))
#define ASSERT_GREATER(val, comp) (val > comp)
#define ASSERT_GREATER_EQ(val, comp) (val >= comp)
#define ASSERT_LESS(val, comp) (val < comp)
#define ASSERT_LESS_EQ(val, comp) (val <= comp)
#define ASSERT_IN_RANGE(val, lb, hb) \
    (ASSERT_GREATER_EQ (val, lb) && ASSERT_LESS_EQ(val, hb))


#endif  /* UT_ASSERTATIONS_H */
