#include "matrix.h"
#include "mprinter.h"

int main() {
  int m, n, precisionSci, precisionFix, margin = 4;
  std::cout << "Input m, n, precision for scientific, precision for fixed: ";
  std::cin >> m >> n >> precisionSci >> precisionFix;
  std::cout << "x: " << x << std::endl;
  double **A = createMatrix(m, n);
  fillMatrixA(A, m, n);
  std::cout << "A:" << std::endl;
  printMatrix(A, m, n, mode::scientific, precisionSci, margin);
  printMatrix(A, m, n, mode::fixed, precisionFix, margin);
  deleteMatrix(A, m);
  double B[B_sz][B_sz];
  fillMatrixB(B);
  double **B_ptr = createPointerB(B);
  std::cout << "B:" << std::endl;
  printMatrix(B_ptr, B_sz, B_sz, mode::fixed, 0, margin);
  delete[] B_ptr;
  return 0;
}
