#include <iostream>

using namespace std;

int main() {
  // русификация
  system("chcp 65001 > nul");
  // ввод данных
  int h, m;
  cin >> h >> m;
  // проверка на правильность данных
  if (h < 0 || h > 23 || m < 0 || m > 59) {
    cout << "введены недопустимые данные" << endl;
    system("pause");
    return 0;
  }
  // проверка на полночь/полдень
  if (m == 0 && (h == 0 || h == 12)) {
    if (h == 0)
      cout << "полночь";
    else
      cout << "полдень";
    cout << endl;
    system("pause");
    return 0;
  }
  // вывод числа часов и нужного склонения слова "час"
  int h12 = (h > 12) ? h - 12 : h;
  cout << h12 << " ";
  switch (h12) {
  case 1:
    cout << "час";
    break;
  case 2:
  case 3:
  case 4:
    cout << "часа";
    break;
  default:
    cout << "часов";
  }
  cout << " ";
  // выводить число минут, когда оно не 0
  if (m > 0) {
    // вывод числа минут и нужного склонения слова "минута"
    cout << m << " ";
    // вывод с окончаниями а/ы только для чисел, оканчивающихся на 1, 2, 3 и 4,
    // кроме 11, 12, 13 и 14
    int m0 = (m > 19) ? m % 10 : m;
    switch (m0) {
    case 1:
      cout << "минута";
      break;
    case 2:
    case 3:
    case 4:
      cout << "минуты";
      break;
    default:
      cout << "минут";
    }
    cout << " ";
  }
  // вывод времени суток
  if (h < 5)
    cout << "ночи";
  else if (h < 12)
    cout << "утра";
  else if (h < 18)
    cout << "дня";
  else
    cout << "вечера";
  // в случае вывода без числа минут
  if (m == 0)
    cout << " ровно";
  cout << endl;
  system("pause");
  return 0;
}
