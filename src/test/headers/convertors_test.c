#include "convertors_test.h"

// Если значение слишком мало (0 < |x| < 1e-28)
static int is_small_num_case(float num) {
  return fabs(num) > 0. && fabs(num) < 1e-28;
}

// Если значение слишков велико (|x| > 79,228,162,514,264,337,593,543,950,335)
// или равно бесконечности
static int is_big_num_case(float num) {
  return fabs(num) > 79228162514264337593543950335. || isinf(fabs(num));
}

int from_int(s21_decimal *src, float num, int expect_res) {
  int res = s21_from_int_to_decimal((int)num, src);
  ck_assert_int_eq(res, expect_res);
  return res;
}

int from_float(s21_decimal *src, float num, int expect_res) {
  int res = s21_from_float_to_decimal(num, src);
  if (is_small_num_case(num)) {
    ck_assert_int_eq(res, CONV_ERR);
    to_float(*src, 0., CONV_OK);
  } else if (is_big_num_case(num)) {
    ck_assert_int_eq(res, CONV_ERR);
  } else {
    ck_assert_int_eq(res, expect_res);
  }
  return res;
}

int to_float(s21_decimal src, float expect, int expect_res) {
  float result = 0.0;
  int res = s21_from_decimal_to_float(src, &result);
  ck_assert_float_eq(result, expect);
  ck_assert_int_eq(res, expect_res);
  return res;
}

int to_int(s21_decimal src, float expect, int expect_res) {
  int result;
  int res = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(result, (int)expect);
  ck_assert_int_eq(res, expect_res);
  return res;
}