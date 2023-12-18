#include "matrix.hpp"

int main() {
  system("chcp 65001 > nul");
  while (true) {
    std::cout << "Выберите действие:\n"
                 "1 - найти обратную матрицу\n"
                 "2 - найти решение СЛАУ\n"
                 "3 - выйти"
              << std::endl;
    int option = 0;
    if (!(std::cin >> option)) {
      std::cin.clear();
      std::cin.ignore();
    }
    switch (option) {
    case 1:
      UIInverse();
      break;
    case 2:
      UISLE();
      break;
    case 3:
      goto end;
      break;
    default:
      std::cout << "Надо вводить число от 1 до 3" << std::endl;
      break;
    }
    std::cout << std::endl;
  }
end:
  return 0;
}
