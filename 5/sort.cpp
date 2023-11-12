#include "sort.h"

using namespace std;

dynArray::dynArray(int length)
    : length(length), arr(new int[length]), comps(0), swaps(0) {}

int &dynArray::operator[](int i) { return this->arr[i]; }

dynArray::~dynArray() { delete[] arr; }

void copyArray(dynArray &src, dynArray &dst) {
  const int minLength = (src.length < dst.length) ? src.length : dst.length;
  for (int i = 0; i < minLength; ++i) {
    dst[i] = src[i];
  }
}

void fillRand(dynArray &dArr, int mx) {
  srand(0);
  for (int i = 0; i < dArr.length; ++i) {
    dArr[i] = rand() % mx;
  }
}

void printArray(dynArray &dArr) {
  for (int i = 0; i < dArr.length; ++i) {
    cout << dArr[i];
    if (i < dArr.length - 1)
      cout << ' ';
  }
}

void comparisonSort(dynArray &dArr, bool reversed) {
  const int sign = 1 - reversed * 2;
  dArr.comps = 0, dArr.swaps = 0;
  for (int i = 0; i < dArr.length; ++i) {
    int swapIdx = i;
    for (int j = i + 1; j < dArr.length; ++j) {
      ++dArr.comps;
      if (dArr[swapIdx] * sign > dArr[j] * sign) {
        swapIdx = j;
      }
    }
    if (i != swapIdx) {
      swap(dArr[i], dArr[swapIdx]);
      ++dArr.swaps;
    }
  }
}

void bubbleSort(dynArray &dArr, bool reversed) {
  const int sign = 1 - reversed * 2;
  dArr.comps = 0, dArr.swaps = 0;
  bool isSorted = false;
  for (int i = 0; i < dArr.length - 1 && !isSorted; ++i) {
    isSorted = true;
    for (int j = 0; j < dArr.length - 1 - i; ++j) {
      ++dArr.comps;
      if (dArr[j] * sign > dArr[j + 1] * sign) {
        isSorted = false;
        swap(dArr[j], dArr[j + 1]);
        ++dArr.swaps;
      }
    }
  }
}

void printRow(const char **row, int length, int w) {
  for (int i = 0; i < length; ++i) {
    if (i < length - 1) {
      cout << left << setw(w);
    }
    cout << row[i];
  }
  cout << endl;
}

void methodTable(dynArray &dArr, bool reversed, int w) {
  dynArray dArrInitial(dArr.length);
  copyArray(dArr, dArrInitial);
  const char *header[] = {"Метод", "Результат", "Сравнений", "Перестановок"};
  const char *order[] = {"возрастанию", "убыванию"};
  cout << "Количество элементов: " << dArr.length << ". Заданный массив: ";
  printArray(dArr);
  cout << ". Сортировка по " << order[reversed] << endl;
  printRow(header, 4, w);
  const char *methods[] = {"сравнений (n)", "сравнений (o)", "пузырек (n)",
                           "пузырек (o)"};
  for (int i = 0; i < 4; ++i) {
    if (i == 2) {
      copyArray(dArrInitial, dArr);
    }
    if (i < 2) {
      comparisonSort(dArr, reversed);
    } else {
      bubbleSort(dArr, reversed);
    }
    cout << left << setw(w) << methods[i];
    printArray(dArr);
    cout << "       " << setw(w) << dArr.comps << dArr.swaps << endl;
  }
  cout << endl;
}

void sizeTable(int method, bool reversed, int w, int mx) {
  const char *header[] = {"N", "Сравнений", "Перестановок"};
  const char *methods[] = {"сравнений (n)", "пузырек (n)"};
  const char *order[] = {"возрастанию", "убыванию"};
  cout << "Метод: " << methods[method] << ". Сортировка по " << order[reversed]
       << endl;
  printRow(header, 3, w);
  int length = 5;
  for (int i = 0; i < 3; ++i) {
    dynArray dArr(length);
    fillRand(dArr, mx);
    if (method == 0) {
      comparisonSort(dArr, reversed);
    } else {
      bubbleSort(dArr, reversed);
    }
    cout << left << setw(w) << length << setw(w) << dArr.comps << dArr.swaps
         << endl;
    length *= 10;
  }
  cout << endl;
}
