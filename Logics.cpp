#include <ncurses.h>
// includere tutto quello che serve
#include "Logics.h"
//srand
#include <cstdlib>
#include <ctime>

Logics::Logics() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    playwin = newwin(20, 50, (yMax / 2) - 10, 10);
    
    e = new enemy(playwin, 1, 1, 'e', 100, 5, true);
    // Player      (window, x, y, char,hp, sc,jf,jh,dst,pow, ...)
    p = new Player(playwin, 1, 1, 'P', 100, 0, 1, 20, 1, 1, 1, 0, 0);
    srand(time(NULL));
    char letters[] = "dcrg";
    char x = letters[rand() % 4];
    el = new elements(playwin, rand()%yMax+1, rand()%xMax+1, x);
    // el = new elements(playwin, 48, 18, x);
}

void Logics::start(){
    // mappa
    box(playwin, 0, 0);
    wrefresh(playwin);
    
    nodelay(playwin, true);
    //ciclo di movimento e cose
    while(true){
        e->movement();
        p->getmv();
        p->display();
        el->display();
        check_upgrades();
        check_damage();
    
        wrefresh(playwin);
    }
}

void Logics::check_upgrades(){
    if((p->getX() == el->getX()) && (p->getY() == el->getY())){
        el->touch();
        // non funziona, come cancellare element?
        // mvwaddch(playwin, el->getY(), el->getX(), ' ');
    }
}

void Logics::check_damage(){
    if((p->getX() == e->getX()) && (p->getY() == e->getY())){
        p->minusHealth(e->getDamage());
    }
}