#include <ncurses.h>
// includere tutto quello che serve
#include "Logics.hpp"
//srand
#include <cstdlib>
#include <ctime>
#include <cmath>
// #include "room.h"
// #include "specialpowers.h"
Logics::Logics() {
    bool isCollected = false;
    bool isInvincible = false;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    playwin = newwin(20, 50, (yMax / 2) - 10, 10);
    int statY = (yMax/2) - 10;
    int statX = 60;
    statwin = newwin(50, 30, statY, statX);
	

    //   
    char letters1[]="EMH";
    char x = letters1[rand()%4];
    e = new Enemy(1, 1, x, playwin);
    // Player      (window, x, y, char,hp, sc,jf,jh,dst,pow,bd,pd,coin, sp)
    p = new Player(playwin, 1, 1, 'P', 100, 0, 1, 4, 1, 1, 50, 0, 0, '\0');
    srand(time(NULL));
    char letters2[]="dcrg";
    char y = letters2[rand()%4];
    el = new Elements(playwin, rand()%49+1, rand()%19+1, y);
}

int elementx = -1;                //serve per passare a logics le coordinate dal main dell'element singolo e per attivare le funzioni di logics
int elementy = -1;

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
	
	check_upgrades();
        p->display();
	    
        check_damage();

        wrefresh(playwin);
    }
}


void Logics::check_damage(){
    if((p->getX() == e->getX()) && (p->getY() == e->getY())){
	if (isInvincible==false){
		p->minusHealth(e->getDamage());
		wprintw(statwin, "\n%d Damage taken!", e->getDamage());
		wrefresh(statwin);
		wprintw(statwin, "\nHealth: %d", p->health);
		wrefresh(statwin);
		if(p->health <= 0)
		gameOver();
	}else{
		wprintw(statwin,"\n You are invicible!");
	}
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
}


void Logics::check_shoot(){
    // bullet(      WINDOW,  x, y, char, damage)
    sh = new Bullet(playwin, p->getX()+1, p->getY(), '-', 10);
    sh->Fire(sh->getY(), sh->getX());
    delete(sh);
    sh = nullptr;
}

void Logics::RecognizeElementLocation(int var1, int var2){    // funzione per usare i valori dell'elements singolo dal main
	elementx=var1;
	elementy=var2;
}

void Logics::check_upgrades(){
	if(!isCollected && p->getX() == var1 && p->getY() == var2){
		el->touch();
		//Erase element
		mvwaddch(playwin, el->getY(), el->getX(), ' ');
		if(el->type == 'd')
			p->plusHealth(el->health_up());
		else if(el->type == 'c')
			p->plusScore(el->score_up());
		else if(el->type == 'r')
			p->minusScore(el->score_down());
		else
			p->plusMoney(el->coins_up());
		wrefresh(playwin);
		delete(el);
		el = nullptr;
		isCollected = true;
     }
   }

