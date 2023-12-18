#include "dictionary.h"

int main(int argc, char *argv[]) {
  system("chcp 65001 > nul");
  bool isInteractive = false;
  if ((argc == 2) && strcmp(argv[1], "i") == 0) {
    isInteractive = true;
  }
  if (isInteractive) {
    interactive(std::cin, false);
  } else {
    demo();
  }
  return 0;
}
