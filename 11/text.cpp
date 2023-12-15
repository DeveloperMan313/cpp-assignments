#include "text.h"

void enterText(vector<char *> &words) {
  vector<char> text;
  for (char ch = '\0'; ch != '\r'; ch = _getch()) {
    if (ch >= 'a' && ch <= 'z' || ch == ' ') {
      text.push(ch);
      _putch(ch);
    } else if (ch == 8 && text.size > 0) {
      --text.size;
      _putch('\b');
      _putch(' ');
      _putch('\b');
    }
  }
  vector<char> word;
  for (size_t i = 0; i <= text.size; ++i) {
    if (text[i] == ' ' || i == text.size) {
      if (word.size == 0) {
        continue;
      }
      word.push('\0');
      words.push(word.array);
      word.array = nullptr;
      word.clear();
      continue;
    }
    word.push(text[i]);
  }
  _putch('\n');
}

void printWords(const vector<char *> &words) {
  bool printed = false;
  for (size_t i = 0; i < words.size; ++i) {
    if (std::strcmp(words[i], words[words.size - 1]) == 0) {
      continue;
    }
    if (printed) {
      _putch(' ');
    } else {
      printed = true;
    }
    size_t len = strlen(words[i]);
    for (size_t j = 0; j < len; ++j) {
      if (j == len - 1 || words[i][j] != words[i][len - 1]) {
        _putch(words[i][j]);
      }
    }
  }
}
