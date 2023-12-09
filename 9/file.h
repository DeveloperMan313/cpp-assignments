#pragma once

#include "dictionary.h"
#include <fstream>

char *get_fname(std::istream &istream);

void read_file(vector<Dictionary *> &dict, char *fname);

void write_file(const vector<Dictionary *> &dict, char *fname);
