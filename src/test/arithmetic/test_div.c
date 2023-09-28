#include "../headers/decimal_test.h"

unsigned int dec1_div1[] = {1444, 0, 0, 0};
unsigned int dec2_div1[] = {2, 0, 0, 0};
unsigned int result_div1[] = {722, 0, 0, 0};

unsigned int dec1_div2[] = {0, 0, 0, 0};
unsigned int dec2_div2[] = {2, 0, 0, 0};
unsigned int result_div2[] = {0, 0, 0, 0};

unsigned int dec1_div3[] = {423, 0, 0, 0};
unsigned int dec2_div3[] = {0, 0, 0, 0};
unsigned int result_div3[] = {0, 0, 0, 0};

// Бесконечность
unsigned int dec1_div4[] = {4294967295U, 4294967295U, 4294967295U, 0};
unsigned int dec2_div4[] = {1, 0, 0, 65536};
unsigned int result_div4[] = {0, 0, 0, 0};

// Отрицательная бесконечность
unsigned int dec1_div5[] = {4294967295U, 4294967295U, 4294967295U, 0};
unsigned int dec2_div5[] = {1, 0, 0, 2147549184};
unsigned int result_div5[] = {0, 0, 0, 0};

// Дробный ответ
unsigned int dec1_div6[] = {5, 0, 0, 0};
unsigned int dec2_div6[] = {2, 0, 0, 0};
unsigned int result_div6[] = {25, 0, 0, 65536};

unsigned int dec1_div7[] = {9, 0, 0, 65536};     // 0.9
unsigned int dec2_div7[] = {6, 0, 0, 65536};     // 0.6
unsigned int result_div7[] = {15, 0, 0, 65536};  // 1.5

unsigned int dec1_div8[] = {14, 0, 0, 65536};      // 1.4
unsigned int dec2_div8[] = {9, 0, 0, 2147549184};  // -0.9
unsigned int result_div8[] = {3280877796, 1621842184, 843268356,
                              2149318656};  // -1.55555555(5)

unsigned int dec1_div9[] = {4294967295U, 4294967295U, 4294967295U, 65536};
unsigned int dec2_div9[] = {1, 0, 0, 65536};
unsigned int result_div9[] = {4294967295U, 4294967295U, 4294967295U, 0};

TEST_ARITHMETIC(dec1_div1, dec2_div1, result_div1, AR_OK, _01_, s21_div);
TEST_ARITHMETIC(dec1_div2, dec2_div2, result_div2, AR_OK, _02_, s21_div);
TEST_ARITHMETIC(dec1_div3, dec2_div3, result_div3, AR_DIV_ZERO, _03_, s21_div);
TEST_ARITHMETIC(dec1_div4, dec2_div4, result_div4, AR_INF, _04_, s21_div);
TEST_ARITHMETIC(dec1_div5, dec2_div5, result_div5, AR_NEG_INF, _05_, s21_div);
TEST_ARITHMETIC(dec1_div6, dec2_div6, result_div6, AR_OK, _06_, s21_div);
TEST_ARITHMETIC(dec1_div7, dec2_div7, result_div7, AR_OK, _07_, s21_div);
TEST_ARITHMETIC(dec1_div8, dec2_div8, result_div8, AR_OK, _08_, s21_div);
TEST_ARITHMETIC(dec1_div9, dec2_div9, result_div9, AR_OK, _09_, s21_div);
NULL_TEST_ARITHMETIC(s21_div, _null_);

static void div_tests(TCase *test_case) {
  tcase_add_test(test_case, _01_);
  tcase_add_test(test_case, _02_);
  tcase_add_test(test_case, _03_);
  tcase_add_test(test_case, _04_);
  tcase_add_test(test_case, _05_);
  tcase_add_test(test_case, _06_);
  tcase_add_test(test_case, _07_);
  tcase_add_test(test_case, _08_);
  tcase_add_test(test_case, _09_);
  tcase_add_test(test_case, _null_);
}
void set_div_case(Suite *suite) { create_case(suite, "div_cases", div_tests); }
