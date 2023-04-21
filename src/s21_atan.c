#include "s21_math.h"

long double s21_atan(double x) {
  long double y;
  if (x == s21_INF) {
    y = s21_PI_2;
  } else if (x == -s21_INF) {
    y = -s21_PI_2;
  } else {
    long double dx = 0, s21_abss = 0;
    int n = 1, flag = 0, flag_n = 0;
    if (x < 0) {
      flag_n = 1;
      x *= -1;
    }
    if (x > 1) {
      x = 1 / x;
      flag = 1;
    }
    dx = x;
    y = x;
    s21_abss = x;
    if (x != 1) {
      while (s21_abss > 0.000000000000001) {
        ++n;
        dx *= -x * x * (2 * n - 3) / (2 * n - 1);
        y += dx;
        if (dx < 0) {
          s21_abss *= -dx;
        } else {
          s21_abss = dx;
        }
      }
    } else {
      y = s21_PI_4;
    }
    if (flag == 1) {
      y = s21_PI_2 - y;
    }
    if (flag_n == 1) {
      y *= -1;
    }
  }
  return y;
}
