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
  int *minusXPows = new int[m + 1];
  minusXPows[0] = 1;
  for (int i = 0; i < m; ++i) {
    minusXPows[i + 1] = minusXPows[i] * -x;
  }
  int *fac = new int[n];
  fac[0] = 1;
  for (int j = 1; j < n; ++j) {
    fac[j] = fac[j - 1] * (j + 1);
  }
  int minSz = (m < n) ? m : n;
  for (int i = 0; i < minSz; ++i) {
    matrix[i][i] = 1;
    for (int j = i + 1; j < m; ++j) {
      if (i == 0) {
        matrix[j][i] = minusXPows[j + 1];
      } else {
        matrix[j][i] = matrix[j][i - 1] / std::pow(i + 1, j + 1);
      }
    }
    for (int j = i + 1; j < n; ++j) {
      if (i == 0) {
        matrix[i][j] = x / fac[j];
      } else {
        matrix[i][j] = matrix[i - 1][j] * matrix[0][j];
      }
    }
  }
  delete[] minusXPows;
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
