#pragma once

#include <cctype>
#include <cstring>
#include <fstream>

namespace caesar {

enum class mode { encode, decode };

char *calculateCaesarOffsets(const char *fkey, size_t &offsetsSz);

void translateCaesar(const char *fsource, const char *offsets,
                     const size_t offsetsSz, const char *ftranslated,
                     caesar::mode mode, unsigned int **stats, size_t statsSz);

} // namespace caesar
