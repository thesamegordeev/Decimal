#include "../s21_decimal.h"

/**
 * @brief Копирует переданный decimal в новый
 * @param value Копируемый decimal
 * @return Число Decimal - результат копирования
 */
s21_decimal s21_copy_dec(s21_decimal value) {
  s21_decimal result = ZERO_DECIMAL;
  result.bits[0] = value.bits[0];
  result.bits[1] = value.bits[1];
  result.bits[2] = value.bits[2];
  result.bits[3] = value.bits[3];
  result.dec_type = value.dec_type;
  return result;
}