#include "headers/decimal_test.h"

Suite *get_convertors_suite() {
  Suite *convertors_suite = suite_create("Convertors_suite");
  set_from_decimal_to_float_case(convertors_suite);
  set_from_float_to_decimal_case(convertors_suite);
  set_from_decimal_to_int_case(convertors_suite);
  set_from_int_to_decimal_case(convertors_suite);
  return convertors_suite;
}

Suite *get_comparison_suite() {
  Suite *comparison_suite = suite_create("Comparison_suite");
  set_is_equal_case(comparison_suite);
  set_is_not_equal_case(comparison_suite);
  set_is_greater_case(comparison_suite);
  set_is_less_case(comparison_suite);
  set_is_greater_or_equal_case(comparison_suite);
  set_is_less_or_equal_case(comparison_suite);
  return comparison_suite;
}

Suite *get_another_suite() {
  Suite *another_suite = suite_create("Another_suite");
  set_negate_case(another_suite);
  set_truncate_case(another_suite);
  set_floor_case(another_suite);
  set_round_case(another_suite);
  return another_suite;
}

Suite *get_arithmetic_suite() {
  Suite *arithmetic_suite = suite_create("Arithmetic_suite");
  set_add_case(arithmetic_suite);
  set_sub_case(arithmetic_suite);
  set_div_case(arithmetic_suite);
  set_mul_case(arithmetic_suite);
  return arithmetic_suite;
}

int main() {
  Suite *suites[] = {get_convertors_suite(), get_comparison_suite(),
                     get_another_suite(), get_arithmetic_suite(), NULL};

  for (int i = 0; suites[i] != NULL; i++, puts("")) {
    SRunner *runner = srunner_create(suites[i]);

    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }
}