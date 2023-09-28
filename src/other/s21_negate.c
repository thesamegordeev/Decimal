#include "../s21_decimal.h"

/**
 * @brief Возвращает результат умножения указанного Decimal на -1.
 * @param value Decimal, который необходимо преобразовать
 * @param result Указатель на decimal, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка вычисления
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return OTH_ERR;
  int err_indicator = OTH_OK;
  *result = ZERO_DECIMAL;
  if (s21_is_type_nan(value) == 1) {
    err_indicator = OTH_ERR;
  }

  if (err_indicator == OTH_OK) {
    *result = s21_copy_dec(value);
    if (s21_is_type_inf(value) == 1) {
      s21_set_decimal_type(result, s21_TYPE_INFINITY);
    } else if (s21_is_type_neg_inf(value) == 1) {
      s21_set_decimal_type(result, s21_TYPE_NEG_INFINITY);
    }
    s21_set_sign(result, !s21_get_sign(value));
  }
  return err_indicator;
}