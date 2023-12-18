#include "mprinter.hpp"

void printMatrix(double **matrix, int m, int n, mode mode, int precision,
                 int margin) {
  int maxStrLen = 0;
  char buffer[64];
  char format[] = "%.* ";
  format[3] = "ef"[static_cast<int>(mode)];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      snprintf(buffer, sizeof(buffer), format, precision, matrix[i][j]);
      int strLen = static_cast<int>(strlen(buffer));
      if (strLen > maxStrLen) {
        maxStrLen = strLen;
      }
    }
  }
  std::cout << std::setprecision(precision);
  if (mode == mode::scientific) {
    std::cout << std::scientific;
  } else {
    std::cout << std::fixed;
  }
  const int rowWidth = maxStrLen + margin,
            lineRows =
                (MAX_LINE_WIDTH / rowWidth < n) ? MAX_LINE_WIDTH / rowWidth : n,
            parts = (n + lineRows - 1) / lineRows,
            delimLen = rowWidth * lineRows;
  std::cout << std::setfill('=') << std::setw(delimLen) << '=' << std::endl;
  for (int part = 0; part < parts; ++part) {
    int startRow = lineRows * part, endRow = startRow + lineRows;
    if (endRow > n) {
      endRow = n;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = startRow; j < endRow; ++j) {
        std::cout << std::setfill(' ') << std::setw(rowWidth) << matrix[i][j];
      }
      std::cout << std::endl;
    }
    char symbol = (endRow == n) ? '=' : '-';
    std::cout << std::setfill(symbol) << std::setw(delimLen) << symbol
              << std::endl;
  }
}
