#include "matrix.h"

double **createMatrix(int m, int n) {
  double **matrix = new double *[m];
  for (int i = 0; i < m; ++i) {
    matrix[i] = new double[n]{0};
  }
  return matrix;
}

void deleteMatrix(double **matrix, int m) {
  for (int i = 0; i < m; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void fillMatrixA(double **matrix, int m, int n) {
  int *fac = new int[n];
  fac[0] = 1;
  for (int j = 1; j < n; ++j) {
    fac[j] = fac[j - 1] * (j + 1);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i < j) {
        matrix[i][j] = std::pow(x, i + 1) / std::pow(fac[j], i + 1);
      } else if (i == j) {
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = std::pow(-x, i + 1) / std::pow(fac[j], i + 1);
      }
    }
  }
  delete[] fac;
}

void fillMatrixB(double (&matrix)[B_sz][B_sz]) {
  for (int i = 0; i < B_sz; ++i) {
    for (int j = 0; j < B_sz; ++j) {
      matrix[i][j] = i * B_sz + j;
    }
  }
}

double **createPointerB(double matrix[B_sz][B_sz]) {
  double **B_ptr = createMatrix(B_sz, B_sz);
  for (int i = 0; i < B_sz; ++i) {
    B_ptr[i] = matrix[i];
  }
  return B_ptr;
}
