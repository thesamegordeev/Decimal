#include "../s21_decimal.h"

/**
 * @brief Функция сдвигает биты влево (умножает на 2^amount) мантиссы decimal
 * @param src Decimal, мантисса которого будет сдвигаться
 * @param src Decimal, в который будет записываться результат
 * @param amount Количество бит, на которое сдвинется мантисса
 * @warning Функция не содержит проверки на старший бит, равный единице,
 * обязательно проверяйте его, чтобы не потерять старший разряд!
 */
void s21_bits_shift_l(s21_decimal src, s21_decimal *dst, int amount) {
  for (int i = MANTISSA_LENGTH - 1; i >= amount; i--) {
    s21_set_bit(dst, i, s21_get_bit(src, i - amount));
  }
  for (int i = 0; i < amount; i++) {
    s21_set_bit(dst, i, 0);
  }
}