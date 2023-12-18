#include "table.hpp"

void table::printHorLine(int columns, int w) {
  std::cout << '+' << std::setfill('-');
  for (size_t i = 0; i < columns; ++i) {
    std::cout << std::right << std::setw(w + 1) << '+';
  }
  std::cout << std::endl;
}

void table::printRow(char row[][STR_SIZE], size_t len, int w) {
  std::cout << '|' << std::setfill(' ');
  for (size_t i = 0; i < len; ++i) {
    std::cout << std::left << std::setw(w) << row[i] << '|';
  }
  std::cout << std::endl;
}

void table::printTable(unsigned int **values) {
  std::system("chcp 65001 > nul");
  std::cout << "Таблица преобразований видимых символов (столбец -> строка)"
            << std::endl;
  std::system("chcp 1251 > nul");
  bool rowHasValues[CHAR_CNT], columnHasValues[CHAR_CNT];
  for (size_t i = 0; i < CHAR_CNT; ++i) {
    rowHasValues[i] = false;
    columnHasValues[i] = false;
  }
  unsigned int maxVal = 0;
  for (size_t i = 0; i < CHAR_CNT; ++i) {
    for (size_t j = 0; j < CHAR_CNT; ++j) {
      if (values[i][j] && hasGlyph_win1251(CHAR_MIN + i) &&
          hasGlyph_win1251(CHAR_MIN + j)) {
        rowHasValues[i] = true;
        columnHasValues[j] = true;
        if (values[i][j] > maxVal) {
          maxVal = values[i][j];
        }
      }
    }
  }
  int w = 0;
  while (maxVal > 0) {
    maxVal /= 10;
    ++w;
  }
  int rows = 0, columns = 1;
  for (size_t i = 0; i < CHAR_CNT; ++i) {
    if (rowHasValues[i]) {
      ++rows;
    }
    if (columnHasValues[i]) {
      ++columns;
    }
  }
  char headerRow[CHAR_CNT + 1][STR_SIZE]{" "};
  size_t headerRowIdx = 0;
  for (size_t i = 0; i < CHAR_CNT; ++i) {
    if (columnHasValues[i]) {
      headerRow[headerRowIdx + 1][0] = CHAR_MIN + static_cast<char>(i);
      ++headerRowIdx;
    }
  }
  ++headerRowIdx;
  char headerColumn[CHAR_CNT][STR_SIZE]{};
  size_t headerColumnIdx = 0;
  for (size_t i = 0; i < CHAR_CNT; ++i) {
    if (rowHasValues[i]) {
      headerColumn[headerColumnIdx][0] = CHAR_MIN + static_cast<char>(i);
      ++headerColumnIdx;
    }
  }
  printHorLine(columns, w);
  printRow(headerRow, headerRowIdx, w);
  printHorLine(columns, w);
  headerColumnIdx = 0;
  for (size_t i = 0; i < CHAR_CNT; ++i) {
    if (!rowHasValues[i]) {
      continue;
    }
    int rowIdx = 0;
    char row[CHAR_CNT + 1][STR_SIZE];
    strcpy_s(row[0], headerColumn[headerColumnIdx]);
    ++headerColumnIdx;
    for (size_t j = 0; j < CHAR_CNT; ++j) {
      if (!columnHasValues[j]) {
        continue;
      }
      sprintf(row[++rowIdx], "%d", values[i][j]);
      if (values[i][j] == 0) {
        row[rowIdx][0] = ' ';
      }
    }
    printRow(row, rowIdx + 1, w);
    printHorLine(columns, w);
  }
}

inline bool table::hasGlyph_win1251(char c) {
  return !(c >= 0 && c <= 31 || c == -104 || c == 127);
}
