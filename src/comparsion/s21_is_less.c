#include "../s21_decimal.h"

/**
 * @brief value_1 < value_2
 * @param value_1 Первое число Decimal
 * @param value_2 Второе число Decimal
 * @return 0 - FALSE, 1 - TRUE
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  if (s21_is_type_nan(value_1) == 1 || s21_is_type_nan(value_2) == 1) {
    return COMP_FALSE;
  }
  return !s21_is_greater_or_equal(value_1, value_2);
}