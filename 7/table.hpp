#pragma once

#include <cstring>
#include <iomanip>
#include <iostream>

namespace table {

const size_t STR_SIZE = 11;
const size_t CHAR_CNT = UCHAR_MAX + 1;

void printHorLine(int columns, int w);

void printRow(char row[][STR_SIZE], size_t len, int w);

void printTable(unsigned int **values);

inline bool hasGlyph_win1251(char c);

} // namespace table
