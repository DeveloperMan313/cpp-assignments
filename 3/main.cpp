#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int task1() {
  int n, m, sum = 0, cnt = 0;
  cout << "Введите количество натуральных чисел n и число m" << endl;
  cin >> n >> m;
  if (cin.fail() || n < 1 || m < 2 || m == 5 || m >= n)
    return 1; // проверка данных на ошибку
  // начать с 5 прыжки по 5 это все натуральные числа, кратные 5
  // продолжать цикл, пока cnt не станет равно n
  for (int i = 5; cnt < n; i += 5)
    if (i % m != 0) { // прибавить к сумме, если не кратно m
      cout << i << " "; // вывод слагаемого
      sum += i;
      ++cnt;
    }
  cout << endl << sum << endl;
  return 0;
}

int task2() {
  double a, x, prod = 1.0;
  cout << "Введите число a" << endl;
  cin >> a;
  if (cin.fail()) // проверка данных на ошибку
    return 1;
  // расчет одного из произведений в зависимости от значения a
  if (a >= 0) {
    for (int i = 2; i <= 8; i += 2) {
      x = i * i;
      prod *= x;
      cout << x << " "; // вывод множителя
    }
    prod -= a;
  } else
    for (int i = 3; i <= 9; i += 3) {
      x = i - 2;
      prod *= x;
      cout << x << " "; // вывод множителя
    }
  cout << endl << setprecision(4) << fixed << prod << endl;
  return 0;
}

int task3() {
  int w = 14;
  double h = 0.2, eps = 0.000001;
  // вывод заголовка таблицы с форматированием
  cout << setw(w) << "x" << setw(w) << "Y(x)" << setw(w) << "S(x)" << setw(w)
       << "N" << endl;
  for (double x = 0; x <= 1; x += h) { // для каждого значения x
    double x2 = x * x, s = 1, term = 1, y = cos(x);
    int n;
    // суммирование ряда Тейлора до точности eps
    for (n = 2; abs(term) > eps; ++n) {
      term *= -x2 / (2 * n - 3) / (2 * n - 2); // расчетное соотношение
      s += term;
    }
    // вывод строки таблицы с форматированием
    cout << defaultfloat << setw(w) << x << fixed << setprecision(w - 5)
         << setw(w) << y << setw(w) << s << setw(w) << n << endl;
  }
  return 0;
}

double task4a(int n) {
  // при n = n0
  double y = 0.5 / n;
  for (; n > 0; n--) // расчет y
    y = 1 / (2 * n + y);
  return y;
}

int task4() {
  int n;
  cout << "Введите натуральное число n" << endl;
  cin >> n;
  if (cin.fail() || n < 1) // проверка данных на ошибку
    return 1;
  // вывод промежуточных результатов
  if (n > 3)
    cout << "n = 3: " << setprecision(9) << task4a(3) << endl;
  if (n > 5)
    cout << "n = 5: " << setprecision(9) << task4a(5) << endl;
  if (n > 10)
    cout << "n = 10: " << setprecision(9) << task4a(10) << endl;
  cout << setprecision(9) << task4a(n) << endl;
  return 0;
}

int main() {
  system("chcp 65001 > nul"); // русификация
  char ans;
  do {
    int task;
    do { // должен быть введен номер задачи
      cout << defaultfloat << "Введите номер задачи (1-4)" << endl;
      cin >> task;
      cin.clear();
      cin.ignore();
    } while (cin.fail() || task < 1 || task > 4);
    // запуск функции выбранной задачи
    int code;
    switch (task) {
    case 1:
      code = task1();
      break;
    case 2:
      code = task2();
      break;
    case 3:
      code = task3();
      break;
    case 4:
      code = task4();
    }
    if (code != 0) { // проверка на ошибку в функции задачи
      cout << "Введены неверные данные" << endl;
      cin.clear();
      cin.ignore();
    }
    do { // должен быть введен либо символ 'y', либо символ 'n'
      cout << "Продолжить работу? (y/n)" << endl;
      cin >> ans;
      cin.clear();
      cin.ignore();
    } while (cin.fail() || !(ans == 'y' || ans == 'n'));
  } while (ans == 'y'); // продолжать работу, пока пользователь отвечает 'y'
  return 0;
}
