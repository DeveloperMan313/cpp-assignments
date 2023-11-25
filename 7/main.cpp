#include "caesar.h"
#include "table.h"

int main() {
  std::system("chcp 1251 > nul");
  unsigned int **stats = new unsigned int *[table::CHAR_CNT];
  for (size_t i = 0; i < table::CHAR_CNT; ++i) {
    stats[i] = new unsigned int[table::CHAR_CNT]{};
  }
  size_t offsetsSz;
  const char *offsets = caesar::calculateCaesarOffsets("key.txt", offsetsSz);
  caesar::translateCaesar("source.txt", offsets, offsetsSz, "encoded.txt",
                          caesar::mode::encode, stats);
  table::printTable(stats);
  caesar::translateCaesar("encoded.txt", offsets, offsetsSz, "decoded.txt",
                          caesar::mode::decode, stats);
  for (size_t i = 0; i < table::CHAR_CNT; ++i) {
    delete[] stats[i];
  }
  delete[] stats;
  delete[] offsets;
  return 0;
}
