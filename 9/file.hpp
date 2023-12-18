#pragma once

#include "dictionary.hpp"
#include <fstream>

char *get_fname(std::istream &istream);

void read_file(vector<Word *> &dict, char *fname);

void write_file(const vector<Word *> &dict, char *fname);
