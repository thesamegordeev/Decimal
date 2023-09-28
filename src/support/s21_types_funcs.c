#include "../s21_decimal.h"

/**
 * @brief Возвращает тип числа Decimal
 * @param value Число Decimal
 * @return Тип числа: 0 - TYPE_NORMAL, 1 - TYPE_INFINITY, 2 - TYPE_NEG_INFINITY,
 * 3 - TYPE_NAN
 */
int s21_get_decimal_type(s21_decimal value) { return value.dec_type; }

/**
 * @brief Устанавливает тип числа Decimal
 * @param value Число Decimal
 * @param type Тип числа: 0 - s21_TYPE_NORMAL, 1 - s21_TYPE_INFINITY, 2 -
 * s21_TYPE_NEG_INFINITY, 3 - s21_TYPE_NAN
 */
void s21_set_decimal_type(s21_decimal *value, int type) {
  value->dec_type = type;
}

/**
 * @brief Проверяет, одинаковые ли типы у чисел Decimal
 * @param value_1 Первое число Decimal
 * @param value_2 Второе число Decimal
 * @return 0 - Не равны, 1 - Равны
 */
int s21_types_eq(s21_decimal value_1, s21_decimal value_2) {
  return s21_get_decimal_type(value_1) == s21_get_decimal_type(value_2);
}

/**
 * @brief Проверяет, является ли тип у числа Decimal равным NORMAL
 * @param value_1 Число Decimal
 * @return 0 - Не является, 1 - Является
 */
int s21_is_type_normal(s21_decimal value) {
  return s21_get_decimal_type(value) == s21_TYPE_NORMAL;
}

/**
 * @brief Проверяет, является ли тип у числа Decimal равным NAN
 * @param value_1 Число Decimal
 * @return 0 - Не является, 1 - Является
 */
int s21_is_type_nan(s21_decimal value) {
  return s21_get_decimal_type(value) == s21_TYPE_NAN;
}

/**
 * @brief Проверяет, является ли тип у числа Decimal равным NEG_INF
 * @param value_1 Число Decimal
 * @return 0 - Не является, 1 - Является
 */
int s21_is_type_neg_inf(s21_decimal value) {
  return s21_get_decimal_type(value) == s21_TYPE_NEG_INFINITY;
}

/**
 * @brief Проверяет, является ли тип у числа Decimal равным INF
 * @param value_1 Число Decimal
 * @return 0 - Не является, 1 - Является
 */
int s21_is_type_inf(s21_decimal value) {
  return s21_get_decimal_type(value) == s21_TYPE_INFINITY;
}