#include "../s21_decimal.h"

/**
 * @brief Функция преобразовывает число типа Int в число типа Decimal
 * @param src Int, который необходимо преобразовать
 * @param dst Указатель на Decimal, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка конвертации
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) return CONV_ERR;
  *dst = ZERO_DECIMAL;
  s21_set_decimal_type(dst, s21_TYPE_NORMAL);
  dst->bits[0] = abs(src);
  s21_set_sign(dst, src < 0);
  return CONV_OK;
}