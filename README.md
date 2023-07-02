# unittest
Super simple unittests for C.

## Usage
Create a new for your test functions and include "assertations.h". Use the
assertation macros to indicate errors to unittest.

```c
/* my-tests.c */

#include <stdbool.h>
#include "assertations.h"

void my_test_func (void) {
    bool status;
    /* do testing */
    status = ASSERT_<OP> (test_val, expected_val);

    /* clean up */
    return status
```

Create a test runnner in which you include your test function's headers and "unittest.h".

```c
/* runtest.c */

#include "unittest.h"
#include "my-tests.h"

int main (void) {
    
    SETUP;

    RUN_TEST (my_test_func);

    EVALUATE;
}
```

Available assertation macros are:

- `ASSERT_EQUAL(val, comp)`
- `ASSERT_GREATER(val, comp)`
- `ASSERT_GREATER_EQ(val, comp)`
- `ASSERT_LESS(val, comp)`
- `ASSERT_LESS_EQ(val, comp)`
- `ASSERT_IN_RANGE(val, lb, hb)`

Alternatively, you may also communicate test status by returning `UT_SUCCESS`,
or `UT_FAILURE` from your test functions.
