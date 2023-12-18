#pragma once

#include <cmath>
#include <iostream>

typedef double (*TPF)(double);
typedef double (*TIF)(double, double);
typedef double (*TSUM)(TPF, double, double, int);
typedef double (*TCALC)(TPF, double, double, double, int *);

double f1(double x);

double f1_i(double a, double b);

double f2(double x);

double f2_i(double a, double b);

double f3(double x);

double f3_i(double a, double b);

double f4(double x);

double f4_i(double a, double b);

double sumRect(TPF f, double a, double b, int n);

double sumTrap(TPF f, double a, double b, int n);

double intBase(TSUM i_sum, TPF f, double a, double b, double eps, int *n);

double IntRect(TPF f, double a, double b, double eps, int *n);

double IntTrap(TPF f, double a, double b, double eps, int *n);
