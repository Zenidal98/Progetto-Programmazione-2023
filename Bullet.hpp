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
	Enemy *enemyArray;
        Bullet(WINDOW *win, int x, int y, char c='-', int d=1, Enemy *enemies[]);
        void Fire(int xLoc, int yLoc);
        int getX();
        int getY();
};

#endif
