#include "calculus.h"
#include "table.h"

using namespace std;

int main() {
  system("chcp 1251 > nul");
  double a, b;
  cout << "������� �������� a: ";
  cin >> a;
  cout << "������� �������� b: ";
  cin >> b;
  cout << endl;
  CalculatePrintTables(IntRect, "����� ���������������", a, b);
  CalculatePrintTables(IntTrap, "����� ��������", a, b);
  system("pause");
  return 0;
}
