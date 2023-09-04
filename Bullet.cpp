#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Room.hpp"

Bullet::Bullet(WINDOW *win, int x, int y, char c, int d){
    curwin = win;
    yLoc = y;
    xLoc = x;
    character = c;
    damage = d;
    getmaxyx(curwin, yMax, xMax);
}

// problema con vedere come interagire con enemy
//if tasto sparo is premuto
void Bullet::Fire(int yLoc, int xLoc){
    for(int i=0; i<xMax; i++){
        if(xLoc+1 != xMax){
            mvwaddch(curwin, yLoc, xLoc, ' ');
            mvwaddch(curwin, yLoc, xLoc+1, '-');
            xLoc = xLoc+1;
            wrefresh(curwin);
            napms(50);
        }
        else if(xLoc+1 == Enemy::getX() && yLoc == Enemy::getY()){
        	Enemy::takeDamage(damage);
            mvwaddch(curwin, yLoc, xLoc, ' ');
	    }
        else
            mvwaddch(curwin, yLoc, xLoc, ' ');
    }
}

int Bullet::getX(){
    return xLoc;
}

int Bullet::getY(){
    return yLoc;
}
