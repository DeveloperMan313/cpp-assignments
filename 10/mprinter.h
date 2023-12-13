#pragma once

#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>

const int MAX_LINE_WIDTH = 80;

enum class mode { scientific, fixed };

void printMatrix(double **matrix, int m, int n, mode mode, int precision,
                 int margin);
