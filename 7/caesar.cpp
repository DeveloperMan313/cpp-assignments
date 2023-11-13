#include "caesar.h"

char *caesar::calculateCaesarOffsets(const char *fkey, size_t &offsetsSz) {
  std::wifstream key(fkey);
  key.seekg(0, std::ios::end);
  const size_t textSz = key.tellg();
  wchar_t *word = new wchar_t[textSz + 1];
  char *offsetsInitial = new char[(textSz + 1) / 2];
  key.seekg(0, std::ios::beg);
  offsetsSz = 0;
  while (key >> word) {
    offsetsInitial[offsetsSz] = 0;
    for (char symbol = *word; symbol != '\0'; ++symbol) {
      offsetsInitial[offsetsSz] += static_cast<char>(wcslen(word));
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
                             const char *ftranslated, caesar::mode mode,
                             unsigned int **stats, size_t statsSz) {
  std::wifstream source(fsource);
  std::wofstream translated(ftranslated);
  source.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
  translated.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
  size_t offsetsSz, offsetsIdx = 0;
  const char *offsets = caesar::calculateCaesarOffsets(fkey, offsetsSz);
  wchar_t symbol;
  while (source.get(symbol)) {
    if (std::iswalpha(symbol)) {
      const int sign = (mode == caesar::mode::encode) ? 1 : -1;
      const int alphabetSz = (symbol <= L'z') ? 26 : 33;
      const wchar_t anchor = (symbol <= L'z') ? ((symbol < L'a') ? L'A' : L'a')
                                              : ((symbol < L'а') ? L'А' : L'а');
      int translatedSymbol = static_cast<int>(symbol - anchor) +
                             sign * static_cast<int>(offsets[offsetsIdx]);
      if (translatedSymbol >= alphabetSz) {
        translatedSymbol %= alphabetSz;
      } else {
        while (translatedSymbol < 0) {
          translatedSymbol += alphabetSz;
        }
      }
      translatedSymbol =
          static_cast<wchar_t>(anchor + static_cast<wchar_t>(translatedSymbol));
      translated.put(translatedSymbol);
      if (symbol <= L'z' && translatedSymbol <= L'z') {
        if (symbol > L'Z') {
          symbol -= alphabetSz + 6;
        }
        if (translatedSymbol > L'Z') {
          translatedSymbol -= alphabetSz + 6;
        }
        std::cout << symbol - anchor << ' ' << translatedSymbol - anchor
                  << std::endl;
        ++stats[symbol - anchor][translatedSymbol - anchor];
      }
    } else {
      translated.put(symbol);
    }
    offsetsIdx = (offsetsIdx + 1) % offsetsSz;
  }
  source.close();
  translated.close();
}
