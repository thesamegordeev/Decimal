#include "../s21_decimal.h"

/**
 * @brief Функция удаляет незначащие нули в конце числа, сводя показатель
 * степени к минимуму
 * @param value Нормализуемый Decimal
 */
void s21_normalize_dec(s21_decimal *value) {
  int scale = s21_get_scale(*value);
  while (s21_check_mod_10(*value) == 1 && scale > 0) {
    s21_div_10_binary(value);
    scale--;
  }
}

/**
 * @brief Функция выравнивает по степени два числа типа Decimal
 * @param value_1 Первое число Decimal
 * @param value_2 Второе число Decimal
 */
void s21_align(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal tmp_1 = s21_copy_dec(*value_1);
  s21_decimal tmp_2 = s21_copy_dec(*value_2);
  int scale_1 = s21_get_scale(*value_1);
  int scale_2 = s21_get_scale(*value_2);

  while (scale_1 != scale_2) {
    if (scale_1 < scale_2) {
      if (s21_mult_10(&tmp_1) == 0) {
        s21_mult_10(value_1);
        scale_1++;
        s21_set_scale(value_1, scale_1);
        tmp_1 = s21_copy_dec(*value_1);
      } else {
        s21_div_10_binary(value_2);
        scale_2--;
      }
    } else {
      if (s21_mult_10(&tmp_2) == 0) {
        s21_mult_10(value_2);
        scale_2++;
        s21_set_scale(value_2, scale_2);
        tmp_2 = s21_copy_dec(*value_2);
      } else {
        s21_div_10_binary(value_1);
        scale_1--;
      }
    }
  }
}