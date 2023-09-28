#include "../s21_decimal.h"

/**
 * @brief Проверяет на неравенство два числа Decimal (value_1 != value_2)
 * @param value_1 Первое число Decimal
 * @param value_2 Второе число Decimal
 * @return 0 - FALSE, 1 - TRUE
 */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}