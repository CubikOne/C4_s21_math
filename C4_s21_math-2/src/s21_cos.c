#include "s21_math.h"

long double s21_factorial(int N) {
  long double result = 1.0;
  for (int i = 1; i <= N; i++) {
    result *= i;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0;
  if (s21_is_inf(x) || s21_is_nan(x)) {
    result = S21_NAN;
  } else {
    int EPS = 100;
    x = x - 2 * S21_PI * s21_floor(x / (2 * S21_PI));

    for (int i = 0; i <= EPS; i++) {
      result += s21_pow_simple(-1.0, i) * s21_pow_simple(x, 2.0 * i) /
                s21_factorial(2.0 * i);
    }
  }
  return result;
}
