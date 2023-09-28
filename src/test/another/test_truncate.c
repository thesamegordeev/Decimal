#include "../headers/decimal_test.h"

unsigned int dec_t1[] = {211, 0, 0, 65536};
unsigned int result_t1[] = {21, 0, 0, 0};

unsigned int dec_t2[] = {4294967295U, 4294967295U, 4294967295U, 65536};
unsigned int result_t2[] = {2576980377U, 2576980377U, 429496729, 0};

unsigned int dec_t3[] = {4294967295U, 4294967295U, 0, 655360};
unsigned int result_t3[] = {1844674407, 0, 0, 0};

unsigned int dec_t4[] = {4294967295U, 4294967295U, 0, 2148270080U};
unsigned int result_t4[] = {18446744, 0, 0, 2147483648U};

unsigned int dec_t5[] = {4294967295U, 4294967295U, 0, 2147483648U};
unsigned int result_t5[] = {4294967295U, 4294967295U, 0, 2147483648U};

unsigned int dec_t6[] = {109, 812379, 12345, 917504};
unsigned int result_t6[] = {2277250590U, 0, 0, 0};

unsigned int dec_t7[] = {3735322806U, 1604706208, 535408480, 589824};
unsigned int result_t7[] = {883802430, 2299561913U, 0, 0};

unsigned int dec_t8[] = {4286807631U, 4294961716U, 0, 2148073472U};
unsigned int result_t8[] = {1266850928, 4, 0, 2147483648U};

unsigned int dec_t9[] = {3500355693U, 530213720, 0, 589824};
unsigned int result_t9[] = {2277250590U, 0, 0, 0};

unsigned int dec_t10[] = {2024258758, 2684156548U, 535408493, 1835008};
unsigned int result_t10[] = {0, 0, 0, 0};

unsigned int dec_t11[] = {2, 0, 0, 0};
unsigned int result_t11[] = {2, 0, 0, 0};

unsigned int dec_t12[] = {35, 0, 0, 65536};
unsigned int result_t12[] = {3, 0, 0, 0};

unsigned int dec_t13[] = {1288864197, 2, 0, 2147483648U};
unsigned int result_t13[] = {1288864197, 2, 0, 2147483648U};

unsigned int dec_t14[] = {4192740781U, 4192740781U, 2956914836U, 2148401152U};
unsigned int result_t14[] = {2255797137U, 126998, 0, 2147483648U};

unsigned int dec_t15[] = {127606680, 1716031907, 297757, 2149056512U};
unsigned int result_t15[] = {5, 0, 0, 2147483648U};

unsigned int dec_t16[] = {1323579766, 1261806041, 431584447, 983040};
unsigned int result_t16[] = {2753445933U, 1853, 0, 0};

unsigned int dec_t17[] = {2022372554, 1644881031, 669260501, 2148859904U};
unsigned int result_t17[] = {12345677, 0, 0, 2147483648U};

unsigned int dec_t18[] = {1710152031, 1545945926, 1, 1245184};
unsigned int result_t18[] = {2, 0, 0, 0};

unsigned int dec_t19[] = {1, 0, 0, 0};
unsigned int result_t19[] = {1, 0, 0, 0};

unsigned int dec_t20[] = {0, 0, 4294967295U, 0};
unsigned int result_t20[] = {0, 0, 4294967295U, 0};

TEST_ANOTHER(dec_t1, result_t1, OTH_OK, s21_truncate, _01_);
TEST_ANOTHER(dec_t2, result_t2, OTH_OK, s21_truncate, _02_);
TEST_ANOTHER(dec_t3, result_t3, OTH_OK, s21_truncate, _03_);
TEST_ANOTHER(dec_t4, result_t4, OTH_OK, s21_truncate, _04_);
TEST_ANOTHER(dec_t5, result_t5, OTH_OK, s21_truncate, _05_);
TEST_ANOTHER(dec_t6, result_t6, OTH_OK, s21_truncate, _06_);
TEST_ANOTHER(dec_t7, result_t7, OTH_OK, s21_truncate, _07_);
TEST_ANOTHER(dec_t8, result_t8, OTH_OK, s21_truncate, _08_);
TEST_ANOTHER(dec_t9, result_t9, OTH_OK, s21_truncate, _09_);
TEST_ANOTHER(dec_t10, result_t10, OTH_OK, s21_truncate, _10_);
TEST_ANOTHER(dec_t11, result_t11, OTH_OK, s21_truncate, _11_);
TEST_ANOTHER(dec_t12, result_t12, OTH_OK, s21_truncate, _12_);
TEST_ANOTHER(dec_t13, result_t13, OTH_OK, s21_truncate, _13_);
TEST_ANOTHER(dec_t14, result_t14, OTH_OK, s21_truncate, _14_);
TEST_ANOTHER(dec_t15, result_t15, OTH_OK, s21_truncate, _15_);
TEST_ANOTHER(dec_t16, result_t16, OTH_OK, s21_truncate, _16_);
TEST_ANOTHER(dec_t17, result_t17, OTH_OK, s21_truncate, _17_);
TEST_ANOTHER(dec_t18, result_t18, OTH_OK, s21_truncate, _18_);
TEST_ANOTHER(dec_t19, result_t19, OTH_OK, s21_truncate, _19_);
TEST_ANOTHER(dec_t20, result_t20, OTH_OK, s21_truncate, _20_);
NULL_TEST_ANOTHER(s21_truncate, _null_);

static void add_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  tcase_add_test(test_case, _06_);
  tcase_add_test(test_case, _07_);
  tcase_add_test(test_case, _08_);
  tcase_add_test(test_case, _09_);
  tcase_add_test(test_case, _10_);
  tcase_add_test(test_case, _11_);
  tcase_add_test(test_case, _12_);
  tcase_add_test(test_case, _13_);
  tcase_add_test(test_case, _14_);
  tcase_add_test(test_case, _15_);
  tcase_add_test(test_case, _16_);
  tcase_add_test(test_case, _17_);
  tcase_add_test(test_case, _18_);
  tcase_add_test(test_case, _19_);
  tcase_add_test(test_case, _20_);
  tcase_add_test(test_case, _null_);
}

void set_truncate_case(Suite *suite) {
  create_case(suite, "truncate_cases", add_tests);
}
