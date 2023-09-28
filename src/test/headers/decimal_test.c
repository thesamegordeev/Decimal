#include "decimal_test.h"

void create_case(Suite *suite, const char *tcase_name,
                 void (*add_cases)(TCase *)) {
  TCase *test_case = tcase_create(tcase_name);
  add_cases(test_case);
  suite_add_tcase(suite, test_case);
}