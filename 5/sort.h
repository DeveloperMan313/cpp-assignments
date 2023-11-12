#pragma once

#include <iomanip>
#include <iostream>

struct dynArray {
  int *arr;
  int length, comps, swaps;

  dynArray(int length);

  int &operator[](int i);

  ~dynArray();
};

void copyArray(dynArray &src, dynArray &dst);

void fillRand(dynArray &dArr, int mx);

void printArray(dynArray &dArr);

void comparisonSort(dynArray &dArr, bool reversed);

void bubbleSort(dynArray &dArr, bool reversed);

void printRow(const char **row, int length, int w);

void methodTable(dynArray &dArr, bool reversed, int w);

void sizeTable(int method, bool reversed, int w, int mx);
