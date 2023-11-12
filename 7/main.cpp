#include "caesar.h"

int main() {
  system("chcp 65001 > nul");
  caesar::translateCaesar("source.txt", "key.txt", "encoded.txt",
                          caesar::mode::encode);
  caesar::translateCaesar("encoded.txt", "key.txt", "decoded.txt",
                          caesar::mode::decode);
  return 0;
}
