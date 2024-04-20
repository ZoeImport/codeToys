
#include "Tetris.h"
#include <curses.h>

WINDOW *initWin() {
  initscr();
  cbreak();
  noecho();
  auto *mainMenu = newwin(Y_ch_count, X_ch_count, 0, 0);
  return mainMenu;
}

void initBound() {
  std::string upBoundStr;
  std::string downBoundStr;
  for (auto cur_x = 0; cur_x <= X_ch_count; ++cur_x) {
    upBoundStr += X_bound_ch;
    downBoundStr += X_bound_ch;
  }
  for (auto cur_y = 1; cur_y <= Y_ch_count; ++cur_y) {
    mvaddch(cur_y, 0, Y_bound_ch);
    mvaddch(cur_y, X_ch_count, Y_bound_ch);
  }
  mvaddstr(0, 0, upBoundStr.c_str());
  mvaddstr(Y_ch_count, 0, downBoundStr.c_str());
}

void initMenu() {
  for (auto col = 0; col < 10; ++col) {
    mvaddstr(3 + col, 15, Header[col]);
    mvaddstr(10 + col, 15, options[col]);
  }
}

std::string inputStr() {
  char buf[1024];
  scanw("%s", buf);
  return std::string(buf);
}

void outstr(std::string output) { printw("%s", output.c_str()); }

void initGame() {
  for (auto col = 1; col < 80; ++col) {
    mvaddstr(col, 60, gameUI[col]);
  }
}