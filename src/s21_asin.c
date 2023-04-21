#include "s21_math.h"

long double s21_asin(double x) {
  long double y;
  if (x != x || x > 1.0 || x < -1.0) {
    y = s21_NAN;
  } else if (x == 1) {
    y = s21_PI_2;
  } else if (x == -1) {
    y = -s21_PI_2;
  } else {
    y = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return y;
}
