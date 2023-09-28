#include "../s21_decimal.h"

/**
 * @brief Функция сложения мантисс двух decimal
 * @param value_1 Decimal, мантисса которого будет первым слагаемым
 * @param value_2 Decimal, мантисса которого будет вторым слагаемым
 * @param result Decimal, мантисса которого будет результатом сложения
 * @return 0, если сложение прошло успешно, 1 - если случилось переполнение
 */
int s21_sum_binary(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int transfer_bit = 0;
  for (int i = 0; i < 96; i++) {
    int bit_1 = s21_get_bit(value_1, i);
    int bit_2 = s21_get_bit(value_2, i);

    if (bit_1 != bit_2) {
      if (transfer_bit == 1) {
        s21_set_bit(result, i, 0);
      } else if (transfer_bit == 0) {
        s21_set_bit(result, i, 1);
      }
    } else if ((bit_1 == 1 && bit_2 == 1)) {
      if (transfer_bit == 1) {
        s21_set_bit(result, i, 1);
      } else if (transfer_bit == 0) {
        s21_set_bit(result, i, 0);
        transfer_bit = 1;
      }
    } else if ((bit_1 == 0 && bit_2 == 0)) {
      if (transfer_bit == 1) {
        s21_set_bit(result, i, 1);
        transfer_bit = 0;
      } else if (transfer_bit == 0) {
        s21_set_bit(result, i, 0);
      }
    }
  }
  return transfer_bit;  // Если вернется 1, значит словили переполнение
}

/**
 * @brief Функция вычитания мантисс двух decimal
 * @param value_1 Decimal, мантисса которого будет уменьшаемым
 * @param value_2 Decimal, мантисса которого будет вычитаемым
 * @param result Decimal, мантисса которого будет разностью
 * @return 0, если вычитание прошло успешно, 2 - если уменьшаемое больше
 * вычитаемого
 */
int s21_sub_binary(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int transfer_bit = 0;
  for (int i = 0; i < 96; i++) {
    int bit_1 = s21_get_bit(value_1, i);
    int bit_2 = s21_get_bit(value_2, i);

    if (transfer_bit == 0) {
      if (bit_1 == bit_2) {
        s21_set_bit(result, i, 0);
      } else if (bit_1 == 1 && bit_2 == 0) {
        s21_set_bit(result, i, 1);
      } else if (bit_1 == 0 && bit_2 == 1) {
        s21_set_bit(result, i, 1);
        transfer_bit = 1;
      }
    } else if (transfer_bit == 1) {
      if (bit_1 == bit_2) {
        s21_set_bit(result, i, 1);
      } else if (bit_1 == 0 && bit_2 == 1) {
        s21_set_bit(result, i, 0);
      } else if (bit_1 == 1 && bit_2 == 0) {
        s21_set_bit(result, i, 0);
        transfer_bit = 0;
      }
    }
  }
  return transfer_bit * 2;
}