#include "../headers/decimal_test.h"

unsigned int dec_f1[] = {165, 0, 0, 2147549184U};
unsigned int result_f1[] = {17, 0, 0, 2147483648U};

unsigned int dec_f2[] = {4294967295U, 4194303, 0, 196608};
unsigned int result_f2[] = {1305670057, 4194, 0, 0};

unsigned int dec_f3[] = {1012340, 0, 0, 2147680256U};
unsigned int result_f3[] = {1013, 0, 0, 2147483648U};

unsigned int dec_f4[] = {2147484660U, 262144, 0, 2147942400U};
unsigned int result_f4[] = {112590205, 0, 0, 2147483648U};

unsigned int dec_f5[] = {2147484660U, 0, 0, 0};
unsigned int result_f5[] = {2147484660U, 0, 0, 0};

unsigned int dec_f6[] = {1661992959, 1808227885, 5, 2148139008U};
unsigned int result_f6[] = {1410065408, 2, 0, 2147483648U};

unsigned int dec_f7[] = {1429924785, 229956191, 0, 2148663296U};
unsigned int result_f7[] = {1, 0, 0, 2147483648U};

unsigned int dec_f8[] = {2481986642U, 288, 0, 655360};
unsigned int result_f8[] = {123, 0, 0, 0};

TEST_ANOTHER(dec_f1, result_f1, OTH_OK, s21_floor, _01_);
TEST_ANOTHER(dec_f2, result_f2, OTH_OK, s21_floor, _02_);
TEST_ANOTHER(dec_f3, result_f3, OTH_OK, s21_floor, _03_);
TEST_ANOTHER(dec_f4, result_f4, OTH_OK, s21_floor, _04_);
TEST_ANOTHER(dec_f5, result_f5, OTH_OK, s21_floor, _05_);
TEST_ANOTHER(dec_f6, result_f6, OTH_OK, s21_floor, _06_);
TEST_ANOTHER(dec_f7, result_f7, OTH_OK, s21_floor, _07_);
TEST_ANOTHER(dec_f8, result_f8, OTH_OK, s21_floor, _08_);
NULL_TEST_ANOTHER(s21_floor, _null_);

static void floor_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  tcase_add_test(test_case, _06_);
  tcase_add_test(test_case, _07_);
  tcase_add_test(test_case, _08_);
  tcase_add_test(test_case, _null_);
}

void set_floor_case(Suite *suite) {
  create_case(suite, "floor_cases", floor_tests);
}