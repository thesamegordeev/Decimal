#include "../headers/decimal_test.h"

static int (*comp_fun)(s21_decimal, s21_decimal) = s21_is_less_or_equal;

TEST_COMPARISON(comp_fun, 23., 23., COMP_TRUE, _01_);
TEST_COMPARISON(comp_fun, 23.123, 23.123, COMP_TRUE, _02_);
TEST_COMPARISON(comp_fun, 22., 23., COMP_TRUE, _03_);
TEST_COMPARISON(comp_fun, 23., 22., COMP_FALSE, _04_);

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
}

void set_is_less_or_equal_case(Suite *suite) {
  create_case(suite, "is_less_or_equal_cases", add_tests);
}