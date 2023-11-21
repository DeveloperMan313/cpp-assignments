#include "matrix.h"
#include "mprinter.h"

int main() {
  int m, n, precision, margin = 4;
  std::cout << "Input m n precision: ";
  std::cin >> m >> n >> precision;
  std::cout << "x: " << x << std::endl;
  double **A = createMatrix(m, n);
  fillMatrixA(A, m, n);
  std::cout << "A:" << std::endl;
  printMatrix(A, m, n, -1, margin);
  printMatrix(A, m, n, precision, margin);
  deleteMatrix(A, m);
  double B[B_sz][B_sz];
  fillMatrixB(B);
  double **B_ptr = createPointerB(B);
  std::cout << "B:" << std::endl;
  printMatrix(B_ptr, B_sz, B_sz, precision, margin);
  deleteMatrix(B_ptr, B_sz);
  return 0;
}
