#include "s21_math.h"

long double s21_exp(double x) {
  long double num = x;
  long double result = 0.0;
  long double a;
  long double n;

  if (s21_is_nan(x)) {
    result = x;
  } else if (x >= 1024.0) {
    result = S21_INF;
  } else if (x >= -16.0) {
    a = 1.0;
    n = 0.0;
    while (a > 1.0e-16L || a < -1.0e-16L) {
      result += a;
      n += 1.0;
      a *= num / n;
    }
  }

  return ((double)result);
}