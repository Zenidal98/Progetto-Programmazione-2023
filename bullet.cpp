#include "bullet.h"

Bullet::Bullet(WINDOW *win, int x, int y, char c='-', int d=1){
    curwin = win;
    yLoc = y;
    xLoc = x;
    character = c;
    damage = d;
    getmaxyx(curwin, yMax, xMax);
}


//if tasto sparo is premuto
void Bullet::Fire(int yLoc, int xLoc){
    for(int i=0; i<xMax; i++){
        if(xLoc+1 != xMax){
            /*if(xLoc+1 == Enemy.xLoc){
                Enemy.die()?;
                mvwaddch(curwin, yLoc, xLoc, ' ');
                break;
            }*/
            mvwaddch(curwin, yLoc, xLoc, ' ');
            mvwaddch(curwin, yLoc, xLoc+1, '-');
            xLoc = xLoc+1;
            wrefresh(curwin);
            napms(50);
        }
        else{
        	mvwaddch(curwin, yLoc, xLoc, ' ');
	}
    }
}
