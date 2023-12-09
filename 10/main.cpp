#include "text.h"

int main() {
  vector<char *> words;
  enterText(words);
  printWords(words);
  for (size_t i = 0; i < words.size; ++i) {
    delete[] words[i];
  }
  return 0;
}
