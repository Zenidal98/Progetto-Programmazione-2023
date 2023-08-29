#pragma once
#include <ncurses.h>

class enemy {
protected:
        int x, y;
        int xMax, yMax;
        char c;
        int health;
        int damage;
        WINDOW *win;
        

public:
    enemy(int x, int y, char c, int health, int damage, WINDOW *win);

    int getX();

    int getY();

    int getHealth();

    int getDamage();

    void takeDamage(int damage);

    void increasehealth(int plush);

    void increasedamage(int plusd);

    void movement();
     
    void drop_gold();
     
    void drop_points();
        
    void display_enemy();

};

class easyenemy: public enemy {
protected:
int health=10;
int damage=3;

public:
easyenemy(int x, int y, char c, WINDOW *win)::enemy(x,y,c,win);  //dubbio sul come si strutturino le sottoclassi e i loro metodi im n .h e .cpp
};


class mediumenemy: public enemy {
protected:
int health=20;
int damage=6;

public:
mediumenemy(int x, int y, char c, WINDOW *win)::enemy(x,y,c,win);
};


class hardenemy: public enemy {
protected:
int health=30;
int damage=15;

public:
hardenemy(int x, int y, char c, WINDOW *win)::enemy(x,y,c,win);
};


