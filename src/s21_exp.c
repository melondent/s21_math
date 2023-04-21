#include "s21_math.h"

long double s21_exp(double x) {
  double val = 1.0, temp = 1.0;
  double iter = 1.0;
  if (x == s21_INF) {
    val = x;
  } else if (x == -s21_INF) {
    val = 0;
  } else if (x > 709) {
    val = s21_INF;
  } else if (x < -709) {
    val = 0;
  } else if (x != 0) {
    if (x > 0) {
      for (; temp >= s21_EPS; ++iter) {
        temp *= x / iter;
        val += temp;
      }
    } else {
      x *= -1;
      for (; temp >= s21_EPS; ++iter) {
        temp *= x / iter;
        val += temp;
      }
      val = 1 / val;
    }
  } else {
    val = 1;
  }
  return val;
}
