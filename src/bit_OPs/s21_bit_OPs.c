#include "../s21_decimal.h"

/**
 * @brief Функция для получения состояния конкретного бита
 * @param value Указатель на Decimal
 * @param bit_num Номер проверяемого бита
 */
unsigned int s21_get_bit(s21_decimal value, int bit_num) {
  int part_num = bit_num / 32;
  return (value.bits[part_num] & (1 << bit_num % 32)) > 0;
}

/**
 * @brief Функция для установки состояния конкретного бита
 * @param value Указатель на Decimal
 * @param bit_num Номер устанавливаемого бита
 * @param bit_condition Устанавливаемое состояние
 */
void s21_set_bit(s21_decimal *value, int bit_num, int bit_condition) {
  int elem_num = bit_num / 32;  // определяем номер элемента массива
  if (bit_condition == 1) {
    value->bits[elem_num] |= (1 << (bit_num - 32 * elem_num));
  } else {
    value->bits[elem_num] &= ~(1 << (bit_num - 32 * elem_num));
  }
}