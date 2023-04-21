#include "s21_math.h"

long double s21_ceil(double x) {
  int i = 0;
  double score = 0;
  if (x < 0)
    score = -x;
  else
    score = x;
  for (i = 0; i < score; i++) {
  }
  return x < 0 ? -i + 1 : i;
}
