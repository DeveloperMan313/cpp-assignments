#include "rootfinder.h"

using namespace std;

double fn(double x, int k) { return x - k * cos(x); }

double dfn(double x, int k) { return 1.0 + k * sin(x); }

double iter(double x, double eps, int k, int maxIter, int &N) {
  double y = 0.0;
  N = 0;
  do {
    x -= y;
    y = fn(x, k);
  } while (abs(y) > eps && ++N < maxIter);
  return x;
}

double newt(double x, double eps, int k, int maxIter, int &N) {
  double y = 0.0;
  N = 0;
  do {
    x -= y / dfn(x, k);
    y = fn(x, k);
  } while (abs(y) > eps && ++N < maxIter);
  return x;
}

double half(double l, double r, double eps, int k, int maxIter, int &N) {
  double m, y;
  N = 0;
  do {
    m = (l + r) / 2;
    y = fn(m, k);
    if (abs(y) < eps)
      break;
    if (y > 0)
      r = m;
    else
      l = m;
  } while (++N < maxIter);
  return m;
}

void printRow(int w, int n, double x, int N) {
  cout << defaultfloat << setw(w) << n << setprecision(8) << fixed << setw(w)
       << x << defaultfloat << N << endl;
}

void printTable(int w, double eps, double x, double l, double r, int k,
                int maxIter) {
  cout << "Уравнение: ";
  if (k == 1)
    cout << "x - cos(x) = 0";
  else
    cout << "x - k * cos(x) = 0, k = " << k;
  cout << ". Погрешность: " << eps << endl << left;
  cout << setw(w) << "№ метода" << setw(w) << "x"
       << "N" << endl;
  int N;
  double X = iter(x, eps, k, maxIter, N);
  printRow(w, 1, X, N);
  X = newt(x, eps, k, maxIter, N);
  printRow(w, 2, X, N);
  X = half(l, r, eps, k, maxIter, N);
  printRow(w, 3, X, N);
  cout << endl;
}

void runTests(int w, double eps, int maxIter) {
  double x, l, r;
  cout << "Введите стартовое значение x для итерационных методов\n"
          "и границы l r для метода половинного деления"
       << endl;
  cin >> x >> l >> r;
  printTable(w, eps, x, l, r, 1, maxIter);
  printTable(w, eps, x, l, r, 5, maxIter);
  printTable(w, eps, x, l, r, 10, maxIter);
}
