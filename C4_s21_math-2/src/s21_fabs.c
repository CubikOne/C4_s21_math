#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = x;
  if (s21_is_nan(x)) {
    result = x;
  } else {
    result = (x > 0) ? x : x * (-1);
  }
  return result;
}
