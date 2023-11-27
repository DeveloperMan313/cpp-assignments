#pragma once

#include <cmath>

const double x = 2.0;
const int B_sz = 10;

double **createMatrix(int m, int n);

void deleteMatrix(double **matrix, int m);

void fillMatrixA(double **matrix, int m, int n);

void fillMatrixB(double (&matrix)[B_sz][B_sz]);

double **createPointerB(double (&matrix)[B_sz][B_sz]);
