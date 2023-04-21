#include "s21_math.h"

long double s21_acos(double x) {
  long double y;
  if (x != x || x > 1.0 || x < -1.0) {
    y = s21_NAN;
  } else if (x == 1) {
    y = 0;
  } else if (x == -1) {
    y = s21_PI;
  } else {
    y = s21_PI_2 - s21_asin(x);
  }
  return y;
}
