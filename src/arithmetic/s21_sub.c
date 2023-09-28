#include "../s21_decimal.h"

/**
 * @brief Вычитает два Decimal
 * @param value_1 Уменьшаемое decimal
 * @param value_2 Вычитаемое decimal
 * @return Код ошибки при вычислении: 0 - ОК, 1 - Результат слишком велик или
 * равен бесконечности, 2 - Результат слишком мал или равен отрицательной
 * бесконечности, 3 - Деление на 0
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return -1;
  *result = ZERO_DECIMAL;
  s21_set_sign(&value_2, !s21_get_sign(value_2));
  return s21_add(value_1, value_2, result);
}