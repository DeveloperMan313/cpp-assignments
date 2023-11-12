#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>

double fn(double x, int k);

double dfn(double x, int k);

double iter(double x, double eps, int k, int maxIter, int &N);

double newt(double x, double eps, int k, int maxIter, int &N);

double half(double l, double r, double eps, int k, int maxIter, int &N);

void printRow(int w, int n, double x, int N);

void printTable(int w, double eps, double x, double l, double r, int k,
                int maxIter);

void runTests(int w, double eps, int maxIter);
