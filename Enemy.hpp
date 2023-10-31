#ifndef ENEMY_HPP
#define ENEMY_HPP

#pragma once
#include <ncurses.h>

class Enemy {
protected:
        int x, y;
        int xMax, yMax;
        char c;
        WINDOW *win;
        char enemyType;
//        int health;
        int damage;
        int scoreDropped;
        int coinsDropped;

public:
    Enemy(int x, int y, char c, WINDOW *win, char enemyType);

    int health;

    int getX();

    int getY();

    int getHealth();

    int getDamage();

    void movement();
     
    int getDroppedScore();

    int getDroppedCoins();
        
    void display_enemy();

};
#endif
