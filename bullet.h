#pragma once
#include <ncurses.h>

class Bullet{
    private:
        int xLoc, yLoc, xMax, yMax;
        int damage;
        
    public:
        Bullet(WINDOW *win, int x, int y, char c='-', int d=1);
        void Fire();
};
