#include "Gravity.hpp"

Gravity::Gravity(WINDOW *win, int x, int y, char c){
    curwin = win;
    xLoc = x;
    yLoc = y;
    character = c;
    getmaxyx(curwin, yMax, xMax);
}

void Gravity::fall(){
    while(mvwinch(curwin, yLoc+1, xLoc) == ' '){
        //mvdown();
        mvwaddch(curwin, yLoc, xLoc, ' ');
        yLoc++;
        if(yLoc > yMax-2)
            yLoc = yMax-2;
        
        // display();
        mvwaddch(curwin, yLoc, xLoc, character);

        wrefresh(curwin);
        napms(150);
    }
}
