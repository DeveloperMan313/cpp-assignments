#pragma once

#include "vector.h"
#include <cstring>
#include <iostream>

struct Dictionary {
  char *eng;
  char *rus;
};

int menu();

void add_w(vector<Dictionary *> &dict);

void print_dict(const vector<Dictionary *> &dict);

void interactive();

void demo();

void comparisonSort(vector<Dictionary *> &dArr);

namespace std {
istream &operator>>(istream &stream, vector<char> &str);
} // namespace std
