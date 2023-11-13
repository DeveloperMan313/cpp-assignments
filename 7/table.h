#pragma once

#include <cstring>
#include <iomanip>
#include <iostream>

const size_t STR_SIZE = 16;

void printHorLine(int columns, int w);

void printRow(char row[][STR_SIZE], size_t len, int w);

void printTable(unsigned int values[26][26], int w);
