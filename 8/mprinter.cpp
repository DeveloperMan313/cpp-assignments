#include "mprinter.h"

void printMatrix(double **matrix, int m, int n, int precision, int margin) {
  int maxStrLen = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      char str[64];
      char format[] = "% ";
      format[1] = (precision == -1) ? 'e' : 'f';
      snprintf(str, sizeof(str), format, matrix[i][j]);
      int strLen = static_cast<int>(strlen(str));
      if (strLen > maxStrLen) {
        maxStrLen = strLen;
      }
    }
  }
  if (precision == -1) {
    std::cout << std::scientific;
  } else {
    std::cout << std::fixed << std::setprecision(precision);
  }
  const int rowWidth = maxStrLen + margin, lineRows = MAX_LINE_WIDTH / rowWidth,
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
