#include "caesar.h"

int main() {
  const size_t alphabetSz = 26;
  system("chcp 65001 > nul");
  unsigned int **stats = new unsigned int *[alphabetSz];
  for (size_t i = 0; i < alphabetSz; ++i) {
    stats[i] = new unsigned int[alphabetSz]{};
  }
  size_t offsetsSz;
  const wchar_t *offsets = caesar::calculateCaesarOffsets("key.txt", offsetsSz);
  caesar::translateCaesar("source.txt", offsets, offsetsSz, "encoded.txt",
                          caesar::mode::encode, stats, alphabetSz);
  // printTable(stats, 4);
  caesar::translateCaesar("encoded.txt", offsets, offsetsSz, "decoded.txt",
                          caesar::mode::decode, stats, alphabetSz);
  for (size_t i = 0; i < alphabetSz; ++i) {
    delete[] stats[i];
  }
  delete[] stats;
  delete[] offsets;
  return 0;
}
