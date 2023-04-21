#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 4, temp = 0;
  while (s21_fabs(result - temp) > s21_EPS) {
    if (x < 0) {
      result = -s21_NAN;
      break;
    }
    temp = result;
    result = (temp + x / temp) / 2;
  }
  return result;
}
