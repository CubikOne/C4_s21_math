#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0.0;

  if (x == 1) {
    result = S21_PI / 4;
  } else if (x == -1) {
    result = -S21_PI / 4;
  } else if (x == S21_INF) {
    result = S21_PI / 2;
  } else if (x == S21_INF_NEGATIVE) {
    result = -S21_PI / 2;
  } else if (x != x) {
    result = S21_NAN;
  } else if (s21_fabs(x) < 1.0) {
    long double delta = 1.0;
    int i = 0;
    while (s21_fabs(delta) > S21_EPS) {
      delta = (s21_pow_simple(-1.0, i) * s21_pow_simple(x, 1 + 2 * i)) /
              (1 + 2 * i);
      i++;
      result += delta;
    }
  } else {
    if (x > 1) {
      result = S21_PI / 2 - s21_atan(1 / x);
    } else {
      result = -S21_PI / 2 - s21_atan(1 / x);
    }
  }
  return result;
}
