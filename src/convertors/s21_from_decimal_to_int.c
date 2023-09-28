#include "../s21_decimal.h"

/**
 * @brief Функция преобразовывает число типа Decimal в число типа int
 * @param src Decimal, который необходимо преобразовать
 * @param dst Указатель на int, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка конвертации
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (s21_is_type_normal(src) == 0 || dst == NULL) return CONV_ERR;

  *dst = src.bits[0];
  *dst *= s21_get_sign(src) == 0 ? 1 : -1;
  *dst /= (int)pow(10, s21_get_scale(src));

  return CONV_OK;
}