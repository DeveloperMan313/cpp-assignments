#include "table.h"

void printHorLine(int columns, int w) {
  std::cout << '+' << std::setfill('-');
  for (size_t i = 0; i < columns; ++i) {
    std::cout << std::right << std::setw(w) << '+';
  }
  std::cout << std::endl;
}

void printRow(char *row, size_t len, int w) {
  std::cout << '|' << std::setfill(' ');
  for (size_t i = 0; i < len; ++i) {
    std::cout << std::left << std::setw(w - 1) << row[i] << '|';
  }
  std::cout << std::endl;
}

void printTable(unsigned int values[26][26], int w) {
  const int alphabetSz = 26;
  std::cout << "Таблица количества преобразований символов (строка -> столбец)"
            << std::endl;
  bool rowHasValues[alphabetSz], columnHasValues[alphabetSz];
  for (size_t i = 0; i < alphabetSz; ++i) {
    rowHasValues[i] = false;
    columnHasValues[i] = false;
  }
  for (size_t i = 0; i < alphabetSz; ++i) {
    for (size_t j = 0; j < alphabetSz; ++j) {
      if (values[i][j]) {
        rowHasValues[i] = true;
        columnHasValues[j] = true;
      }
    }
  }
  int rows = 0, columns = 1;
  for (size_t i = 0; i < alphabetSz; ++i) {
    if (rowHasValues[i]) {
      ++rows;
    }
    if (columnHasValues[i]) {
      ++columns;
    }
  }
  char headerRow[27] = {' '};
  int headerRowIdx = 0;
  for (size_t i = 0; i < alphabetSz; ++i) {
    if (rowHasValues[i]) {
      headerRow[headerRowIdx + 1] = 'a' + static_cast<char>(headerRowIdx);
      ++headerRowIdx;
    }
  }
  ++headerRowIdx;
  char headerColumn[26];
  int headerColumnIdx = 0;
  for (size_t i = 0; i < alphabetSz; ++i) {
    if (columnHasValues[i]) {
      headerColumn[headerColumnIdx] = 'a' + static_cast<char>(headerColumnIdx);
      ++headerColumnIdx;
    }
  }
  printHorLine(columns, w);
  printRow(headerRow, headerRowIdx, w);
  printHorLine(columns, w);
  for (size_t i = 0; i < alphabetSz; ++i) {
    if (!rowHasValues[i]) {
      continue;
    }
    int rowIdx = 0;
    char row[alphabetSz + 1] = {headerColumn[i]};
    for (size_t j = 0; j < alphabetSz; ++j) {
      if (!columnHasValues[j]) {
        continue;
      }
      row[++rowIdx] = static_cast<char>(
          rand() % 64 + 50); // TODO values[i][j] to cstring + remake printRow()
    }
    printRow(row, rowIdx + 1, w);
    printHorLine(columns, w);
  }
}
