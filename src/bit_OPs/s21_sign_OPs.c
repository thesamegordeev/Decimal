#include "../s21_decimal.h"

/**
 * @brief Функция определяет знак decimal
 * @param value Decimal, знак которого необходимо получить
 * @return Функция вернет 1, если знак "+", и 0, если знак "-"
 */
int s21_get_sign(s21_decimal value) { return s21_get_bit(value, 127); }

/**
 * @brief Функция устанавливает знак decimal
 * @param value Decimal, знак которому необходимо установить
 * @param sign 1(-) или 0(+), знак, который должен быть установлен
 */
void s21_set_sign(s21_decimal *value, int sign) {
  s21_set_bit(value, 127, sign);
}