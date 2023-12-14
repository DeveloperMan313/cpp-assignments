#include "matrix.h"

void initMatrix(matrix &mat, size_t m, size_t n) {
  if (n == -1) {
    n = m;
  }
  mat.arr = new double *[m];
  for (size_t i = 0; i < m; ++i) {
    mat.arr[i] = new double[n]{0};
  }
  mat.m = m;
  mat.n = n;
}

void deleteMatrix(matrix &mat) {
  for (size_t i = 0; i < mat.m; ++i) {
    delete[] mat.arr[i];
  }
  delete[] mat.arr;
}

bool getInverse(matrix &mat, matrix &inv) {
  initMatrix(inv, mat.m);
  for (size_t i = 0; i < mat.m; ++i) {
    inv.arr[i][i] = 1;
  }
  for (size_t i = 0; i < mat.m; ++i) {
    if (abs(mat.arr[i][i]) < eps) {
      bool found = false;
      for (size_t j = i + 1; j < mat.m; ++j) {
        if (abs(mat.arr[j][i]) > eps) {
          std::swap(mat.arr[i], mat.arr[j]);
          std::swap(inv.arr[i], inv.arr[j]);
          found = true;
          break;
        }
      }
      if (!found) {
        return false;
      }
    }
    double mult = 1 / mat.arr[i][i];
    for (size_t j = 0; j < mat.m; ++j) {
      mat.arr[i][j] *= mult;
      inv.arr[i][j] *= mult;
    }
    for (size_t j = 0; j < mat.m; ++j) {
      if (j == i) {
        continue;
      }
      double mult = mat.arr[j][i];
      for (size_t k = 0; k < mat.m; ++k) {
        mat.arr[j][k] -= mat.arr[i][k] * mult;
        inv.arr[j][k] -= inv.arr[i][k] * mult;
      }
    }
  }
  return true;
}

void multiplyMatrices(matrix &a, matrix &b, matrix &c) {
  if (a.n != b.m) {
    return;
  }
  initMatrix(c, a.m, b.n);
  for (size_t i = 0; i < a.m; ++i) {
    for (size_t j = 0; j < b.n; ++j) {
      double sum = 0;
      for (size_t k = 0; k < a.n; ++k) {
        sum += a.arr[i][k] * b.arr[k][j];
      }
      c.arr[i][j] = sum;
    }
  }
}

void inputMatrix(matrix &mat) {
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      std::cin >> mat.arr[i][j];
    }
  }
}

double EPrecision(matrix &mat) {
  double sum = 0;
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.m; ++j) {
      if (i != j) {
        sum += abs(mat.arr[i][j]);
      }
    }
  }
  return sum / ((mat.m - 1) * mat.m);
}

void UIInverse() {
  const int margin = 4, precision = 2;
  matrix matI, mat, inv;
  size_t m;
  std::cout << "Введите размер квадратной матрицы" << std::endl;
  std::cin >> m;
  initMatrix(matI, m);
  initMatrix(mat, m);
  std::cout << "Введите матрицу A" << std::endl;
  inputMatrix(matI);
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < m; ++j) {
      mat.arr[i][j] = matI.arr[i][j];
    }
  }
  if (!getInverse(mat, inv)) {
    std::cout << "Обратной матрицы не существует" << std::endl;
  } else {
    std::cout << "Обратная матрица (A^-1):" << std::endl;
    printMatrix(inv.arr, inv.m, inv.m, mode::fixed, precision, margin);
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < m; ++j) {
        mat.arr[i][j] = matI.arr[i][j];
      }
    }
    matrix product;
    multiplyMatrices(mat, inv, product);
    std::cout << "A * A^-1 = " << std::endl;
    printMatrix(product.arr, inv.m, inv.m, mode::fixed, precision, margin);
    std::cout << "Точность обратной матрицы: " << std::scientific
              << EPrecision(product) << std::endl;
    deleteMatrix(product);
  }
  deleteMatrix(mat);
  deleteMatrix(inv);
}

void UISLE() {
  const int margin = 4, precision = 2;
  matrix mat, inv;
  size_t m;
  std::cout << "Введите размер квадратной матрицы" << std::endl;
  std::cin >> m;
  initMatrix(mat, m);
  std::cout << "Введите матрицу коэффициентов системы" << std::endl;
  inputMatrix(mat);
  if (!getInverse(mat, inv)) {
    std::cout << "Обратной матрицы не существует" << std::endl;
  } else {
    matrix freeTerms, solution;
    initMatrix(freeTerms, m, 1);
    std::cout << "Введите вектор свободных членов системы" << std::endl;
    inputMatrix(freeTerms);
    multiplyMatrices(inv, freeTerms, solution);
    std::cout << "Решение системы:" << std::endl;
    printMatrix(solution.arr, solution.m, solution.n, mode::fixed, precision,
                margin);
  }
}
