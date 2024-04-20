#include "Tetris.h"
#include <cstring>
#include <curses.h>
#include <cwchar>
#include <iostream>
#include <string>

int main() {

  auto *mainMenu = initWin();
  initBound();
  initMenu();

  refresh();

  while (1) {
    char input;
    std::cin >> input;
    if (input == 'n') {
      scr_dump("windows/mainPage.txt");
      
    }
  }
}