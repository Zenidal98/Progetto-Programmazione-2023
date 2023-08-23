#include "logics.hpp"
#include <ncurses.h>

int main(){
    initscr();
    noecho();
    refresh();

    Logics l;
    l.start();

    endwin();
    return 0;
}
