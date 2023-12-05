#include "dictionary.h"
#include <cstring>

int menu() {
  std::cin.clear();
  std::cout << "Выберите действие:\n"
               "1 - добавить слово\n"
               "5 - вывести словарь в консоль\n"
               "6 - выйти"
            << std::endl;
  int option;
  std::cin >> option;
  return option;
}

void add_w(vector<Dictionary *> &dict) {
  std::cout << "Введите латиницей слово на английском и на русском"
            << std::endl;
  vector<char> eng, rus;
  std::cin >> eng >> rus;
  dict.push(new Dictionary{eng.array, rus.array});
  if (dict.size > 1 && std::strcmp(dict[dict.size - 2]->eng, eng.array) == 1) {
    comparisonSort(dict);
  }
  eng.array = nullptr;
  rus.array = nullptr;
}

void print_dict(const vector<Dictionary *> &dict) {
  std::cout << "Сохраненные слова:" << std::endl;
  for (size_t i = 0; i < dict.size; ++i) {
    std::cout << dict[i]->eng << ' ' << dict[i]->rus << std::endl;
  }
}

void interactive() {
  vector<Dictionary *> dict;
  while (true) {
    switch (menu()) {
    case 1:
      add_w(dict);
      break;
    case 2:
    case 3:
    case 4:
      break;
    case 5:
      print_dict(dict);
      break;
    case 6:
      goto end;
      break;
    default:
      std::cout << "Надо вводить число от 1 до 6" << std::endl;
      break;
    }
    std::cout << std::endl;
  }
end:
  for (size_t i = 0; i < dict.size; ++i) {
    delete[] dict[i]->eng;
    delete[] dict[i]->rus;
    delete dict[i];
  }
}

void demo(){};

void comparisonSort(vector<Dictionary *> &dArr) {
  for (int i = 0; i < dArr.size; ++i) {
    int swapIdx = i;
    for (int j = i + 1; j < dArr.size; ++j) {
      if (std::strcmp(dArr[swapIdx]->eng, dArr[j]->eng) == 1) {
        swapIdx = j;
      }
    }
    if (i != swapIdx) {
      Dictionary *dPtr = dArr[i];
      dArr[i] = dArr[swapIdx];
      dArr[swapIdx] = dPtr;
    }
  }
}

namespace std {
istream &operator>>(istream &stream, vector<char> &str) {
  char c;
  size_t len = 0;
  while (stream.get(c)) {
    if (c == ' ' || c == '\n') {
      if (len) {
        break;
      }
      continue;
    }
    str.push(c);
    ++len;
  }
  str.push('\0');
  return stream;
}
} // namespace std
