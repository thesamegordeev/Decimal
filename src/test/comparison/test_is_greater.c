#include "../headers/decimal_test.h"

static int (*comp_fun)(s21_decimal, s21_decimal) = s21_is_greater;

TEST_COMPARISON(comp_fun, 23., 23., COMP_FALSE, _01_);
TEST_COMPARISON(comp_fun, 23.123, 23.123, COMP_FALSE, _02_);
TEST_COMPARISON(comp_fun, 22., 23., COMP_FALSE, _03_);
TEST_COMPARISON(comp_fun, 23., 22., COMP_TRUE, _04_);

START_TEST(_05_) {
  s21_decimal val1 = {{0, 0, 0, 0}, s21_TYPE_NEG_INFINITY};
  s21_decimal val2 = {{2, 0, 0, 0}, s21_TYPE_NORMAL};
  int res = s21_is_greater(val1, val2);
  ck_assert_int_eq(res, COMP_FALSE);
}
END_TEST

START_TEST(_06_) {
  s21_decimal val1 = {{2, 0, 0, 0}, s21_TYPE_NORMAL};
  s21_decimal val2 = {{0, 0, 0, 0}, s21_TYPE_NEG_INFINITY};
  int res = s21_is_greater(val1, val2);
  ck_assert_int_eq(res, COMP_TRUE);
}
END_TEST

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  tcase_add_test(test_case, _06_);
}

void set_is_greater_case(Suite *suite) {
  create_case(suite, "is_greater_cases", add_tests);
}