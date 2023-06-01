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
    enemy(WINDOW *win, int x, int y, char c, int health, int damage);

    int getX();

    int getY();

    int getHealth();

    void takeDamage(int damage);

    void increasehealth(int plush);

    void increasedamage(int plusd);

    void movement();
     
    void drop_gold();
     
    void drop_points();
        
    void display_enemy();

};

