#include "s21_math.h"

long double s21_tan(double x) {
  if (s21_is_nan(x)) {
    return S21_NAN;
  }
  if (s21_is_inf(x)) {
    return S21_NAN;
  }
  x = x - S21_PI * s21_floor(x / S21_PI);
  return s21_sin(x) / s21_cos(x);
}
