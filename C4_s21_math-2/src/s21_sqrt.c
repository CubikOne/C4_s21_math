#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0 || s21_is_nan(x)) {
    res = S21_NAN;
  } else if (x == S21_INF || x <= S21_EPS) {
    res = x;
  } else {
    long double left = 0;
    long double right = 0;
    long double mid = 0;

    if (x > 1)
      right = x;
    else
      right = 1;

    mid = (left + right) / 2;

    while ((mid - left) > S21_EPS) {
      if (mid * mid > x) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (left + right) / 2;
    }
    res = mid;
  }
  return res;
}