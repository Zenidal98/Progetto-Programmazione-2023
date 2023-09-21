#include <ncurses.h>
#include "Logics.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
//include "Specialpowers.hpp"?

bool isCollected = false;
bool gameOver = false;

void Logics::check_damage(Player *p, Enemy *e){
	if(p->getX() == e->getX() && p->getY()==e->getY()){
		if(isInvincible == false){
			p->minusHealth(e->getDamage());
			if(p->health<=0)
				gameOver = true;
		}
		
	}
}

void Logics::check_melee(Player *p, Enemy *e){
	int distance = abs(p->getX()-e->getX());
	if(distance <= 2){
		//ridurre la vita del nemico singolo del valore del danno del player cioe p->getDamage.
		if(e->getHealth() <= 0){
                        int s = 0;
                        int c = 0;
                        char cr = 'E';
                        if(e->getDamage()==6){
                        cr = 'M';
                           }
                        else if ( e->getDamage()==15){
                        cr = 'H' ;
                          }
			mvaddch(e->getY(),e->getX(), ' ');
                        s = e->getDroppedScore(cr);
                        c = e->getDroppedCoins(cr);
                        p->plusScore(s);
                        p->plusCoins(c);
		}
	}
}
/*
void Logics::check_shoot(){
	sh = new Bullet(
}*/

void Logics::check_upgrades(Player *p, Elements e){
	if(!isCollected && p->getX() == e.getX() && p->getY() == e.getY()){
		e.touch();
		switch(e.type){
			case 'd':
				p->plusHealth(e.health_up());
				break;
			case 'c':
				p->plusScore(e.score_up());
				break;
			case 'r':
				p->minusScore(e.score_down());
				break;
			case 'g':
				p->plusMoney(e.coins_up());
				break;
			default:
				break;
		}
		isCollected = true;
	}
}

