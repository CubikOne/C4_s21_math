#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0.0;

  if (x < 0) {
    res = S21_NAN;
  } else if (x == 0) {
    res = S21_INF_NEGATIVE;
  } else if (x == 1) {
    res = 0;
  } else if (s21_is_nan(x) || x == S21_INF) {
    res = x;

  } else {
    int power = s21_difussion(&x);
    x = x / 10;
    power = power + 1;

    long double delta = 1.0;
    long double y = x - 1;
    int i = 1;
    double znak = 1;
    int stop = 0;
    while (!stop) {
      delta = delta * y;
      res = res + znak * delta / i;
      i += 1;
      znak = znak * (-1);
      if (s21_fabs(delta / i) < S21_EPS) {
        stop = 1;
        res = res + power * s21_LN10;
      }
    }
  }

  return res;
}

int s21_difussion(double *x) {
  int res = 0;
  int stepen = s21_find_stepen((long double)(*x));
  res = stepen;

  *x = *x * s21_pow_simple(10.0, -stepen);

  return res;
}

int s21_find_stepen(long double x) {
  int res = 0;
  if (s21_fabs(x) >= 10.0) {
    while (s21_fabs(x) >= 10.0) {
      res += 1;
      x = x / 10.0;
    }
  } else if (s21_fabs(x) < 1.0)

    while (s21_fabs(x) < 1.0) {
      res -= 1;
      x = x * 10.0;
    }
  return res;
}
