#include "../s21_decimal.h"

/**
 * @brief Перемножает два Decimal
 * @param value_1 Множимое decimal
 * @param value_2 Множитель decimal
 * @return Код ошибки при вычислении: 0 - ОК, 1 - Результат слишком велик или
 * равен бесконечности, 2 - Результат слишком мал или равен отрицательной
 * бесконечности, 3 - Деление на 0
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return -1;
  int err_indicator = AR_OK;
  *result = ZERO_DECIMAL;
  err_indicator = s21_functional_mul(value_1, value_2, result);
  return err_indicator;
}

int s21_functional_mul(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result) {
  *result = ZERO_DECIMAL;
  s21_decimal tmp_1 = s21_copy_dec(value_1);
  s21_decimal tmp_2 = s21_copy_dec(value_2);
  s21_normalize_dec(&tmp_1);
  s21_normalize_dec(&tmp_2);
  int scale_1 = s21_get_scale(tmp_1), scale_2 = s21_get_scale(tmp_2);
  int scale_result = scale_1 + scale_2;
  int sign_1 = s21_get_sign(tmp_1), sign_2 = s21_get_sign(tmp_2);
  int signRes = sign_1 ^ sign_2;
  s21_set_sign(result, signRes);
  int err_indicator = AR_OK;
  int res[192] = {0};
  int value1shifted[192] = {0};
  s21_decToArray(tmp_1, value1shifted, 192);
  for (int i = 0; i < 96 && err_indicator == AR_OK; i++) {
    if (s21_get_bit(tmp_2, i) == 1) {
      s21_decArraySimpleAdd(res, value1shifted);
    }
    s21_decArrayShiftLeft(value1shifted);
  }
  int resBase10[60] = {0};
  s21_binToDec(res, resBase10, 192);
  s21_base10normalize(resBase10, &scale_result);
  err_indicator = s21_base10truncate(resBase10, scale_result, signRes);
  if (!err_indicator) {
    s21_base10ToDecimal(resBase10, scale_result, signRes, result);
  }
  return err_indicator;
}
