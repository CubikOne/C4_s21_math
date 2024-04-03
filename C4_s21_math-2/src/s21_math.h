#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_EPS 1e-9
#define S21_INF (1.0 / 0.0)
#define S21_INF_NEGATIVE (-1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)
#define S21_E 2.718281828459045
#define S21_PI 3.14159265358979323846
#define s21_LN10 2.30258509299404590109
#define S21_MAX_LDOUBLE 1.79769313486231571e308

#define s21_is_inf(x) (x == S21_INF || x == S21_INF_NEGATIVE)
#define s21_isfinite(x) ((!s21_is_inf(x) && !s21_is_nan(x)))
#define s21_is_nan(x) (x != x)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_factorial(int N);
long double s21_pow_simple(long double x, long long int n);
int s21_find_stepen(long double x);
int s21_difussion(double *x);

#endif
