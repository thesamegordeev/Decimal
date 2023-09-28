#include "../headers/decimal_test.h"

//_01_
unsigned int dec1_add1[] = {123456, 0, 0, 0};
unsigned int dec2_add1[] = {532167, 0, 0, 0};
unsigned int result1[] = {655623, 0, 0, 0};
//_02_
unsigned int dec1_add2[] = {38321, 0, 0, 2147483648};
unsigned int dec2_add2[] = {13282, 0, 0, 2147483648};
unsigned int result2[] = {51603, 0, 0, 2147483648};
//_03_
unsigned int dec1_add3[] = {4238529012, 4294967295, 0, 0};
unsigned int dec2_add3[] = {56438283, 4294967295, 4294967294, 0};
unsigned int result3[] = {4294967295, 4294967294, 4294967295, 0};
//_04_
unsigned int dec1_add4[] = {4238529012, 4294967295, 4294967295, 0};
unsigned int dec2_add4[] = {56438283, 4294967295, 4294967294, 0};
unsigned int result4[] = {0, 0, 0, 0};
//_05_
unsigned int dec1_add5[] = {4238529012, 4294967295, 4294967295, 0};
unsigned int dec2_add5[] = {56438283, 4294967295, 4294967294, 0};
unsigned int result5[] = {0, 0, 0, 0};
//_06_
unsigned int dec1_add6[] = {613478421, 0, 0, 196608};
unsigned int dec2_add6[] = {2056771366, 613, 0, 393216};
unsigned int result6[] = {1354869038, 756, 0, 393216};
//_07_
unsigned int dec1_add7[] = {613478421, 0, 0, 196608};
unsigned int dec2_add7[] = {0, 0, 0, 393216};
unsigned int result7[] = {613478421, 0, 0, 196608};
//_08_
unsigned int dec1_add8[] = {4294967295, 4294967295, 4294967295, 196608};
unsigned int dec2_add8[] = {1, 0, 0, 196608};
unsigned int result8[] = {2576980378, 2576980377, 429496729, 131072};
//_09_
unsigned int dec1_add9[] = {23784103, 0, 0, 0};
unsigned int dec2_add9[] = {721398, 0, 0, 2147483648};
unsigned int result9[] = {23062705, 0, 0, 0};
//_10_
unsigned int dec1_add10[] = {74563556, 0, 0, 2147483648};
unsigned int dec2_add10[] = {24567653, 0, 0, 0};
unsigned int result10[] = {49995903, 0, 0, 2147483648};
//_11_
unsigned int dec1_add11[] = {4294967294U, 4294967295U, 4294967295U, 0};
unsigned int dec2_add11[] = {1, 0, 0, 1835008};
unsigned int result11[] = {4294967294U, 4294967295U, 4294967295U, 0};
//_12_
unsigned int dec1_add12[] = {723947, 839204, 8239, 0};
unsigned int dec2_add12[] = {0, 0, 0, 1835008};
unsigned int result12[] = {723947, 839204, 8239, 0};
//_13_
unsigned int dec1_add13[] = {2195872493U, 4192740781U, 2956914836U,
                             2148401152U};
unsigned int dec2_add13[] = {54564654, 0, 0, 0};
unsigned int result13[] = {1898633965, 775741944, 2956914541U, 2148401152U};
//_14_
unsigned int dec1_add14[] = {123, 0, 0, 327680};
unsigned int dec2_add14[] = {456, 0, 0, 327680};
unsigned int result14[] = {579, 0, 0, 327680};
//_15_
unsigned int dec1_add15[] = {123, 0, 0, 2147811328U};
unsigned int dec2_add15[] = {456, 0, 0, 327680};
unsigned int result15[] = {333, 0, 0, 0x00050000};
//_16_
unsigned int dec1_add16[] = {555, 0, 0, 2147811328U};
unsigned int dec2_add16[] = {456, 0, 0, 327680};
unsigned int result16[] = {99, 0, 0, 2147811328U};
//_17_
unsigned int dec1_add17[] = {123, 0, 0, 327680};
unsigned int dec2_add17[] = {456, 0, 0, 2147811328U};
unsigned int result17[] = {333, 0, 0, 2147811328U};
//_18_
unsigned int dec1_add18[] = {555, 0, 0, 327680};
unsigned int dec2_add18[] = {456, 0, 0, 2147811328U};
unsigned int result18[] = {99, 0, 0, 327680};
// _19_ переполнение
unsigned int dec1_add19[] = {4294967295U, 4294967295U, 4294967295U,
                             2147483648U};
unsigned int dec2_add19[] = {4294967295U, 4294967295U, 4294967295U,
                             2147483648U};
unsigned int result19[] = {0, 0, 0, 0};
// _20
unsigned int dec1_add20[] = {4294967295U, 4294967295U, 0, 2149318656U};
unsigned int dec2_add20[] = {4294967295U, 4294967295U, 0, 2149384192U};
unsigned int result20[] = {4294967285U, 4294967295U, 10, 2149384192U};
// _21_ переполнение
unsigned int dec1_add21[] = {4294967295U, 4294967295U, 4294967295U, 327680};
unsigned int dec2_add21[] = {4294967295U, 4294967295U, 4294967295U, 327680};
unsigned int result21[] = {0, 0, 0, 0};

TEST_ARITHMETIC(dec1_add1, dec2_add1, result1, AR_OK, _01_, s21_add);
TEST_ARITHMETIC(dec1_add2, dec2_add2, result2, AR_OK, _02_, s21_add);
TEST_ARITHMETIC(dec1_add3, dec2_add3, result3, AR_OK, _03_, s21_add);
TEST_ARITHMETIC(dec1_add4, dec2_add4, result4, AR_INF, _04_, s21_add);
TEST_ARITHMETIC(dec1_add5, dec2_add5, result5, AR_INF, _05_, s21_add);
TEST_ARITHMETIC(dec1_add6, dec2_add6, result6, AR_OK, _06_, s21_add);
TEST_ARITHMETIC(dec1_add7, dec2_add7, result7, AR_OK, _07_, s21_add);
TEST_ARITHMETIC(dec1_add8, dec2_add8, result8, AR_INF, _08_, s21_add);
TEST_ARITHMETIC(dec1_add9, dec2_add9, result9, AR_OK, _09_, s21_add);
TEST_ARITHMETIC(dec1_add10, dec2_add10, result10, AR_OK, _10_, s21_add);
TEST_ARITHMETIC(dec1_add11, dec2_add11, result11, AR_OK, _11_, s21_add);
TEST_ARITHMETIC(dec1_add12, dec2_add12, result12, AR_OK, _12_, s21_add);
TEST_ARITHMETIC(dec1_add13, dec2_add13, result13, AR_OK, _13_, s21_add);
TEST_ARITHMETIC(dec1_add14, dec2_add14, result14, AR_OK, _14_, s21_add);
TEST_ARITHMETIC(dec1_add15, dec2_add15, result15, AR_OK, _15_, s21_add);
TEST_ARITHMETIC(dec1_add16, dec2_add16, result16, AR_OK, _16_, s21_add);
TEST_ARITHMETIC(dec1_add17, dec2_add17, result17, AR_OK, _17_, s21_add);
TEST_ARITHMETIC(dec1_add18, dec2_add18, result18, AR_OK, _18_, s21_add);
TEST_ARITHMETIC(dec1_add19, dec2_add19, result19, AR_NEG_INF, _19_, s21_add);
TEST_ARITHMETIC(dec1_add20, dec2_add20, result20, AR_OK, _20_, s21_add);
TEST_ARITHMETIC(dec1_add21, dec2_add21, result21, AR_INF, _21_, s21_add);
NULL_TEST_ARITHMETIC(s21_add, _null_);

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
  tcase_add_test(test_case, _21_);
  tcase_add_test(test_case, _null_);
}

void set_add_case(Suite *suite) { create_case(suite, "add_cases", add_tests); }
