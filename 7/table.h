#pragma once

#include <iomanip>
#include <iostream>

void printHorLine(int columns, int w);

void printRow(char *row, size_t len, int w);

void printTable(unsigned int values[26][26], int w);
