#pragma once

#include <codecvt>
#include <cstring>
#include <cwchar>
#include <cwctype>
#include <fstream>

namespace caesar {

enum class mode { encode, decode };

wchar_t *calculateCaesarOffsets(const char *fkey, size_t &offsetsSz);

void translateCaesar(const char *fsource, const char *fkey,
                     const char *ftranslated, mode mode, unsigned int **stats,
                     size_t statsSz);

} // namespace caesar
