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
    for (char symbol = *word; symbol != '\0'; ++symbol) {
      offsetsInitial[offsetsSz] += static_cast<char>(strlen(word));
    }
    offsetsInitial[offsetsSz] %= 128;
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

void caesar::translateCaesar(const char *fsource, const char *fkey,
                             const char *ftranslated, caesar::mode mode) {
  std::ifstream source(fsource);
  std::ofstream translated(ftranslated);
  size_t offsetsSz, offsetsIdx = 0;
  const char *offsets = caesar::calculateCaesarOffsets(fkey, offsetsSz);
  char symbol;
  while (source.get(symbol)) {
    if (std::isalpha(symbol)) {
      const int alphabetSz = 26;
      const int sign = (mode == caesar::mode::encode) ? 1 : -1;
      const char anchor = (symbol < 'a') ? 'A' : 'a';
      int translatedSymbol = static_cast<int>(symbol - anchor) +
                             sign * static_cast<int>(offsets[offsetsIdx]);
      if (translatedSymbol >= alphabetSz) {
        translatedSymbol %= alphabetSz;
      } else {
        while (translatedSymbol < 0) {
          translatedSymbol += alphabetSz;
        }
      }
      translated.put(static_cast<char>(anchor + translatedSymbol));
    } else {
      translated.put(symbol);
    }
    offsetsIdx = (offsetsIdx + 1) % offsetsSz;
  }
  source.close();
  translated.close();
}
