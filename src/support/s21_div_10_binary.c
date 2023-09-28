#include "../s21_decimal.h"

/**
 * @brief Функция делит на 10 мантиссу decimal
 * @param value Decimal, мантисса которого будет делиться
 * @warning Степень числа устанавливается внутри этой функции, ее менять не надо
 */
void s21_div_10_binary(s21_decimal *value) {
  int remainder = 0;
  unsigned long long transfer = value->bits[2];
  int i = 2;
  while (i > 0) {
    remainder = transfer % 10;
    value->bits[i] = transfer / 10;
    i--;
    transfer = remainder * (s21_MAX_UINT + 1) + value->bits[i];
    if (i == 0) value->bits[i] = transfer / 10;
  }
  s21_set_scale(value, (s21_get_scale(*value) - 1));
}