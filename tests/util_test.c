#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <my_program/util.h>

/**
 * @brief An example test case.
 *
 * @param state
 */
static void util_test(void **state)
{
    (void)state; // unused.

    double actualResult, // Actual test result.
        expectedResult;  // Expected test result.

    expectedResult = 0.0;
    actualResult = sum(-1, 1);
    assert_int_equal(expectedResult, actualResult);
}

/**
 * @brief Main test function.
 *
 * This test is failing on purpose. The point is to show that, alghough my_program
 * requires sum, my_program test is working fine thanks to the stub, while this
 * test is failing.
 *
 * @return int Number of failed tests.
 */
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(util_test)};
    return cmocka_run_group_tests(tests, NULL, NULL);
}