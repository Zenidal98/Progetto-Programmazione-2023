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
    statwin = newwin(10, 20, (yMax / 2) - 10, 60);

    //            (WINDOW, x, y, ch,  hp, dam, hard);
    e = new enemy(playwin, 1, 1, 'e', 100, 50, true);
    // Player      (window, x, y, char,hp, sc,jf,jh,dst,pow, ...)
    p = new Player(playwin, 1, 1, 'P', 100, 0, 1, 20, 1, 1, 1, 0, 0);
    srand(time(NULL));
    char letters[] = "dcrg";
    char x = letters[rand() % 4];
    // el = new elements(playwin, rand()%yMax+1, rand()%xMax+1, x);
    el = new elements(playwin, 45, 12, x);
}

void Logics::start(){
    // mappa
    box(playwin, 0, 0);
    wrefresh(playwin);

    // box statistiche
    box(statwin, 0, 0);
    wprintw(statwin, "Health: %d", p->health);
    wrefresh(statwin);
    
    nodelay(playwin, true);
    //ciclo di movimento e cose
    while(true && end == false){
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
        // wprintw(playwin, "Damage!!");
        p->minusHealth(e->getDamage());

        wprintw(statwin, "\n%d Damage taken!", e->getDamage());
        wrefresh(statwin);
        wprintw(statwin, "\nHealth: %d", p->health);
        wrefresh(statwin);

        if(p->health <= 0)
            gameOver();
    }
}

void Logics::gameOver(){
    mvaddch(p->getY(), p->getX(), ' ');
    wrefresh(playwin);
    end = true;
}