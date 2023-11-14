#include "caesar.h"

int main() {
  const size_t alphabetSz = 26;
  system("chcp 65001 > nul");
  unsigned int **stats = new unsigned int *[alphabetSz];
  for (size_t i = 0; i < alphabetSz; ++i) {
    stats[i] = new unsigned int[alphabetSz]{};
  }
  caesar::translateCaesar("source.txt", "key.txt", "encoded.txt",
                          caesar::mode::encode, stats, alphabetSz);
  // printTable(stats, 4);
  caesar::translateCaesar("encoded.txt", "key.txt", "decoded.txt",
                          caesar::mode::decode, stats, alphabetSz);
  for (size_t i = 0; i < alphabetSz; ++i) {
    delete[] stats[i];
  }
  delete[] stats;
  return 0;
}
