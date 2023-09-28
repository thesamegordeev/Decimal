#include "../s21_decimal.h"

/**
 * @brief Проверяет, является decimal нулем или нет
 * @param value Проверяемый decimal
 * @return 0 - Если decimal равен нулю, 1 - если нет
 */
int s21_is_zero(s21_decimal value) {
  int amount_ones = 0;
  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(value, i) == 1) amount_ones++;
  }
  return amount_ones > 0;
}