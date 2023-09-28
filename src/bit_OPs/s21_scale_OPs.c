#include "../s21_decimal.h"

/**
 * @brief Функция возвращает значение показателя степени
 * @param value Decimal, показатель степени которого необходимо узнать
 * @return число в диапазоне 0-255 (показатель степени существует в пределах
 * 0-28)
 */
unsigned int s21_get_scale(s21_decimal value) {
  return (value.bits[3] >> 16) & 255;
}

/**
 * @brief Функция устанавливает значение показателя степени
 * @param value Decimal, в который необходимо установить показатель степени
 * @param scale число в диапазоне 0-28, которое будет установлено в качестве
 * степени
 */
void s21_set_scale(s21_decimal *value, int scale) {
  for (int i = 3 * 32 + 16; i < 3 * 32 + 24; i++) {
    s21_set_bit(value, i, scale & 1);
    scale >>= 1;
  }
};
