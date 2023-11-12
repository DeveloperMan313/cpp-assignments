#include "caesar.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  system("chcp 65001 > nul");
  fstream file;
  file.open("test.txt");
  if (!file) {
    cerr << "Ошибка при открытии файла!\n";
    exit(1);
  }
  while (file.peek() != EOF) {
    const int line_sz = 512;
    char line[line_sz];
    file.getline(line, line_sz);
    cout << line << endl;
  }
  return 0;
}
