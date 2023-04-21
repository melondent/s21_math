#include "s21_math.h"

long double s21_fmod(double x, double y) {
  return (x && y) || y != 0 ? (x / y - (int)(x / y)) * y : s21_NAN;
}

// Функция рассчитывает остаток от деления x на y по формуле x - n *y,
//     где n – это результат деления x на y округленный в сторону нуля.
