#include "s21_math.h"

long double s21_pow_simple(long double x, long long int n) {
  long double res = 1;
  int minus = 0;
  int stop = 0;

  if (n == 0) {
    res = 1;
    stop = 1;
  } else if (n < 0) {
    n = -n;
    minus = 1;
  }

  while (!stop) {
    res = res * x;
    n -= 1;
    if (n < 1) {
      stop = 1;
    }
    if (res > S21_MAX_LDOUBLE) {
      stop = 1;
      res = S21_INF;
    }
  }
  if (minus) {
    res = 1 / res;
  }

  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0.0;
  long long int power = 0;

  if (s21_isfinite(exp)) {
    if (exp > 9223372036854775807) {
      exp = S21_INF;

    } else if (exp < -9223372036854775807) {
      exp = S21_INF_NEGATIVE;
    } else {
      power = (long long int)exp;
      exp = exp - power;
    }
  }

  long double new_base = base;
  int power_e = 0;
  if (!s21_isfinite(base)) {
    new_base = base;
  } else {
    while (new_base > 1) {
      new_base = new_base / S21_E;
      power_e += 1;
    }
  }
  if (exp == 0 && power == 0) {
    res = 1;
  } else if (s21_is_nan(base)) {
    res = S21_NAN;

  } else if (exp == S21_INF) {
    if (base == 1 || base == -1) {
      res = 1;
    } else if (base == 0) {
      res = 0;
    } else if (base == S21_INF_NEGATIVE) {
      res = S21_INF;

    } else if (s21_fabs(base) < 1) {
      res = 0;

    } else {
      res = S21_INF;
    }
  } else if (exp == S21_INF_NEGATIVE) {
    if (base == 1 || base == -1) {
      res = 1;
    } else if (base == 0) {
      res = S21_INF;
    } else if (base == S21_INF_NEGATIVE) {
      res = 0;

    } else if (s21_fabs(base) < 1) {
      res = S21_INF;
    } else {
      res = 0;
    }
  } else if (s21_is_nan(exp)) {
    if (base == 1) {
      res = 1;
    } else {
      res = S21_NAN;
    }

  } else if (exp < 0 || power < 0) {
    if (base == 0) {
      res = S21_INF;
    } else if (base < 0) {
      if (exp != 0.0) {
        res = S21_NAN;
      } else {
        res = s21_pow_simple(base, power);
      }
    } else {
      exp = -exp;
      power = -power;
      if (s21_log(base) > S21_MAX_LDOUBLE) {
        res = 0;
      } else {
        res = 1.0 / (s21_exp(((long double)exp) * s21_log(new_base)) *
                     s21_pow_simple(s21_exp(exp), power_e) *
                     s21_pow_simple(base, power));
      }
    }

  } else {
    if (base == 0) {
      res = 0;
    } else if (base < 0) {
      if (exp != 0.0) {
        res = S21_NAN;
      } else {
        res = s21_pow_simple(base, power);
      }

    } else {
      if (s21_log(base) > S21_MAX_LDOUBLE) {
        res = S21_INF;
      } else {
        res = s21_exp(((long double)exp) * s21_log(new_base)) *
              s21_pow_simple(s21_exp(exp), power_e) *
              s21_pow_simple(base, power);
      }
    }
  }

  if (res > S21_MAX_LDOUBLE) {
    res = S21_INF;
  }
  if (res < -S21_MAX_LDOUBLE) {
    res = S21_INF_NEGATIVE;
  }

  return res;
}
