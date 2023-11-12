#pragma once

#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

namespace caesar {

enum class mode { encode, decode };

char *calculateCaesarOffsets(const char *fkey, size_t &offsetsSz);

void translateCaesar(const char *fsource, const char *fkey,
                     const char *ftranslated, mode mode);

} // namespace caesar
