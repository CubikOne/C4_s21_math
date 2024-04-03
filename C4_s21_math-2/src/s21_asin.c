#include "s21_math.h"

long double s21_asin(double x) {
  long double res;

  if (s21_abs((int)x) > 1)
    res = S21_NAN;
  else if (x == 1)
    res = S21_PI / 2;
  else if (x == -1)
    res = -S21_PI / 2;
  else
    res = s21_atan(x / (s21_sqrt(1 - x * x)));

  return res;
}
