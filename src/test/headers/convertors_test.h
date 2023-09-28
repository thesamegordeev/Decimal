#ifndef CONVERTORS_TEST_H
#define CONVERTORS_TEST_H

#include <check.h>

#include "../../s21_decimal.h"

#define TEST_CONVERTOR(prep_fun, test_fun, input_num, expect_num, expect_res, \
                       test_name)                                             \
  START_TEST(test_name) {                                                     \
    float expect = expect_num;                                                \
    s21_decimal src = ZERO_DECIMAL;                                           \
    int res = prep_fun(&src, input_num, expect_res);                          \
    if (res != CONV_ERR) test_fun(src, expect, expect_res);                   \
  }                                                                           \
  END_TEST

#define NULL_TEST_CONVERTOR(test_fun, test_name) \
  START_TEST(test_name) {                        \
    s21_decimal *dec = NULL;                     \
    int res = test_fun(1, dec);                  \
    ck_assert_int_eq(res, CONV_ERR);             \
  }                                              \
  END_TEST

int from_int(s21_decimal *src, float num, int expect_res);
int from_float(s21_decimal *src, float num, int expect_res);
int to_float(s21_decimal src, float expect_num, int expect_res);
int to_int(s21_decimal src, float expect_num, int expect_res);

#endif  // CONVERTORS_TEST_H
