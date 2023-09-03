#ifndef BULLET_HPP
#define BULLET_HPP

#pragma once
#include <ncurses.h>

class Bullet{
    private:
        WINDOW *curwin;
        int xLoc, yLoc, xMax, yMax;
        int damage;
        char character; 
        
    public:
        Bullet(Room *win, int x, int y, char c='-', int d=1);
        void Fire(int xLoc, int yLoc);
        int getX();
        int getY();
};

#endif
