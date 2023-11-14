#include "caesar.h"

char *caesar::calculateCaesarOffsets(const char *fkey, size_t &offsetsSz) {
  std::ifstream key(fkey);
  key.seekg(0, std::ios::end);
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
    offsetsInitial[offsetsSz] %= UCHAR_MAX;
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
                             caesar::mode mode, unsigned int **stats,
                             size_t statsSz) {
  std::ifstream source(fsource);
  std::ofstream translated(ftranslated);
  size_t offsetsIdx = 0;
  char symbol;
  while (source.get(symbol)) {
    const int sign = (mode == caesar::mode::encode) ? 1 : -1;
    const char translatedSymbol =
        static_cast<char>((static_cast<int>(symbol) +
                           sign * static_cast<int>(offsets[offsetsIdx])) %
                          UCHAR_MAX);
    translated.put(translatedSymbol);
    offsetsIdx = ++offsetsIdx % offsetsSz;
    if (std::isalpha(symbol) && std::isalpha(translatedSymbol) &&
        symbol >= 'A' && translatedSymbol >= 'A') {
      const char anchorS = (symbol > 'Z') ? 'a' : 'A';
      const char anchorTS = (translatedSymbol > 'Z') ? 'a' : 'A';
      ++stats[symbol - anchorS][translatedSymbol - anchorTS];
    }
  }
  source.close();
  translated.close();
}
