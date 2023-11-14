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
    offsetsInitial[offsetsSz] %= WCHAR_MAX;
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
                             caesar::mode mode, unsigned int **stats,
                             size_t statsSz) {
  std::wifstream source(fsource);
  std::wofstream translated(ftranslated);
  const std::locale locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>);
  source.imbue(locale);
  translated.imbue(locale);
  size_t offsetsIdx = 0;
  wchar_t symbol;
  while (source.get(symbol)) {
    const int sign = (mode == caesar::mode::encode) ? 1 : -1;
    const wchar_t translatedSymbol =
        static_cast<wchar_t>((static_cast<int>(symbol) +
                              sign * static_cast<int>(offsets[offsetsIdx])) %
                             WCHAR_MAX);
    translated.put(translatedSymbol);
    offsetsIdx = ++offsetsIdx % offsetsSz;
  }
  source.close();
  translated.close();
}
