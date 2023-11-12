#include "calculus.h"
#include "table.h"

using namespace std;

int main() {
  system("chcp 1251 > nul");
  double a, b;
  cout << "Введите значение a: ";
  cin >> a;
  cout << "Введите значение b: ";
  cin >> b;
  cout << endl;
  CalculatePrintTables(IntRect, "Метод прямоугольников", a, b);
  CalculatePrintTables(IntTrap, "Метод трапеций", a, b);
  system("pause");
  return 0;
}
