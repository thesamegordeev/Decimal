#include "../s21_decimal.h"

/**
 * @brief Функция преобразовывает число типа float в число типа Decimal
 * @param src float, который необходимо преобразовать
 * @param dst Указатель на Decimal, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка конвертации
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (dst == NULL) return CONV_ERR;
  int err_indicator = CONV_OK;
  *dst = ZERO_DECIMAL;
  s21_set_type_from_float(src, dst);
  if (s21_is_type_normal(*dst) == 0) err_indicator = CONV_ERR;
  if (err_indicator == CONV_OK) {
    double tmp = (double)fabs(src);
    int sign = s21_get_sign_float(src);
    int bin_scale = s21_get_scale_float(src);
    int dec_scale = 0;
    s21_round_float(&tmp, &dec_scale);
    if (bin_scale > -94 && bin_scale < 96) {
      represent_float represent_float = {tmp};
      bin_scale = s21_get_scale_float(represent_float.as_float);
      s21_set_sign(dst, sign);
      s21_set_bit(dst, bin_scale, 1);
      s21_move_mantissa_from_float_to_decimal(represent_float, dst, bin_scale);
      s21_set_scale(dst, dec_scale);
    } else {
      err_indicator = CONV_ERR;
    }
  }
  return err_indicator;
}
