#ifndef ARITHMETIC_TEST_H
#define ARITHMETIC_TEST_H

#include <check.h>

#include "../../s21_decimal.h"

#define TEST_ARITHMETIC(val1, val2, expect_res, func_res, test_name, \
                        func_name)                                   \
  START_TEST(test_name) {                                            \
    s21_decimal value_1 = {0};                                       \
    s21_decimal value_2 = {0};                                       \
    s21_decimal result = {0};                                        \
    s21_decimal expect_result = {0};                                 \
    for (int i = 0; i <= 3; ++i) {                                   \
      value_1.bits[i] = val1[i];                                     \
      value_2.bits[i] = val2[i];                                     \
      expect_result.bits[i] = expect_res[i];                         \
    }                                                                \
    int res = func_name(value_1, value_2, &result);                  \
    if (!res) {                                                      \
      ck_assert_int_eq(res, func_res);                               \
      ck_assert_float_eq(result.bits[0], expect_result.bits[0]);     \
      ck_assert_float_eq(result.bits[1], expect_result.bits[1]);     \
      ck_assert_float_eq(result.bits[2], expect_result.bits[2]);     \
      ck_assert_float_eq(result.bits[3], expect_result.bits[3]);     \
    } else {                                                         \
      ck_assert_int_eq(res, func_res);                               \
    }                                                                \
  }                                                                  \
  END_TEST

#define NULL_TEST_ARITHMETIC(test_fun, test_name)       \
  START_TEST(test_name) {                               \
    s21_decimal val1 = {{1, 0, 0, 0}, s21_TYPE_NORMAL}; \
    s21_decimal val2 = {{1, 0, 0, 0}, s21_TYPE_NORMAL}; \
    s21_decimal *dec = NULL;                            \
    int res = test_fun(val1, val2, dec);                \
    ck_assert_int_eq(res, -1);                          \
  }                                                     \
  END_TEST
#endif  // ARITHMETIC_TEST_H
