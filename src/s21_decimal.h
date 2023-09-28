#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MANTISSA_LENGTH 96
#define MAX_DECIMAL 79228162514264337593543950335.0
#define MIN_DECIMAL -79228162514264337593543950335.0
#define s21_MAX_UINT 4294967295

typedef enum {
  s21_TYPE_NORMAL,
  s21_TYPE_INFINITY,
  s21_TYPE_NEG_INFINITY,
  s21_TYPE_NAN
} dec_type;

typedef struct {
  unsigned int bits[4];
  dec_type dec_type;
} s21_decimal;

#define ZERO_DECIMAL \
  (s21_decimal) { {0, 0, 0, 0}, s21_TYPE_NORMAL }

#define ONE_DECIMAL \
  (s21_decimal) { {1, 0, 0, 0}, s21_TYPE_NORMAL }

typedef union {
  float as_float;
  unsigned int as_int;
} represent_float;

/*
============== Арифметика ==============
*/

#define AR_OK 0
#define AR_INF 1
#define AR_NEG_INF 2
#define AR_DIV_ZERO 3

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Сложение
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Вычитание
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Умножение
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Деление
int s21_mod(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Остаток от деления

/*
============== Сравнение ==============
*/

#define COMP_FALSE 0
#define COMP_TRUE 1

int s21_is_less(s21_decimal value_1, s21_decimal value_2);  // Меньше <
int s21_is_less_or_equal(s21_decimal value_1,
                         s21_decimal value_2);  // Меньше или равно <=
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);  // Больше >
int s21_is_greater_or_equal(s21_decimal value_1,
                            s21_decimal value_2);  // Больше или равно >=
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);  // Равно ==
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);  // Не равно !=

/*
============== Конвертеры ==============
*/

#define CONV_OK 0
#define CONV_ERR 1

int s21_from_int_to_decimal(int src, s21_decimal *dst);  // Из int в decimal
int s21_from_float_to_decimal(float src,
                              s21_decimal *dst);  // Из float в decimal
int s21_from_decimal_to_int(s21_decimal src, int *dst);  // Из decimal в int
int s21_from_decimal_to_float(s21_decimal src,
                              float *dst);  // Из decimal в float

/*
============== Дополнительные ==============
*/

#define OTH_OK 0
#define OTH_ERR 1

int s21_floor(s21_decimal value, s21_decimal *result);  // Округление вниз
int s21_round(
    s21_decimal value,
    s21_decimal *result);  // Математическое окргуление (0.5 округляется до 1)
int s21_truncate(s21_decimal value,
                 s21_decimal *result);  // Отбрасываение дробной части
int s21_negate(s21_decimal value, s21_decimal *result);  // Умножние на -1

/*
============== Вспомогательные операции с техническим bits[3] ==============
*/

unsigned int s21_get_bit(s21_decimal value, int bit_num);
unsigned int s21_get_scale(s21_decimal value);
int s21_get_sign(s21_decimal value);
void s21_set_bit(s21_decimal *value, int bit_num, int bit_condition);
void s21_set_scale(s21_decimal *value, int scale);
void s21_set_sign(s21_decimal *value, int sign);

/*
============== Вспомогательные операции с типами Decimal ==============
*/

int s21_get_decimal_type(s21_decimal value);
void s21_set_decimal_type(s21_decimal *value, int type);
int s21_is_type_normal(s21_decimal value);
int s21_types_eq(s21_decimal value_1, s21_decimal value_2);
int s21_is_type_nan(s21_decimal value);
int s21_is_type_neg_inf(s21_decimal value);
int s21_is_type_inf(s21_decimal value);

/*
============= Вспомогательные арифметические и сдвиговые операции =============
*/

int s21_sum_binary(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int s21_sub_binary(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int s21_mult_2(s21_decimal *value);
int s21_mult_10(s21_decimal *value);
void s21_div_10_binary(s21_decimal *value);
int s21_check_mod_10(s21_decimal value);
void s21_bits_shift_l(s21_decimal src, s21_decimal *dst, int amount);
void s21_decToArray(s21_decimal value, int *array, int size);
void s21_decArrayShiftLeft(int *decArray);
void s21_base10ShiftRight(int *decArray);
void s21_decArraySimpleAdd(int *sum, int *toAdd);
void s21_reverseIntArray(int *array, int size);
void s21_binToDec(int *binArray, int *ret, int arrSize);
int s21_base10truncate(int *base10arr, int scale, int sign);
int s21_comparebase10WithMax(int *base10arr);
void s21_bankRound(int *base10arr, int digit);
void s21_base10normalize(int *resBase10, int *scale_result);
void s21_base10ToDecimal(int *resBase10, int scale_result, int signRes,
                         s21_decimal *result);
int s21_signifLength(s21_decimal divisor);
void s21_fillString(int *string, int *value1, int dividend, int divisor);
int s21_divBy2ToPow(int *res);
int s21_stringComp(int *left, int *right);
void s21_appendString(int *string, int *value, int currPos);
int s21_isEmpty(int *string);
void s21_decArraySimpleSub(int *string1, int *string2);
void s21_resLoop(int *res, int len);
void s21_divByPowerTwo(int *res, int pow, int *decPoint, int *length);

/*
============== Технические операции с Decimal ==============
*/

int s21_is_zero(s21_decimal value);
s21_decimal s21_copy_dec(s21_decimal value);

/*
============== Функции нормализации Decimal ==============
*/

void s21_normalize_dec(s21_decimal *value);
void s21_align(s21_decimal *value_1, s21_decimal *value_2);

/*
============== Вспомогательные операции с float ==============
*/

void s21_set_mantissa_float(s21_decimal src, double *dst);
void s21_set_scale_float(double *dst, int scale);
void s21_set_sign_float(float *dst, int sign);
void s21_set_type_from_float(float src, s21_decimal *dst);
int s21_get_sign_float(float src);
int s21_get_scale_float(float src);
void s21_round_float(double *src, int *decimal_scale);
void s21_normalize_float(double *src, int *decimal_scale);
void s21_move_mantissa_from_float_to_decimal(represent_float represent_float,
                                             s21_decimal *dst, int bin_scale);

/*
============== Функции-исполнители основных задач ==============
*/

int s21_functional_add(int sign_1, int sign_2, s21_decimal tmp_1,
                       s21_decimal tmp_2, s21_decimal *result);
int s21_functional_mul(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
int s21_functional_div(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
#endif  // S21_DECIMAL_H