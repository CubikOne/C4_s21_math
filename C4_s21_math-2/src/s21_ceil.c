#include "s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (s21_is_inf(x) || s21_is_nan(x)) {
    result = x;
  } else {
    result = (long long int)x;
    x > result ? (result += 1) : result;
  }
  return result;
}
