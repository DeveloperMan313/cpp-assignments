#include "dictionary.hpp"
#include "file.hpp"

int menu(std::istream &istream) {
  std::cout << "Выберите действие:\n"
               "1 - добавить слово\n"
               "2 - удалить слово\n"
               "3 - перевод с английского\n"
               "4 - перевод с русского\n"
               "5 - просмотреть словарь\n"
               "6 - загрузить из файла\n"
               "7 - сохранить в файл\n"
               "8 - выйти"
            << std::endl;
  int option = 0;
  if (!(istream >> option)) {
    istream.clear();
    istream.ignore();
  }
  return option;
}

void interactive(std::istream &istream, bool demo) {
  vector<Word *> dict;
  while (true) {
    char *fname;
    vector<char> eng, rus;
    int option = menu(istream);
    if (demo) {
      std::cout << option << std::endl;
    }
    switch (option) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
      if (dict_empty(dict)) {
        std::cout << std::endl;
        continue;
      }
      break;
    }
    switch (option) {
    case 1:
      std::cout << "Введите латиницей слово на английском и на русском"
                << std::endl;
      istream >> eng >> rus;
      if (demo) {
        std::cout << eng.array << ' ' << rus.array << std::endl;
      }
      add_word(dict, eng, rus);
      break;
    case 2:
      std::cout << "Введите слово на английском" << std::endl;
      istream >> eng;
      if (demo) {
        std::cout << eng.array << std::endl;
      }
      delete_word(dict, eng);
      break;
    case 3:
      std::cout << "Введите слово на английском" << std::endl;
      istream >> eng;
      if (demo) {
        std::cout << eng.array << std::endl;
      }
      translate_eng(dict, eng);
      break;
    case 4:
      std::cout << "Введите слово латиницей на русском" << std::endl;
      istream >> rus;
      if (demo) {
        std::cout << rus.array << std::endl;
      }
      translate_rus(dict, rus);
      break;
    case 5:
      print_dict(dict);
      break;
    case 6:
      fname = get_fname(istream);
      if (demo) {
        std::cout << fname << std::endl;
      }
      read_file(dict, fname);
      delete[] fname;
      break;
    case 7:
      fname = get_fname(istream);
      if (demo) {
        std::cout << fname << std::endl;
      }
      write_file(dict, fname);
      delete[] fname;
      break;
    case 8:
      goto end;
      break;
    default:
      std::cout << "Надо вводить число от 1 до 8" << std::endl;
      break;
    }
    std::cout << std::endl;
  }
end:
  clear_dict(dict);
}

void demo() {
  std::cout << "Демонстрационный режим:" << std::endl;
  char input[] = "5 1 dog sobaka 5 1 cat kot 5 1 cow korova 5 3 cat "
                 "4 korova 7 demo.txt 2 cat 5 6 demo.txt 5 8";
  auto stream = std::istringstream(input);
  interactive(stream, true);
};

void add_word(vector<Word *> &dict, vector<char> &eng, vector<char> &rus) {
  Word *newEntry = new Word{eng.array, rus.array};
  dict.push(newEntry);
  if (dict.size > 1 && strcmp(eng.array, dict[dict.size - 2]->eng) == -1) {
    size_t wordIdx = dict.size - 1;
    for (size_t i = 0; i < dict.size - 1; ++i) {
      if (strcmp(eng.array, dict[i]->eng) == -1) {
        wordIdx = i;
        break;
      }
    }
    for (size_t i = dict.size - 1; i > wordIdx; --i) {
      dict[i] = dict[i - 1];
    }
    dict[wordIdx] = newEntry;
  }
  eng.array = nullptr;
  rus.array = nullptr;
}

void delete_word(vector<Word *> &dict, const vector<char> &eng) {
  size_t wordIdx = find_eng(dict, eng);
  if (wordIdx == -1) {
    std::cout << "Слово не найдено" << std::endl;
    return;
  }
  delete_dict_entry(dict, wordIdx);
  for (size_t i = wordIdx; i < dict.size - 1; ++i) {
    dict[i] = dict[i + 1];
  }
  --dict.size;
}

void translate_eng(const vector<Word *> &dict, const vector<char> &eng) {
  size_t wordIdx = find_eng(dict, eng);
  if (wordIdx == -1) {
    std::cout << "Слово не найдено" << std::endl;
    return;
  }
  std::cout << "Перевод: " << dict[wordIdx]->rus << std::endl;
}

void translate_rus(const vector<Word *> &dict, const vector<char> &rus) {
  for (size_t i = 0; i < dict.size; ++i) {
    if (strcmp(dict[i]->rus, rus.array) == 0) {
      std::cout << "Перевод: " << dict[i]->eng << std::endl;
      return;
    }
  }
  std::cout << "Слово не найдено" << std::endl;
}

void print_dict(const vector<Word *> &dict) {
  std::cout << "Словарь:" << std::endl;
  for (size_t i = 0; i < dict.size; ++i) {
    std::cout << dict[i]->eng << " - " << dict[i]->rus << std::endl;
  }
}

bool dict_empty(const vector<Word *> &dict) {
  if (dict.size == 0) {
    std::cout << "Словарь пуст" << std::endl;
    return true;
  }
  return false;
}

void sort_dict(vector<Word *> &dict) {
  for (int i = 0; i < dict.size; ++i) {
    int swapIdx = i;
    for (int j = i + 1; j < dict.size; ++j) {
      if (strcmp(dict[swapIdx]->eng, dict[j]->eng) == 1) {
        swapIdx = j;
      }
    }
    if (i != swapIdx) {
      Word *dPtr = dict[i];
      dict[i] = dict[swapIdx];
      dict[swapIdx] = dPtr;
    }
  }
}

inline void delete_dict_entry(vector<Word *> &dict, size_t i) {
  delete[] dict[i]->eng;
  delete[] dict[i]->rus;
  delete dict[i];
}

void clear_dict(vector<Word *> &dict) {
  for (size_t i = 0; i < dict.size; ++i) {
    delete_dict_entry(dict, i);
  }
  dict.clear();
}

size_t find_eng(const vector<Word *> &dict, const vector<char> &eng) {
  size_t l = 0, r = dict.size - 1;
  while (l <= r) {
    size_t m = l + (r - l) / 2;
    int cmp = strcmp(dict[m]->eng, eng.array);
    if (cmp == 0) {
      return m;
    }
    if (cmp == -1) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

int strcmp(const char *s1, const char *s2) {
  for (size_t i = 0;; ++i) {
    if (s1[i] == '\0' || s2[i] == '\0') {
      if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
      }
      if (s1[i] == '\0') {
        return -1;
      } else {
        return 1;
      }
    }
    if (s1[i] < s2[i]) {
      return -1;
    } else if (s1[i] > s2[i]) {
      return 1;
    }
  }
}

namespace std {
istream &operator>>(istream &stream, vector<char> &str) {
  str.clear();
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
