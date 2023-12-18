#include "rootfinder.hpp"

using namespace std;

int main() {
  system("chcp 65001 > nul");
  int w = 16, maxIter = 100000;
  runTests(w, 1e-6, maxIter);
  runTests(w, 1e-8, maxIter);
  return 0;
}
