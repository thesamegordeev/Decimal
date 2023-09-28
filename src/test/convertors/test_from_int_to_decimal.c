#include "../headers/decimal_test.h"

TEST_CONVERTOR(from_int, to_int, 1234., 1234., CONV_OK, _01_);
TEST_CONVERTOR(from_int, to_int, 2147483647., 2147483647., CONV_OK, _02_);
TEST_CONVERTOR(from_int, to_float, 1234., 1234., CONV_OK, _03_);
TEST_CONVERTOR(from_int, to_float, -987654., -987654., CONV_OK, _04_);
TEST_CONVERTOR(from_int, to_float, 0., 0., CONV_OK, _05_);
NULL_TEST_CONVERTOR(s21_from_int_to_decimal, _null_);

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  tcase_add_test(test_case, _null_);
}

void set_from_int_to_decimal_case(Suite *suite) {
  create_case(suite, "from_int_to_decimal_cases", add_tests);
}