#ifndef COMPARISON_TEST_H
#define COMPARISON_TEST_H

#include <check.h>

#include "../../s21_decimal.h"

#define TEST_COMPARISON(comparison_fun, first_num, second_num, expect_res, \
                        test_name)                                         \
  START_TEST(test_name) {                                                  \
    s21_decimal first;                                                     \
    s21_decimal second;                                                    \
    s21_from_float_to_decimal(first_num, &first);                          \
    s21_from_float_to_decimal(second_num, &second);                        \
    int res = comparison_fun(first, second);                               \
    ck_assert_int_eq(res, expect_res);                                     \
  }                                                                        \
  END_TEST

#endif  // COMPARISON_TEST_H