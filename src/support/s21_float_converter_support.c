#include "../s21_decimal.h"

/**
 * @brief Функция записывает мантиссу в число float из Decimal
 * @param src Число Decimal, из которого будет записываться мантисса
 * @param dst Указатель на float, в которое будет записываться мантисса
 */
void s21_set_mantissa_float(s21_decimal src, double *dst) {
  for (int i = 0; i < MANTISSA_LENGTH; i++) {
    if (s21_get_bit(src, i) == 1) {
      *dst += pow(2, i);
    }
  }
}

/**
 * @brief Функция записывает степень в число float
 * @param dst Указатель на float, в который будет записываться степень
 * @param scale Степень, которая будет записана
 */
void s21_set_scale_float(double *dst, int scale) {
  while (scale > 0) {
    *dst /= 10.0;
    scale--;
  }
}

/**
 * @brief Функция записывает знак в число float
 * @param dst Указатель на float, в который будет записываться знак
 * @param sign Знак, который будет записан
 */
void s21_set_sign_float(float *dst, int sign) { *dst *= sign == 0 ? 1 : -1; }

/**
 * @brief Функция записывает тип в число Decimal из float
 * @param src Число float, из которого будет записываться тип
 * @param dst Указатель на decimal, в которое будет записываться тип
 */
void s21_set_type_from_float(float src, s21_decimal *dst) {
  if (isinf(src) == 1 || src >= MAX_DECIMAL) {
    s21_set_decimal_type(dst, s21_TYPE_INFINITY);
  } else if (isinf(src) == -1 || src <= MIN_DECIMAL || fabs(src) < 1e-28) {
    s21_set_decimal_type(dst, s21_TYPE_NEG_INFINITY);
  } else if (isnan(src) == 1) {
    s21_set_decimal_type(dst, s21_TYPE_NAN);
  } else {
    s21_set_decimal_type(dst, s21_TYPE_NORMAL);
  }
}

/**
 * @brief Функция получает знак из числа float
 * @param src float, из которого будет получен знак
 * @return 0 (+) или 1 (-)
 */
int s21_get_sign_float(float src) { return abs((int)src >> 31); }

/**
 * @brief Функция получает показатель степени для двоичного представления из
 * числа float
 * @param src float, из которого будет получен показатель
 * @return Показатель степени x для представления 2^x
 */
int s21_get_scale_float(float src) {
  return ((*(int *)&src & ~(1u << 31)) >> 23) - 127;
}

/**
 * @brief Функция округляет float до 7 знака, либо до предела показателя степени
 * decimal
 * @param src Указатель на округляемое число
 * @param decimal_scale Указатель на степень, которая будет установлена в
 * итоговый decimal
 */
void s21_round_float(double *src, int *decimal_scale) {
  while (*decimal_scale < 28 && (int)*src / (int)pow(2, 22) == 0) {
    *src *= 10;
    *decimal_scale += 1;
  }
  s21_normalize_float(src, decimal_scale);
}

/**
 * @brief Функция округляет float банковским округлением до ближайшего целого с
 * учетом множителя, а потом удаляет нули
 * @param src Указатель на округляемое число
 * @param decimal_scale Указатель на степень, которая будет установлена в
 * итоговый decimal
 */
void s21_normalize_float(double *src, int *decimal_scale) {
  *src = round(*src);
  while (fmod(*src, 10) == 0 && *decimal_scale > 0) {
    *src /= 10;
    *decimal_scale -= 1;
  }
}

/**
 * @brief Функция перекидывает мантиссу, включая неявный бит из float в decimal
 * @param represent_float Union float + int для простого доступа к битам типа
 * данных
 * @param dst Указатель на decimal, в который будет загружена мантисса
 * @param bin_scale Показатель степени float для двоичного представления,
 * указывает, куда нужно поставить неявный бит
 */
void s21_move_mantissa_from_float_to_decimal(represent_float represent_float,
                                             s21_decimal *dst, int bin_scale) {
  for (int i = bin_scale - 1, j = 22; j >= 0; i--, j--) {
    if (represent_float.as_int & (1 << j)) {
      s21_set_bit(dst, i, 1);
    }
  }
}
