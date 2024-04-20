#ifndef _TETRIS_H_
#define _TETRIS_H_
#include <curses.h>
#include <string>

constexpr int X_ch_count = 80;
constexpr char X_bound_ch = '=';

constexpr int Y_ch_count = 20;
constexpr char Y_bound_ch = '|';

const char Header[10][50] = {
    "  ==+==  +====    #     #  #   ==+==   =====     ",
    "    #    #      ==+==    # #     #     #         ",
    "    #    +====    #      ##      #     +====     ",
    "    #    #        #      #       #         #     ",
    "    #    +====    +==    #     ==+==   ====+     ",
    "                                                 ",
    "                                                 ",

};
const char options[10][50]{
    "         +===========================+           ",
    "         #                           #           ",
    "         #      Play New Game  (n)   #           ",
    "         #                           #           ",
    "         #                           #           ",
    "         #        Exit Game    (q)   #           ",
    "         #                           #           ",
    "         ============================+           ",
};
const char gameUI[20][80]{
  "                                                               #               ",
  "                                                               #               ",
  "                                                               #               ",
  "                                                               #               ",
  "                                                               #               ",
};
WINDOW *initWin();
void initBound();
void initMenu();
std::string inputStr();
void outstr(std::string output);
void initGame();

#endif