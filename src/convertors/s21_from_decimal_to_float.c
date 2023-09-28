#include "../s21_decimal.h"

/**
 * @brief Функция преобразовывает число типа Decimal в число типа float
 * @param src Decimal, который необходимо преобразовать
 * @param dst Указатель на float, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка конвертации
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (s21_is_type_normal(src) == 0) return CONV_ERR;
  int scale_decimal = s21_get_scale(src);
  int sign = s21_get_sign(src);
  double tmp = 0;
  s21_set_mantissa_float(src, &tmp);
  s21_set_scale_float(&tmp, scale_decimal);
  *dst = (float)tmp;
  s21_set_sign_float(dst, sign);
  return CONV_OK;
}