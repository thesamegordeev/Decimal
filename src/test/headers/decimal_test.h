#ifndef DECIMAL_TEST_H
#define DECIMAL_TEST_H

#include <check.h>
#include <stdio.h>

#include "../../s21_decimal.h"
#include "another_test.h"
#include "arithmetic_test.h"
#include "comparison_test.h"
#include "convertors_test.h"

void create_case(Suite *suite, const char *tcase_name,
                 void (*add_cases)(TCase *));

void set_from_decimal_to_float_case(Suite *suite);
void set_from_decimal_to_int_case(Suite *suite);
void set_from_float_to_decimal_case(Suite *suite);
void set_from_int_to_decimal_case(Suite *suite);

void set_is_equal_case(Suite *suite);
void set_is_greater_or_equal_case(Suite *suite);
void set_is_greater_case(Suite *suite);
void set_is_less_or_equal_case(Suite *suite);
void set_is_less_case(Suite *suite);
void set_is_not_equal_case(Suite *suite);

void set_add_case(Suite *suite);
void set_div_case(Suite *suite);
void set_mod_case(Suite *suite);
void set_mul_case(Suite *suite);
void set_sub_case(Suite *suite);

void set_floor_case(Suite *suite);
void set_negate_case(Suite *suite);
void set_round_case(Suite *suite);
void set_truncate_case(Suite *suite);
void set_shift_case(Suite *suite);

#endif  // DECIMAL_TEST_H
