#include <ncurses.h>
// includere tutto quello che serve
#include "Logics.h"
//srand
#include <cstdlib>
#include <ctime>
#include <cmath>

Logics::Logics() {
    bool isCollected = false;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    playwin = newwin(20, 50, (yMax / 2) - 10, 10);
    int statY = (yMax/2) - 10;
    int statX = 60;
    statwin = newwin(50, 30, statY, statX);

    //            (WINDOW, x, y, ch,  hp, dam, hard);
    e = new enemy(playwin, 1, 1, 'e', 100, 10, true);
    // Player      (window, x, y, char,hp, sc,jf,jh,dst,pow,bd,pd,coin, sp)
    p = new Player(playwin, 1, 1, 'P', 100, 0, 1, 4, 1, 1, 50, 0, 0, '\0');
    srand(time(NULL));
    char letters[] = "dcrg";
    char x = letters[rand() % 4];
    // el = new elements(playwin, rand()%yMax+1, rand()%xMax+1, x);
    el = new elements(playwin, 48, 18, x);


}

void Logics::start(){
    // mappa
    box(playwin, 0, 0);
    wrefresh(playwin);

    // box statistiche
    box(statwin, 0, 0);
    mvwprintw(statwin, 1, 1, "Health: %d", p->health);
    wrefresh(statwin);
    
    // mostra elements
    el->display();

    nodelay(playwin, true);

    //ciclo di movimento e cose
    while(true && end == false){
        if(e != NULL)
            e->movement();
        int key = p->getinput();
        if(key == 'd'){
            check_melee();
        }

        if(key == 's'){
            check_shoot();
        }

        p->display();

        check_upgrades();
        check_damage();

        wrefresh(playwin);
    }
}

void Logics::check_upgrades(){
    if(!isCollected && (p->getX() == el->getX()) && (p->getY() == el->getY())){
        wprintw(statwin, "\nPower up!!");
        wrefresh(statwin);
        el->touch();

        // Erase the element from the screen
        mvwaddch(playwin, el->getY(), el->getX(), ' ');
        wrefresh(playwin);

        // Erase pointer
        delete(el);
        el = nullptr;

        isCollected = true;
    }
}

void Logics::check_damage(){
    if((p->getX() == e->getX()) && (p->getY() == e->getY())){
        p->minusHealth(e->getDamage());

        wprintw(statwin, "\n%d Damage taken!", e->getDamage());
        wrefresh(statwin);
        wprintw(statwin, "\nHealth: %d", p->health);
        wrefresh(statwin);

        if(p->health <= 0)
            gameOver();

    }
}

void Logics::check_melee(){
    int distance = abs(p->getX()-e->getX());
    if(distance <= 2){
        e->takeDamage(p->getDamage());
        wprintw(statwin, "\nEnemy hit, Health: %d!", e->getHealth());
        wrefresh(statwin);
        // morte enemy 
        if(e->getHealth() <= 0){
            mvwaddch(playwin, e->getY(), e->getX(), ' ');
            wrefresh(playwin);

            // Erase pointer
            delete(e);
            e = nullptr;
        }
    }
    else
        return;
}

void Logics::gameOver(){
    mvaddch(p->getY(), p->getX(), ' ');
    wrefresh(playwin);
    end = true;
}

void Logics::check_shoot(){
    // bullet(      WINDOW,  x, y, char, damage)
    sh = new Bullet(playwin, p->getX()+1, p->getY(), '-', 10);
    sh->Fire(sh->getX(), sh->getY());
}
