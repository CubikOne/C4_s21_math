#include "s21_math_test.h"

int main(void) {
  Suite *list_cases[] = {
      suite_abs(),   suite_acos(), suite_asin(), suite_atan(),
      suite_ceil(),  suite_cos(),  suite_exp(),  suite_fabs(),
      suite_floor(), suite_fmod(), suite_log(),  suite_pow(),
      suite_sin(),   suite_sqrt(), suite_tan(),  NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    SRunner *runner = srunner_create(list_cases[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}
