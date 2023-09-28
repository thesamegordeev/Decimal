#include "../headers/decimal_test.h"

unsigned int dec1_mul1[] = {13, 0, 0, 0};
unsigned int dec2_mul1[] = {10, 0, 0, 0};
unsigned int result_mul1[] = {130, 0, 0, 0};

unsigned int dec1_mul2[] = {
    1288491188, 12312, 0, 0};  // 110000000110001001100110011001101000010110100
unsigned int dec2_mul2[] = {10, 0, 0, 0};
unsigned int result_mul2[] = {
    9992, 123123, 0, 0};  // 1111000001111001100000000000000000010011100001000

unsigned int dec1_mul3[] = {60, 0, 0, 0};
unsigned int dec2_mul3[] = {10, 0, 0, 0};
unsigned int result_mul3[] = {600, 0, 0, 0};

unsigned int dec1_mul4[] = {336433, 563, 0,
                            0};  // 100011001100000000000001010010001000110001
unsigned int dec2_mul4[] = {1241, 0, 0, 0};
unsigned int result_mul4[] = {
    417513353, 698683, 0,
    0};  // 1010101010010011101100011000111000101011111110001001

unsigned int dec1_mul5[] = {336433, 563, 0, 0};
unsigned int dec2_mul5[] = {1241, 0, 0, 0};
unsigned int result_mul5[] = {417513353, 698683, 0, 0};

unsigned int dec1_mul6[] = {125236476, 0, 0, 393216};       // -6
unsigned int dec2_mul6[] = {364287140, 0, 0, 2147680256U};  // -3
unsigned int result_mul6[] = {3605414744, 1062220, 0,
                              2148007936U};  // 3605414744 1062220 0 2148007936

// 3 знака
unsigned int dec1_mul7[] = {4294967295U, 4294967295U, 2147483647, 393216};
unsigned int dec2_mul7[] = {2, 0, 0, 0};
unsigned int result_mul7[] = {4294967294U, 4294967295U, 4294967295U, 393216};

unsigned int dec1_mul8[] = {
    137900165, 69122625, 1,
    1310720};  // 20 знаков
               // 10000010000011110101110100100000100001000001110000011000010000101
unsigned int dec2_mul8[] = {46246921, 0, 0, 983040};  // 15 знаков
// 28 знаков
unsigned int result_mul8[] = {2090836749, 3002702997, 4, 1835008};

// 20 знаков
unsigned int dec1_mul9[] = {137900165, 69122625, 1, 1310720};
// 16 знаков
unsigned int dec2_mul9[] = {1, 0, 0, 1048576};
// 28 знаков
unsigned int result_mul9[] = {2752641148, 43, 0, 1835008};

unsigned int dec1_mul10[] = {4294967295U, 4294967295U, 4294967295U, 0};
unsigned int dec2_mul10[] = {2, 0, 0, 0};
unsigned int result_mul10[] = {0, 0, 0, 0};

unsigned int dec1_mul11[] = {4294967295U, 4294967295U, 4294967295U, 2147483648};
unsigned int dec2_mul11[] = {2, 0, 0, 0};
unsigned int result_mul11[] = {0, 0, 0, 0};

TEST_ARITHMETIC(dec1_mul1, dec2_mul1, result_mul1, AR_OK, _01_, s21_mul);
TEST_ARITHMETIC(dec1_mul2, dec2_mul2, result_mul2, AR_OK, _02_, s21_mul);
TEST_ARITHMETIC(dec1_mul3, dec2_mul3, result_mul3, AR_OK, _03_, s21_mul);
TEST_ARITHMETIC(dec1_mul4, dec2_mul4, result_mul4, AR_OK, _04_, s21_mul);
TEST_ARITHMETIC(dec1_mul5, dec2_mul5, result_mul5, AR_OK, _05_, s21_mul);
TEST_ARITHMETIC(dec1_mul6, dec2_mul6, result_mul6, AR_OK, _06_, s21_mul);
TEST_ARITHMETIC(dec1_mul7, dec2_mul7, result_mul7, AR_OK, _07_, s21_mul);
TEST_ARITHMETIC(dec1_mul8, dec2_mul8, result_mul8, AR_OK, _08_, s21_mul);
TEST_ARITHMETIC(dec1_mul9, dec2_mul9, result_mul9, AR_OK, _09_, s21_mul);
TEST_ARITHMETIC(dec1_mul10, dec2_mul10, result_mul10, AR_INF, _10_, s21_mul);
TEST_ARITHMETIC(dec1_mul11, dec2_mul11, result_mul11, AR_NEG_INF, _11_,
                s21_mul);
NULL_TEST_ARITHMETIC(s21_mul, _null_);

static void mul_tests(TCase *test_case) {
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
  tcase_add_test(test_case, _null_);
}

void set_mul_case(Suite *suite) { create_case(suite, "mul_cases", mul_tests); }
