#include "../s21_decimal.h"

/**
 * @brief Округляет Decimal до ближайшего целого числа.
 * @param value Decimal, который необходимо преобразовать
 * @param result Указатель на decimal, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка вычисления
 */
int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return OTH_ERR;

  int err_indicator = OTH_OK;
  *result = ZERO_DECIMAL;
  if (s21_is_type_nan(value) == 1) {
    err_indicator = OTH_ERR;
  }

  if (err_indicator == OTH_OK) {
    s21_decimal tmp = s21_copy_dec(value);
    int sign = s21_get_sign(value);
    s21_truncate(tmp, result);
    s21_sub(tmp, *result, &tmp);

    int scale = s21_get_scale(tmp);
    if (scale != 0) scale--;
    while (scale != 0) {
      s21_div_10_binary(&tmp);
      scale--;
    }
    s21_set_sign(result, 0);
    if (tmp.bits[0] >= 5) {
      s21_add(ONE_DECIMAL, *result, result);
    }
    s21_set_sign(result, sign);
  }
  return err_indicator;
}