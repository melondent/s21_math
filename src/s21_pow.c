#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double number;
  if (base < 0) {
    if ((long int)exp == exp) {
      if (exp > 0) {
        number = base;
        for (long int i = 0; i < (long int)exp - 1; i++) {
          number *= base;
        }
      } else if (exp == 0) {
        number = 1;
      } else {
        number = 1 / base;
        for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
          number /= base;
        }
      }
    } else {
      if (exp == -s21_INF || exp == s21_INF) {
        if (base * (-1) < 1) {
          number = 0;
        } else if (base * (-1) == 1) {
          number = 1;
        } else {
          if (exp == -s21_INF) {
            number = 0;
          } else {
            number = s21_INF;
          }
        }
      } else {
        number = -s21_NAN;
      }
    }
  } else if (base == 0) {
    if (exp == 0) {
      number = 1;
    } else {
      number = 0;
    }
  } else if (base == 1) {
    number = 1;
  } else {
    if ((long int)exp == exp) {
      if (exp > 0) {
        number = base;
        for (long int i = 0; i < (long int)exp - 1; i++) {
          number *= base;
        }
      } else if (exp == 0) {
        number = 1;
      } else {
        number = 1 / base;
        for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
          number /= base;
        }
      }
    } else {
      number = s21_exp(exp * (double)s21_log(base));
    }
  }
  return number;
}
