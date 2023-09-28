#include "../s21_decimal.h"

/**
 * @brief Округляет указанное Decimal число до ближайшего целого числа в сторону
 * отрицательной бесконечности.
 * @param value Decimal, который необходимо преобразовать
 * @param result Указатель на decimal, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка вычисления
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return OTH_ERR;
  int err_indicator = OTH_OK;
  *result = ZERO_DECIMAL;
  if (s21_is_type_nan(value) == 1) {
    err_indicator = OTH_ERR;
  }

  if (err_indicator == OTH_OK) {
    s21_truncate(value, result);
    if (s21_get_sign(value) == 1 && s21_is_zero(value) == 1) {
      s21_sub(*result, ONE_DECIMAL, result);
    }
  }
  return err_indicator;
}