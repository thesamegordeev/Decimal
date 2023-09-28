#include "../s21_decimal.h"

// https://stackoverflow.com/questions/12356442/binary-divisibility-by-10

/**
 * @brief Функция проверяет делимость на 10 мантиссы decimal
 * @param value Decimal, мантисса которого будет проверяться
 * @return 0 - если число не делится на 10, 1 - если делится
 */
int s21_check_mod_10(s21_decimal value) {
  int result = 0;
  int sign = 1;
  for (int i = 0; i < 96 / 2; i++) {
    sign = -1 * ((i % 2 * 2) - 1);
    result +=
        sign * (s21_get_bit(value, i * 2) + s21_get_bit(value, i * 2 + 1) * 2);
  }
  if (s21_get_bit(value, 0) != 0) {
    result = 1;
  }
  return (result % 5) == 0;
}