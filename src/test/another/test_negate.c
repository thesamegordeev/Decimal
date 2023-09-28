#include "../headers/decimal_test.h"

TEST_NEGATE(-25., 25., OTH_OK, _01_);
TEST_NEGATE(25., -25., OTH_OK, _02_);
NULL_TEST_ANOTHER(s21_negate, _null_);

START_TEST(_03_) {
  s21_decimal val = {{0, 0, 0, 0}, s21_TYPE_NEG_INFINITY};
  s21_decimal res = ZERO_DECIMAL;
  s21_negate(val, &res);
  ck_assert_int_eq(res.dec_type, s21_TYPE_NEG_INFINITY);
}
END_TEST

START_TEST(_04_) {
  s21_decimal val = {{0, 0, 0, 0}, s21_TYPE_INFINITY};
  s21_decimal res = ZERO_DECIMAL;
  s21_negate(val, &res);
  ck_assert_int_eq(res.dec_type, s21_TYPE_INFINITY);
}
END_TEST

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _null_);
}

void set_negate_case(Suite *suite) {
  create_case(suite, "negate_cases", add_tests);
}