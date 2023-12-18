#pragma once

#include "vector.hpp"
#include <iostream>
#include <sstream>

struct Word {
  char *eng;
  char *rus;
};

int menu(std::istream &istream);

void interactive(std::istream &istream, bool demo);

void demo();

void add_word(vector<Word *> &dict, vector<char> &eng, vector<char> &rus);

void delete_word(vector<Word *> &dict, const vector<char> &eng);

void translate_eng(const vector<Word *> &dict, const vector<char> &eng);

void translate_rus(const vector<Word *> &dict, const vector<char> &rus);

void print_dict(const vector<Word *> &dict);

bool dict_empty(const vector<Word *> &dict);

void sort_dict(vector<Word *> &dict);

inline void delete_dict_entry(vector<Word *> &dict, size_t i);

void clear_dict(vector<Word *> &dict);

size_t find_eng(const vector<Word *> &dict, const vector<char> &eng);

int strcmp(const char *s1, const char *s2);

namespace std {
istream &operator>>(istream &stream, vector<char> &str);
} // namespace std
