#include "sort.h"

using namespace std;

int main() {
  system("chcp 1251 > nul");
  int w = 16, mx = 10, l = 5;
  dynArray dArr(l);
  fillRand(dArr, mx);
  methodTable(dArr, false, w);
  for (int i = 0; i < l; ++i) {
    dArr[i] = i;
  }
  methodTable(dArr, true, w);
  mx = 1000;
  sizeTable(0, false, w, mx);
  sizeTable(1, true, w, mx);
  system("pause");
  return 0;
}
