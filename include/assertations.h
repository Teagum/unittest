#ifndef ASSERTATIONS_H
#define ASSERTATIONS_H


#define ASSERT_EQUAL(val, comp) (FP_EQUAL (val, comp))
#define ASSERT_GREATER(val, comp) (val > comp)
#define ASSERT_GREATER_EQ(val, comp) (val >= comp)
#define ASSERT_LESS(val, comp) (val < comp)
#define ASSERT_LESS_EQ(val, comp) (val <= comp)
#define ASSERT_IN_RANGE(val, lb, hb) \
    (ASSERT_GREATER_EQ (val, lb) && ASSERT_LESS_EQ(val, hb))


#endif  /* ASSERTATIONS_H */
