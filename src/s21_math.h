#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_PI 3.141592653589793116
#define s21_PI_2 1.570796326794896558
#define s21_PI_3 1.047197551196597853
#define s21_PI_4 0.785398163397448309

#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-17
#define s21_LN10 2.30258509299404590109

struct special {
  int sign;
  long double mantisa;
  long double pow;
  int e;
};

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
int s21_abs(int x);
long double s21_ln(double x);
long double s21_log(double x);
long double simple_pow(double x, int y);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
double delete (double x);
void translate(double x, struct special *SPECIAL);

#endif  // SRC_S21_MATH_H_
