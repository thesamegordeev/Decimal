#ifndef ANOTHER_TEST_H
#define ANOTHER_TEST_H

#include <check.h>

#include "../../s21_decimal.h"

#define TEST_NEGATE(num, expect_num, expect_res, test_name) \
  START_TEST(test_name) {                                   \
    s21_decimal value = {0};                                \
    s21_decimal result = {0};                               \
    s21_from_float_to_decimal(num, &value);                 \
    int res = s21_negate(value, &result);                   \
    float negate_num;                                       \
    s21_from_decimal_to_float(result, &negate_num);         \
    ck_assert_float_eq(negate_num, expect_num);             \
    ck_assert_int_eq(res, expect_res);                      \
  }                                                         \
  END_TEST

#define TEST_ANOTHER(value_arr, expect_num, expect_res, func_name, test_name) \
  START_TEST(test_name) {                                                     \
    s21_decimal value = {0};                                                  \
    s21_decimal expect_result = {0};                                          \
    s21_decimal result = {0};                                                 \
    for (int i = 0; i <= 3; ++i) {                                            \
      value.bits[i] = value_arr[i];                                           \
      expect_result.bits[i] = expect_num[i];                                  \
    }                                                                         \
    int func_res = func_name(value, &result);                                 \
    ck_assert_float_eq(result.bits[0], expect_result.bits[0]);                \
    ck_assert_float_eq(result.bits[1], expect_result.bits[1]);                \
    ck_assert_float_eq(result.bits[2], expect_result.bits[2]);                \
    ck_assert_float_eq(result.bits[3], expect_result.bits[3]);                \
    ck_assert_int_eq(func_res, expect_res);                                   \
  }                                                                           \
  END_TEST

#define NULL_TEST_ANOTHER(test_fun, test_name)           \
  START_TEST(test_name) {                                \
    s21_decimal value = {{1, 0, 0, 0}, s21_TYPE_NORMAL}; \
    s21_decimal *dec = NULL;                             \
    int res = test_fun(value, dec);                      \
    ck_assert_int_eq(res, OTH_ERR);                      \
  }                                                      \
  END_TEST

#define TEST_SHIFT(value_arr, expect_num, shift, test_fun, test_name) \
  START_TEST(test_name) {                                             \
    s21_decimal value = {0};                                          \
    s21_decimal expect_result = {0};                                  \
    for (int i = 0; i <= 3; ++i) {                                    \
      value.bits[i] = value_arr[i];                                   \
      expect_result.bits[i] = expect_num[i];                          \
    }                                                                 \
    test_fun(&value, shift);                                          \
    int res = s21_is_equal(value, expect_result);                     \
    ck_assert_int_eq(res, RES_CMP_TRUE);                              \
  }                                                                   \
  END_TEST

#endif  // ANOTHER_TEST_H