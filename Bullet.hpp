#ifndef BULLET_HPP
#define BULLET_HPP

#pragma once
#include <ncurses.h>
#include "Enemy.hpp"

class Bullet{
    private:
        WINDOW *curwin;
        int xLoc, yLoc, xMax, yMax;
        int damage;
        char character; 
	int size;
        
    public:
	Enemy  *enemy[];
        Bullet(WINDOW *win, int x, int y, char c='-', int d=1, Enemy enemies[]={}, int enemySize=6);
        void Fire(int xLoc, int yLoc);
        int getX();
        int getY();
};

#endif
