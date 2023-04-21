#include "s21_math.h"

long double s21_sin(double x) {
  x = delete (x);
  long double result = x, temp = x;
  long double i = 1.;
  while (s21_fabs(result) > s21_EPS) {
    result = -1 * result * x * x / (2 * i * (2 * i + 1));
    i += 1.;
    temp += result;
  }
  return temp;
}

double delete (double x) {
  while (x > s21_PI || x < -s21_PI) {
    x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
  }
  return x;
}
