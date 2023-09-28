#include "../headers/decimal_test.h"

int dec_r1[] = {165, 0, 0, 2147549184U};
int result_r1[] = {17, 0, 0, 2147483648U};

int dec_r2[] = {4294967295U, 4194303, 0, 196608};
int result_r2[] = {1305670058, 4194, 0, 0};

int dec_r3[] = {1012340, 0, 0, 2147680256U};
int result_r3[] = {1012, 0, 0, 2147483648U};

int dec_r4[] = {2147484660U, 262144, 0, 2147942400U};
int result_r4[] = {112590205, 0, 0, 2147483648U};

int dec_r5[] = {2147484660U, 0, 0, 0};
int result_r5[] = {2147484660U, 0, 0, 0};

int dec_r6[] = {1661992959, 1808227885, 5, 2148139008U};
int result_r6[] = {1410065408, 2, 0, 2147483648U};

int dec_r7[] = {1429924785, 229956191, 0, 2148663296U};
int result_r7[] = {1, 0, 0, 2147483648U};

int dec_r8[] = {2481986642U, 288, 0, 655360};
int result_r8[] = {124, 0, 0, 0};

int dec_r9[] = {3452402752U, 1042612832, 542101086, 2147745792U};
int result_r9[] = {2701020676U, 466537709, 54210, 2147483648U};

int dec_r10[] = {2701020676U, 466537709, 54210, 0};
int result_r10[] = {2701020676U, 466537709, 54210, 0};

int dec_r11[] = {2540937215U, 1007169933, 1, 458752};
int result_r11[] = {917933120, 530, 0, 0};

int dec_r12[] = {2540937215U, 1007169933, 1, 2147942400U};
int result_r12[] = {917933120, 530, 0, 2147483648U};

int dec_r13[] = {2, 0, 0, 0};
int result_r13[] = {2, 0, 0, 0};

int dec_r14[] = {35, 0, 0, 65536};
int result_r14[] = {4, 0, 0, 0};

int dec_r15[] = {35, 0, 0, 2147549184U};
int result_r15[] = {4, 0, 0, 2147483648U};

int dec_r16[] = {0, 0, 0, 0};
int result_r16[] = {0, 0, 0, 0};

int dec_r17[] = {3736382049U, 4109917929U, 2, 2147811328U};
int result_r17[] = {2255797137U, 126998, 0, 2147483648U};

int dec_r18[] = {127606680, 1716031907, 297757, 2149056512U};
int result_r18[] = {5, 0, 0, 2147483648U};

int dec_r19[] = {1323579766, 1261806041, 431584447, 983040};
int result_r19[] = {2753445934U, 1853, 0, 0};

int dec_r20[] = {2022372554, 1644881031, 669260501, 2148859904U};
int result_r20[] = {12345677, 0, 0, 2147483648U};

int dec_r21[] = {2949175647U, 1755493505, 1, 1245184};
int result_r21[] = {3, 0, 0, 0};

int dec_r22[] = {1, 0, 0, 0};
int result_r22[] = {1, 0, 0, 0};

int dec_r23[] = {11, 0, 0, 65536};
int result_r23[] = {1, 0, 0, 0};

int dec_r24[] = {11, 0, 0, 2147549184U};
int result_r24[] = {1, 0, 0, 2147483648U};

int dec_r25[] = {2456, 0, 0, 131072};
int result_r25[] = {25, 0, 0, 0};

int dec_r26[] = {2124, 0, 0, 2147680256U};
int result_r26[] = {2, 0, 0, 2147483648U};

int dec_r27[] = {25, 0, 0, 65536};
int result_r27[] = {3, 0, 0, 0};

int dec_r28[] = {35, 0, 0, 65536};
int result_r28[] = {4, 0, 0, 0};

TEST_ANOTHER(dec_r1, result_r1, OTH_OK, s21_round, _01_);
TEST_ANOTHER(dec_r2, result_r2, OTH_OK, s21_round, _02_);
TEST_ANOTHER(dec_r3, result_r3, OTH_OK, s21_round, _03_);
TEST_ANOTHER(dec_r4, result_r4, OTH_OK, s21_round, _04_);
TEST_ANOTHER(dec_r5, result_r5, OTH_OK, s21_round, _05_);
TEST_ANOTHER(dec_r6, result_r6, OTH_OK, s21_round, _06_);
TEST_ANOTHER(dec_r7, result_r7, OTH_OK, s21_round, _07_);
TEST_ANOTHER(dec_r8, result_r8, OTH_OK, s21_round, _08_);
TEST_ANOTHER(dec_r9, result_r9, OTH_OK, s21_round, _09_);
TEST_ANOTHER(dec_r10, result_r10, OTH_OK, s21_round, _10_);
TEST_ANOTHER(dec_r11, result_r11, OTH_OK, s21_round, _11_);
TEST_ANOTHER(dec_r12, result_r12, OTH_OK, s21_round, _12_);
TEST_ANOTHER(dec_r13, result_r13, OTH_OK, s21_round, _13_);
TEST_ANOTHER(dec_r14, result_r14, OTH_OK, s21_round, _14_);
TEST_ANOTHER(dec_r15, result_r15, OTH_OK, s21_round, _15_);
TEST_ANOTHER(dec_r16, result_r16, OTH_OK, s21_round, _16_);
TEST_ANOTHER(dec_r17, result_r17, OTH_OK, s21_round, _17_);
TEST_ANOTHER(dec_r18, result_r18, OTH_OK, s21_round, _18_);
TEST_ANOTHER(dec_r19, result_r19, OTH_OK, s21_round, _19_);
TEST_ANOTHER(dec_r20, result_r20, OTH_OK, s21_round, _20_);
TEST_ANOTHER(dec_r21, result_r21, OTH_OK, s21_round, _21_);
TEST_ANOTHER(dec_r22, result_r22, OTH_OK, s21_round, _22_);
TEST_ANOTHER(dec_r23, result_r23, OTH_OK, s21_round, _23_);
TEST_ANOTHER(dec_r24, result_r24, OTH_OK, s21_round, _24_);
TEST_ANOTHER(dec_r25, result_r25, OTH_OK, s21_round, _25_);
TEST_ANOTHER(dec_r26, result_r26, OTH_OK, s21_round, _26_);
TEST_ANOTHER(dec_r27, result_r27, OTH_OK, s21_round, _27_);
TEST_ANOTHER(dec_r28, result_r28, OTH_OK, s21_round, _28_);
NULL_TEST_ANOTHER(s21_round, _null_);

static void round_tests(TCase *test_case) {
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
  tcase_add_test(test_case, _22_);
  tcase_add_test(test_case, _23_);
  tcase_add_test(test_case, _24_);
  tcase_add_test(test_case, _25_);
  tcase_add_test(test_case, _26_);
  tcase_add_test(test_case, _27_);
  tcase_add_test(test_case, _28_);
  tcase_add_test(test_case, _null_);
}

void set_round_case(Suite *suite) {
  create_case(suite, "round_cases", round_tests);
}