#include "../s21_decimal.h"

/**
 * @brief Складывает два Decimal
 * @param value_1 Первое слагаемое decimal
 * @param value_2 Второе слагаемое decimal
 * @return Код ошибки при вычислении: 0 - ОК, 1 - Результат слишком велик или
 * равен бесконечности, 2 - Результат слишком мал или равен отрицательной
 * бесконечности, 3 - Деление на 0
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    return -1;
  }
  int err_indicator = AR_OK;
  *result = ZERO_DECIMAL;
  s21_decimal tmp_1 = s21_copy_dec(value_1);
  s21_decimal tmp_2 = s21_copy_dec(value_2);
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);

  s21_normalize_dec(&tmp_1);
  s21_normalize_dec(&tmp_2);
  s21_align(&tmp_1, &tmp_2);

  err_indicator = s21_functional_add(sign_1, sign_2, tmp_1, tmp_2, result);
  if (err_indicator > 0) {
    err_indicator = s21_get_sign(*result) == 0 ? 1 : 2;
    *result = ZERO_DECIMAL;
  }

  return err_indicator;
}

/**
 * @brief Непосредственно складывает два обработанных Decimal
 * @param sign_1 Знак первого decimal (0 - "+", 1 - "-")
 * @param sign_2 Знак второго decimal (0 - "+", 1 - "-")
 * @param tmp_1 Первое слагаемое decimal
 * @param tmp_2 Второе слагаемое decimal
 * @return 0 - OK, 1 - случилось переполнение, 2 - ошибка сложения
 * положительного и отрицательного числа
 */
int s21_functional_add(int sign_1, int sign_2, s21_decimal tmp_1,
                       s21_decimal tmp_2, s21_decimal *result) {
  int err_value = 0;
  if (sign_1 == sign_2) {
    err_value += s21_sum_binary(tmp_1, tmp_2, result);
    s21_set_sign(result, sign_1);
  } else {
    s21_set_sign(&tmp_1, 0);
    s21_set_sign(&tmp_2, 0);

    if (s21_is_greater(tmp_1, tmp_2) == 1) {
      err_value += s21_sub_binary(tmp_1, tmp_2, result);
      s21_set_sign(result, sign_1);
    } else {
      err_value += s21_sub_binary(tmp_2, tmp_1, result);
      s21_set_sign(result, sign_2);
    }
  }

  s21_set_scale(result, s21_get_scale(tmp_2));

  s21_normalize_dec(result);
  return err_value;
}