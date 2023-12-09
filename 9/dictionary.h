#pragma once

#include "vector.h"
#include <iostream>
#include <sstream>

struct Dictionary {
  char *eng;
  char *rus;
};

int menu(std::istream &istream);

void interactive(std::istream &istream, bool demo);

void demo();

void add_word(vector<Dictionary *> &dict, vector<char> &eng, vector<char> &rus);

void delete_word(vector<Dictionary *> &dict, const vector<char> &eng);

void translate_eng(const vector<Dictionary *> &dict, const vector<char> &eng);

void translate_rus(const vector<Dictionary *> &dict, const vector<char> &rus);

void print_dict(const vector<Dictionary *> &dict);

bool dict_empty(const vector<Dictionary *> &dict);

void sort_dict(vector<Dictionary *> &dict);

inline void delete_dict_entry(vector<Dictionary *> &dict, size_t i);

void clear_dict(vector<Dictionary *> &dict);

size_t find_eng(const vector<Dictionary *> &dict, const vector<char> &word);

int strcmp(const char *s1, const char *s2);

namespace std {
istream &operator>>(istream &stream, vector<char> &str);
} // namespace std
