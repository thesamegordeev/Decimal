#include "../s21_decimal.h"

/**
 * @brief Проверяет на взаимное равенство два числа Decimal
 * @param value_1 Первое число Decimal
 * @param value_2 Второе число Decimal
 * @return 0 - FALSE, 1 - TRUE
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  if (s21_types_eq(value_1, value_2) == 0 || s21_is_type_nan(value_1) == 1 ||
      s21_is_type_nan(value_2) == 1) {
    return COMP_FALSE;
  }
  s21_decimal tmp_1 = s21_copy_dec(value_1);
  s21_decimal tmp_2 = s21_copy_dec(value_2);
  s21_normalize_dec(&tmp_1);
  s21_normalize_dec(&tmp_2);
  s21_align(&tmp_1, &tmp_2);
  int result = COMP_TRUE;
  if (s21_is_type_normal(value_1) == 1 && s21_is_type_normal(value_2) == 1) {
    for (int i = 3; i >= 0; i--) {
      if (value_1.bits[i] != value_2.bits[i]) {
        result = COMP_FALSE;
      }
    }
  }

  return result;
}