#include "s21_math_test.h"

static const double sin_array[] = {
    1.0 / 0.0, 0.0 / 0.0, -1,      1,         0,     -1.0 / 0.0,
    0.0005,    0.5,       0.997,   1.2,       2.5,   3.9,
    11.50001,  39.4999,   345.23,  991.0001,  1400,  12516222.3,
    -0.0005,   -0.5,      -0.997,  -1.2,      -2.5,  -3.9,
    -11.50001, -39.4999,  -345.23, -991.0001, -1400, -12511222.3};

START_TEST(test_sin) {
  double test_number = sin_array[_i];
  long double otvet_real = sin((double)test_number);
  long double otvet_my = s21_sin(test_number);

  if (isnan(otvet_real)) {
    ck_assert_ldouble_nan(otvet_my);
  } else if (isinf(otvet_real)) {
    ck_assert_ldouble_infinite(otvet_my);
  } else {
    ck_assert_ldouble_eq_tol(otvet_my, otvet_real, TEST_EPS);
  }
}
END_TEST

Suite *suite_sin(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("SIN");
  tc_core = tcase_create("Core");
  tcase_add_loop_test(tc_core, test_sin, 0, 30);
  suite_add_tcase(s, tc_core);
  return s;
}
