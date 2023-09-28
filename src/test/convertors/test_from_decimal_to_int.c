#include "../headers/decimal_test.h"

TEST_CONVERTOR(from_int, to_int, 1234., 1234., CONV_OK, _01_);
TEST_CONVERTOR(from_int, to_int, 2147483647., 2147483647., CONV_OK, _02_);
TEST_CONVERTOR(from_float, to_int, 1234.5678, 1234., CONV_OK, _03_);
TEST_CONVERTOR(from_float, to_int, -987654.321, -987654., CONV_OK, _04_);
TEST_CONVERTOR(from_float, to_int, 0.0000000001234567890123456789, 0., CONV_OK,
               _05_);
TEST_CONVERTOR(from_float, to_int, 0.9, 0., CONV_OK, _06_);

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  tcase_add_test(test_case, _06_);
}

void set_from_decimal_to_int_case(Suite *suite) {
  create_case(suite, "from_decimal_to_int_cases", add_tests);
}