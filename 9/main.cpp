#include "dictionary.h"

int main(int argc, char *argv[]) {
  system("chcp 65001 > nul");
  bool isInteractive = true;
  if ((argc == 2) && strcmp(argv[1], "i") == 0) {
    isInteractive = true;
  }
  if (isInteractive) {
    interactive();
  } else {
    demo();
  }
  return 0;
}
