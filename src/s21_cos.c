#include "s21_math.h"

long double s21_cos(double x) {
  long double y;
  if (x == s21_INF || x == -s21_INF) {
    y = -s21_NAN;
  } else {
    if (x < 0) {
      x *= -1;
    }
    while (x >= 2 * s21_PI) {
      x -= 2 * s21_PI;
    }
    x = s21_PI_2 - x;
    y = s21_sin(x);
  }
  return y;
}
