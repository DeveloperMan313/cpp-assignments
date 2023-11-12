#include "caesar.h"
#include "table.h"

int main() {
  system("chcp 65001 > nul");
  caesar::translateCaesar("source.txt", "key.txt", "encoded.txt",
                          caesar::mode::encode);
  caesar::translateCaesar("encoded.txt", "key.txt", "decoded.txt",
                          caesar::mode::decode);
  unsigned int values[26][26];
  for (size_t i = 0; i < 26; ++i) {
    for (size_t j = 0; j < 26; ++j) {
      values[i][j] = rand() % 100;
    }
  }
  printTable(values, 4);
  return 0;
}
