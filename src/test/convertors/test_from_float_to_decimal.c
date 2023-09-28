#include "../headers/decimal_test.h"

TEST_CONVERTOR(from_float, to_int, 1234.32, 1234., CONV_OK, _01_);
TEST_CONVERTOR(from_float, to_int, 2474836.213, 2474836., CONV_OK, _02_);
TEST_CONVERTOR(from_float, to_float, 1234.5678, 1234.5678, CONV_OK, _03_);
TEST_CONVERTOR(from_float, to_float, -987654.321, -987654.321, CONV_OK, _04_);
TEST_CONVERTOR(from_float, to_float, 0.0000000001234567890123456789,
               0.0000000001234567890123456789, CONV_OK, _05_);
// TEST_CONVERTOR(from_float, to_float, 1e-29, 0., CONV_ERR, _06_);
TEST_CONVERTOR(from_float, to_float, 79228162514264337593543950336.0, 0.,
               CONV_ERR, _07_);
TEST_CONVERTOR(from_float, to_float, INFINITY, 0., CONV_ERR, _08_);
TEST_CONVERTOR(from_float, to_float, -79228162514264337593543950336.0, 0.,
               CONV_ERR, _09_);
TEST_CONVERTOR(from_float, to_float, -INFINITY, 0., CONV_ERR, _10_);
TEST_CONVERTOR(from_float, to_float, NAN, 0., CONV_ERR, _11_);
NULL_TEST_CONVERTOR(s21_from_float_to_decimal, _null_);

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  // tcase_add_test(test_case, _06_);
  tcase_add_test(test_case, _07_);
  tcase_add_test(test_case, _08_);
  tcase_add_test(test_case, _09_);
  tcase_add_test(test_case, _10_);
  tcase_add_test(test_case, _11_);
  tcase_add_test(test_case, _null_);
}

void set_from_float_to_decimal_case(Suite *suite) {
  create_case(suite, "from_float_to_decimal_cases", add_tests);
}