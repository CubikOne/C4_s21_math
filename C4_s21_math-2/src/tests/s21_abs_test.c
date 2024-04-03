#include "s21_math_test.h"

static const double abs_array[] = {
    1.0 / 0.0, 0.0 / 0.0, -1,      1,         0,     -1.0 / 0.0,
    0.0005,    0.5,       0.997,   1.2,       2.5,   3.9,
    11.50001,  39.4999,   345.23,  991.0001,  1400,  125165161222.3,
    -0.0005,   -0.5,      -0.997,  -1.2,      -2.5,  -3.9,
    -11.50001, -39.4999,  -345.23, -991.0001, -1400, -125165161222.3};

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs((int)abs_array[_i]), abs((int)abs_array[_i]));
}
END_TEST

Suite *suite_abs(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("ABS");
  tc_core = tcase_create("Core");
  tcase_add_loop_test(tc_core, test_abs, 0, 30);
  suite_add_tcase(s, tc_core);
  return s;
}
