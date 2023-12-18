#include "caesar.hpp"

char *caesar::calculateCaesarOffsets(const char *fkey, size_t &offsetsSz) {
  std::ifstream key(fkey, std::ios::binary | std::ios::in | std::ios::ate);
  const size_t textSz = key.tellg();
  char *word = new char[textSz + 1];
  char *offsetsInitial = new char[(textSz + 1) / 2];
  key.seekg(0, std::ios::beg);
  offsetsSz = 0;
  while (key >> word) {
    offsetsInitial[offsetsSz] = 0;
    const size_t wordLen = std::strlen(word);
    for (size_t i = 0; i < wordLen; ++i) {
      offsetsInitial[offsetsSz] += word[i];
    }
    ++offsetsSz;
  }
  key.close();
  delete[] word;
  char *offsets = new char[offsetsSz];
  for (size_t i = 0; i < offsetsSz; ++i) {
    offsets[i] = offsetsInitial[i];
  }
  delete[] offsetsInitial;
  return offsets;
}

void caesar::translateCaesar(const char *fsource, const char *offsets,
                             const size_t offsetsSz, const char *ftranslated,
                             caesar::mode mode, unsigned int **stats) {
  std::ifstream source(fsource, std::ios::binary | std::ios::in);
  std::ofstream translated(ftranslated, std::ios::binary | std::ios::out);
  const char sign = (mode == caesar::mode::encode) ? 1 : -1;
  size_t offsetsIdx = 0;
  char symbol;
  while (source.get(symbol)) {
    const char translatedSymbol = symbol + sign * offsets[offsetsIdx];
    translated.put(translatedSymbol);
    offsetsIdx = ++offsetsIdx % offsetsSz;
    ++stats[static_cast<int>(translatedSymbol) - CHAR_MIN]
           [static_cast<int>(symbol) - CHAR_MIN];
  }
  source.close();
  translated.close();
}
