#include "s21_math.h"

long double s21_tan(double x) {
  long double y = 0;
  if (x == s21_INF || x == -s21_INF) {
    y = -s21_NAN;
  } else {
    long double sin_x = s21_sin(x), cos_x = s21_cos(x);
    if (cos_x == 0) {
      y = 16331239353195370;  // s21_INF
    } else {
      y = sin_x / cos_x;
    }
  }
  return y;
}
