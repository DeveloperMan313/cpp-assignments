#include "matrix.hpp"

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
  matrix[0][0] = 1.0;
  if (m > 1) {
    matrix[1][0] = x * x;
  }
  if (n > 1) {
    matrix[0][1] = x / 2;
  }
  for (int j = 2; j < m; ++j) {
    matrix[j][0] = matrix[j - 1][0] * -x;
  }
  for (int j = 2; j < n; ++j) {
    matrix[0][j] = matrix[0][j - 1] / (j + 1);
  }
  int minSz = (m < n) ? m : n;
  for (int i = 1; i < minSz; ++i) {
    matrix[i][i] = 1.0;
    for (int j = i + 1; j < m; ++j) {
      matrix[j][i] = matrix[j][i - 1] / std::pow(i + 1, j + 1);
    }
    for (int j = i + 1; j < n; ++j) {
      matrix[i][j] = matrix[i - 1][j] * matrix[0][j];
    }
  }
}

void fillMatrixB(double (&matrix)[B_sz][B_sz]) {
  for (int i = 0; i < B_sz; ++i) {
    for (int j = 0; j < B_sz; ++j) {
      matrix[i][j] = i * B_sz + j;
    }
  }
}

double **createPointerB(double (&matrix)[B_sz][B_sz]) {
  double **B_ptr = new double *[B_sz];
  for (int i = 0; i < B_sz; ++i) {
    B_ptr[i] = matrix[i];
  }
  return B_ptr;
}
