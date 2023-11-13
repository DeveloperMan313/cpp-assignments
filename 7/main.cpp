#include "caesar.h"
#include "table.h"

int main() {
  const size_t alphabetSz = 26;
  system("chcp 65001 > nul");
  unsigned int stats[alphabetSz][alphabetSz]{};
  caesar::translateCaesar("source.txt", "key.txt", "encoded.txt",
                          caesar::mode::encode, (unsigned int **)(stats),
                          alphabetSz);
  caesar::translateCaesar("encoded.txt", "key.txt", "decoded.txt",
                          caesar::mode::decode, (unsigned int **)(stats),
                          alphabetSz);
  // for (size_t i = 0; i < 26; ++i) {
  //   for (size_t j = 0; j < 26; ++j) {
  //     if ((i == 0 || i == 5 || i == 15) && j != 10)
  //       stats[i][j] = rand() % 100;
  //     else
  //       stats[i][j] = 0;
  //   }
  // }
  printTable(stats, 4);
  return 0;
}
