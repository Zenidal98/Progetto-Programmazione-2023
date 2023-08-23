#pragma once
#include <ncurses.h>

class Gravity{
    private:
        int xLoc, yLoc;
        int xMax, yMax;
        char character;
        WINDOW *curwin;
    public:
        Gravity(WINDOW *win, int x, int y, char c);
        void fall();
};
