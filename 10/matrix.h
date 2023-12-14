#pragma once

#include "mprinter.h"
#include <cstddef>
#include <iostream>

const double eps = 1e-9;

struct matrix {
  double **arr;
  size_t m, n;
};

void initMatrix(matrix &mat, size_t m, size_t n = -1);

void deleteMatrix(matrix &mat);

bool getInverse(matrix &mat, matrix &inv);

void multiplyMatrices(matrix &a, matrix &b, matrix &c);

void inputMatrix(matrix &mat);

double EPrecision(matrix &mat);

void UIInverse();

void UISLE();
