#include "calculus.h"

using namespace std;

double f1(double x) { return x; }

double f1_i(double a, double b) { return (b * b - a * a) / 2.0; }

double f2(double x) { return sin(22 * x); }

double f2_i(double a, double b) {
  return (cos(a * 22.0) - cos(b * 22.0)) / 22.0;
}

double f3(double x) { return x * x * x * x; }

double f3_i(double a, double b) {
  return (b * b * b * b * b - a * a * a * a * a) / 5.0;
}

double f4(double x) { return atan(x); }

double f4_i(double a, double b) {
  return b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0;
}

double sumRect(TPF f, double a, double b, int n) {
  const double dx = (b - a) / n, start = a + dx / 2;
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += f(start + dx * i);
  }
  return sum * dx;
}

double sumTrap(TPF f, double a, double b, int n) {
  const double dx = (b - a) / n;
  double sum = 0;
  for (int i = 1; i < n; ++i) {
    sum += f(a + dx * i);
  }
  return (f(a) + sum * 2 + f(b)) * dx / 2;
}

double intBase(TSUM i_sum, TPF f, double a, double b, double eps, int *n) {
  *n = 1;
  double prev_sum, sum = 0;
  for (int i = 0; i < 16; ++i) {
    *n *= 2;
    prev_sum = sum;
    sum = i_sum(f, a, b, *n);
    if (i == 0) {
      continue;
    }
    if (abs(sum - prev_sum) / 3 < eps) {
      break;
    }
  }
  return sum;
}

double IntRect(TPF f, double a, double b, double eps, int *n) {
  return intBase(sumRect, f, a, b, eps, n);
}

double IntTrap(TPF f, double a, double b, double eps, int *n) {
  return intBase(sumTrap, f, a, b, eps, n);
}
