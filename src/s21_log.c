#include "s21_math.h"

long double log_0_2(double x) {
  x--;
  long double result = x, temp = x;
  long double i = 2;
  while (s21_fabs(result) > s21_EPS) {
    result *= -x * (i - 1) / i;
    i += 1;
    temp += result;
  }
  return temp;
}

long double s21_log(double x) {
  long double res;

  if (x > 0 && x < 2) {
    res = log_0_2(x);
  } else if (x < 0) {
    res = s21_NAN;
  } else if (x == 0) {
    res = -s21_INF;
  } else {
    struct special SPECIAL;
    translate(x, &SPECIAL);
    x = SPECIAL.mantisa * SPECIAL.sign / 10;
    res = log_0_2(x) + (SPECIAL.e + 1) * s21_LN10;
  }
  return res;
}

void translate(double x, struct special *SPECIAL) {
  long double i = 1;
  int e = 0;
  SPECIAL->sign = x < 0 ? -1 : 1;
  x *= SPECIAL->sign;
  while (x >= 10) {
    x /= 10.;
    i *= 10;
    e++;
  }
  SPECIAL->mantisa = x;
  SPECIAL->pow = i;
  SPECIAL->e = e;
}
