#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;

  long double a = x;
  long double b = y;
  if (y == 0) {
    res = S21_NAN;

  } else if (s21_is_inf(x)) {
    res = S21_NAN;

  } else if (s21_is_inf(y)) {
    res = x;

  } else {
    long long int del = a / b;
    res = (a - b * (long double)del);
  }

  return res;
}
