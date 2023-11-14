#include "caesar.h"

wchar_t *caesar::calculateCaesarOffsets(const char *fkey, size_t &offsetsSz) {
  std::wifstream key(fkey);
  key.seekg(0, std::ios::end);
  const size_t textSz = key.tellg();
  wchar_t *word = new wchar_t[textSz + 1];
  wchar_t *offsetsInitial = new wchar_t[(textSz + 1) / 2];
  key.seekg(0, std::ios::beg);
  offsetsSz = 0;
  while (key >> word) {
    offsetsInitial[offsetsSz] = 0;
    const size_t wordLen = std::wcslen(word);
    for (size_t i = 0; i < wordLen; ++i) {
      offsetsInitial[offsetsSz] += word[i];
    }
    offsetsInitial[offsetsSz] %= 128;
    ++offsetsSz;
  }
  key.close();
  delete[] word;
  wchar_t *offsets = new wchar_t[offsetsSz];
  for (size_t i = 0; i < offsetsSz; ++i) {
    offsets[i] = offsetsInitial[i];
  }
  delete[] offsetsInitial;
  return offsets;
}

void caesar::translateCaesar(const char *fsource, const wchar_t *offsets,
                             const size_t offsetsSz, const char *ftranslated,
                             mode mode, unsigned int **stats, size_t statsSz) {
  std::wifstream source(fsource);
  std::wofstream translated(ftranslated);
  const std::locale locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>);
  source.imbue(locale);
  translated.imbue(locale);
  size_t offsetsIdx = -1;
  wchar_t symbol;
  while (source.get(symbol)) {
    offsetsIdx = ++offsetsIdx % offsetsSz;
    if (!std::iswalpha(symbol)) {
      translated.put(symbol);
      continue;
    }
    const int sign = (mode == caesar::mode::encode) ? 1 : -1;
    const int alphabetSz = (symbol <= L'z') ? 26 : 33;
    const wchar_t anchor = (symbol <= L'z') ? ((symbol < L'a') ? L'A' : L'a')
                                            : ((symbol < L'а') ? L'А' : L'а');
    int translatedSymbolInt = static_cast<int>(symbol - anchor) +
                              sign * static_cast<int>(offsets[offsetsIdx]);
    if (translatedSymbolInt >= alphabetSz) {
      translatedSymbolInt %= alphabetSz;
    } else {
      while (translatedSymbolInt < 0) {
        translatedSymbolInt += alphabetSz;
      }
    }
    const wchar_t translatedSymbol =
        anchor + static_cast<wchar_t>(translatedSymbolInt);
    translated.put(translatedSymbol);
    if (symbol <= L'z' && translatedSymbol <= L'z') {
      ++stats[symbol - anchor][translatedSymbol - anchor];
    }
  }
  source.close();
  translated.close();
}
