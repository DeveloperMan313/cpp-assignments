#include "file.h"

char *get_fname(std::istream &istream) {
  std::cout << "Введите имя файла" << std::endl;
  vector<char> fname;
  istream >> fname;
  char *fname_c = fname.array;
  fname.array = nullptr;
  return fname_c;
}

void read_file(vector<Word *> &dict, char *fname) {
  clear_dict(dict);
  std::ifstream file(fname, std::ios::in | std::ios::binary);
  if (!file) {
    std::cout << "Не удалось открыть файл" << std::endl;
    file.close();
    return;
  }
  vector<char> eng, rus;
  while (true) {
    file >> eng >> rus;
    if (eng[0] == '\0' || rus[0] == '\0') {
      break;
    }
    dict.push(new Word{eng.array, rus.array});
    eng.array = nullptr;
    rus.array = nullptr;
  }
  file.close();
  sort_dict(dict);
}

void write_file(const vector<Word *> &dict, char *fname) {
  std::ofstream file(fname, std::ios::out | std::ios::binary);
  if (!file) {
    std::cout << "Не удалось открыть файл" << std::endl;
    file.close();
    delete[] fname;
    return;
  }
  file.clear();
  for (size_t i = 0; i < dict.size; ++i) {
    file << dict[i]->eng << ' ' << dict[i]->rus << std::endl;
  }
  file.close();
}
