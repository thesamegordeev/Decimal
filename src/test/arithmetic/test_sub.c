#include "../headers/decimal_test.h"

unsigned int dec1_sub1[] = {532167, 0, 0, 0};
unsigned int dec2_sub1[] = {123456, 0, 0, 0};
unsigned int result_sub1[] = {408711, 0, 0, 0};

unsigned int dec1_sub2[] = {123456, 0, 0, 0};
unsigned int dec2_sub2[] = {532167, 0, 0, 0};
unsigned int result_sub2[] = {408711, 0, 0, 2147483648};

unsigned int dec1_sub3[] = {532167, 0, 0, 2147483648};
unsigned int dec2_sub3[] = {123456, 0, 0, 2147483648};
unsigned int result_sub3[] = {408711, 0, 0, 2147483648};

unsigned int dec1_sub4[] = {61287, 0, 0, 2147483648};
unsigned int dec2_sub4[] = {234787, 0, 0, 2147483648};
unsigned int result_sub4[] = {173500, 0, 0, 0};

unsigned int dec1_sub5[] = {532167, 0, 0, 196608};
unsigned int dec2_sub5[] = {1236, 0, 0, 983040};
unsigned int result_sub5[] = {607087404, 123904785, 0, 983040};

unsigned int dec1_sub6[] = {532167, 0, 0, 196608};
unsigned int dec2_sub6[] = {0, 0, 0, 0};
unsigned int result_sub6[] = {532167, 0, 0, 196608};

unsigned int dec1_sub7[] = {2361234, 0, 0, 2147483648};
unsigned int dec2_sub7[] = {48695, 0, 0, 0};
unsigned int result_sub7[] = {2409929, 0, 0, 2147483648};

unsigned int dec1_sub8[] = {6347852, 0, 0, 0};
unsigned int dec2_sub8[] = {723184, 0, 0, 2147483648};
unsigned int result_sub8[] = {7071036, 0, 0, 0};

unsigned int dec1_sub9[] = {4294967295, 4294967295, 4294967295, 0};
unsigned int dec2_sub9[] = {6, 0, 0, 65536};
unsigned int result_sub9[] = {4294967294, 4294967295, 4294967295, 0};

unsigned int dec1_sub10[] = {4294967295, 4294967295, 4294967295, 2147483648};
unsigned int dec2_sub10[] = {1, 0, 0, 0};
unsigned int result_sub10[] = {0, 0, 0, 0};

TEST_ARITHMETIC(dec1_sub1, dec2_sub1, result_sub1, AR_OK, _01_, s21_sub);
TEST_ARITHMETIC(dec1_sub2, dec2_sub2, result_sub2, AR_OK, _02_, s21_sub);
TEST_ARITHMETIC(dec1_sub3, dec2_sub3, result_sub3, AR_OK, _03_, s21_sub);
TEST_ARITHMETIC(dec1_sub4, dec2_sub4, result_sub4, AR_OK, _04_, s21_sub);
TEST_ARITHMETIC(dec1_sub5, dec2_sub5, result_sub5, AR_OK, _05_, s21_sub);
TEST_ARITHMETIC(dec1_sub6, dec2_sub6, result_sub6, AR_OK, _06_, s21_sub);
TEST_ARITHMETIC(dec1_sub7, dec2_sub7, result_sub7, AR_OK, _07_, s21_sub);
TEST_ARITHMETIC(dec1_sub8, dec2_sub8, result_sub8, AR_OK, _08_, s21_sub);
TEST_ARITHMETIC(dec1_sub9, dec2_sub9, result_sub9, AR_OK, _09_, s21_sub);
TEST_ARITHMETIC(dec1_sub10, dec2_sub10, result_sub10, AR_NEG_INF, _10_,
                s21_sub);
NULL_TEST_ARITHMETIC(s21_sub, _null_);

static void sub_tests(TCase *test_case) {
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
  tcase_add_test(test_case, _null_);
}

void set_sub_case(Suite *suite) { create_case(suite, "sub_cases", sub_tests); }
