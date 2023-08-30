#include <ncurses.h>
// includere tutto quello che serve
#include "logics.hpp"
//srand
#include <cstdlib>
#include <ctime>
#include <cmath>
// #include "room.h"
// #include "specialpowers.h"
Logics::Logics() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    playwin = newwin(20, 50, (yMax / 2) - 10, 10);
    int statY = (yMax/2) - 10;
    int statX = 60;
    statwin = newwin(50, 30, statY, statX);

    //            (WINDOW, x, y, ch,  hp, dam, hard);
    e = new Enemy(playwin, 1, 1, 'e', 100, 10, true);
    // Player      (window, x, y, char,hp, sc,jf,jh,dst,pow,bd,pd,coin, sp)
    p = new Player(playwin, 1, 1, 'P', 100, 0, 1, 4, 1, 1, 50, 0, 0, '\0');
    srand(time(NULL));
}

void Logics::start(){
    // mappa
    box(playwin, 0, 0);
    wrefresh(playwin);

    // box statistiche
    box(statwin, 0, 0);
    mvwprintw(statwin, 1, 1, "Health: %d", p->health);
    wrefresh(statwin);

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
	    
        check_damage();

        wrefresh(playwin);
    }
}


void Logics::check_damage(){
    if((p->getX() == e->getX()) && (p->getY() == e->getY())){
	//if (specialpowers::inv==false){
		p->minusHealth(e->getDamage());
		wprintw(statwin, "\n%d Damage taken!", e->getDamage());
		wrefresh(statwin);
		wprintw(statwin, "\nHealth: %d", p->health);
		wrefresh(statwin);
		if(p->health <= 0)
		gameOver();
	}
    //}else{
	//	wprintw(statwin,"\n You are invicible!");
	//}
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


void Logics::check_shoot(){
    // bullet(      WINDOW,  x, y, char, damage)
    sh = new Bullet(playwin, p->getX()+1, p->getY(), '-', 10);
    sh->Fire(sh->getY(), sh->getX());
    delete(sh);
    sh = nullptr;
}

/*
void logics:teleportpower(){
	room::teleportpowerRoom();



}

int invRID ;
void Logics::invPower(){
	invRID = room::roomID;
	


}
*/
