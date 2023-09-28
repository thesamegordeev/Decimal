#include "../s21_decimal.h"

/**
 * @brief value_1 > value_2
 * @param value_1 Первое число Decimal
 * @param value_2 Второе число Decimal
 * @return 0 - FALSE, 1 - TRUE
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  if (s21_is_equal(value_1, value_2) == 1) {
    return COMP_FALSE;
  }

  int result = COMP_TRUE;
  int type_1 = s21_get_decimal_type(value_1);
  int type_2 = s21_get_decimal_type(value_2);
  if (type_1 == s21_TYPE_NEG_INFINITY &&
      (type_2 == s21_TYPE_NORMAL || type_2 == s21_TYPE_INFINITY)) {
    result = COMP_FALSE;
  } else if (type_1 == s21_TYPE_NORMAL && type_2 == s21_TYPE_INFINITY) {
    result = COMP_FALSE;
  } else if (type_1 == s21_TYPE_NORMAL && type_2 == s21_TYPE_NORMAL) {
    float f_1 = 0.0, f_2 = 0.0;
    s21_from_decimal_to_float(value_1, &f_1);
    s21_from_decimal_to_float(value_2, &f_2);
    result = f_1 > f_2 ? COMP_TRUE : COMP_FALSE;
  }
  return result;
}