#include "../s21_decimal.h"

/**
 * @brief Возвращает целые цифры указанного Decimal числа; любые дробные цифры
 * отбрасываются, включая конечные нули.
 * @param value Decimal, который необходимо преобразовать
 * @param result Указатель на decimal, в который необходимо записать результат
 * преобразования
 * @return 0 - OK, 1 - Ошибка вычисления
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return OTH_ERR;
  int err_indicator = OTH_OK;
  *result = ZERO_DECIMAL;
  if (s21_is_type_nan(value) == 1 || s21_get_scale(value) > 28) {
    err_indicator = OTH_ERR;
  }

  if (err_indicator == OTH_OK) {
    *result = s21_copy_dec(value);

    int scale = s21_get_scale(*result);
    while (scale != 0) {
      s21_div_10_binary(result);
      scale--;
    }
  }

  return err_indicator;
}