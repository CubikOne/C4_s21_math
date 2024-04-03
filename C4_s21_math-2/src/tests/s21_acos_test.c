#include "s21_math_test.h"

static const double acos_array[] = {
    1.0 / 0.0, 0.0 / 0.0,     -1,           1,
    0,         -1.0 / 0.0,    0.0005,       0.5,
    0.00005,   -0.5000001,    -456.2442424, 13.4999999,
    3.9,       43.4,          0.235,        0.000023,
    -33.5,     31211221210.2, 150.81,       -1};

START_TEST(test_acos) {
  double test_number = acos_array[_i];
  long double otvet_real = acos((double)test_number);
  long double otvet_my = s21_acos(test_number);

  if (isnan(otvet_real)) {
    ck_assert_ldouble_nan(otvet_my);
  } else if (isinf(otvet_real)) {
    ck_assert_ldouble_infinite(otvet_my);
  } else {
    ck_assert_ldouble_eq_tol(otvet_my, otvet_real, TEST_EPS);
  }
}
END_TEST

Suite *suite_acos(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("ACOS");
  tc_core = tcase_create("Core");
  tcase_add_loop_test(tc_core, test_acos, 0, 30);
  suite_add_tcase(s, tc_core);
  return s;
}
