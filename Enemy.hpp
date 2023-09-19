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
        int takenDamage;

public:
    Enemy(int x, int y, char c, WINDOW *win);

    int getX();

    int getY();

    int getHealth();

    int getDamage();

    void takeDamage(int takenDamage);

    void increasehealth(int plush);

    void increasedamage(int plusd);

    void movement();
     
    int getDroppedScore(char enemyType);

    int getDroppedCoins(char enemyType);
        
    void display_enemy();

};

class Easyenemy: public Enemy {
protected:
int health;
int damage;

public:
Easyenemy(int x, int y, char c, WINDOW *win);
};


class Mediumenemy: public Enemy {
protected:
int health;
int damage;

public:
Mediumenemy(int x, int y, char c, WINDOW *win);
};


class Hardenemy: public Enemy {
protected:
int health;
int damage;

public:
Hardenemy(int x, int y, char c, WINDOW *win);
};

#endif
