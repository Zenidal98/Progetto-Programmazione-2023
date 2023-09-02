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
		e->takeDamage(p->getDamage());
		//print...
		if(e->getHealth() <= 0){
			//gestire morte o passare bool true?
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

