#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Room.hpp"

Bullet::Bullet(WINDOW *win, int x, int y, char c, int d, Enemy *enemies[]){
    curwin = win;
    yLoc = y;
    xLoc = x;
    character = c;
    damage = d;
    getmaxyx(curwin, yMax, xMax);
    enemyArray = enemies;
}

// problema con vedere come interagire con enemy
//if tasto sparo is premuto
void Bullet::Fire(int yLoc, int xLoc, ){
    for(int i=0; i<xMax; i++){
        if(xLoc+1 != xMax){
	    for(int j=0; j<enemySize; j++){
		//enemy hit
		if(xLoc+1 == enemy[j].getX() && yLoc+1 == enemy[j].getY())
		{
			enemy[j].takeDamage(damage);
			return;
		}
	    }
            mvwaddch(curwin, yLoc, xLoc, ' ');
            mvwaddch(curwin, yLoc, xLoc+1, '-');
            xLoc = xLoc+1;
            wrefresh(curwin);
            napms(50);
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
