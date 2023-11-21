#pragma once

#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>

const int MAX_LINE_WIDTH = 80;

void printMatrix(double **matrix, int m, int n, int precision, int margin);
