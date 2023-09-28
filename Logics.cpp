#include <ncurses.h>
#include "Logics.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
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
	if(distance <= 2){                             //colpito
                int energy=0;
                energy=e->getHealth();
                energy=energy-p->getDamage();
		if(energy <= 0){
                        int s = 0;
                        int m = 0;
			mvaddch(e->getY(),e->getX(), ' ');
                        s = e->getDroppedScore();
                        m = e->getDroppedCoins();
                        p->plusScore(s);
                        p->plusMoney(m);
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

void Logics::showmarket(int roomID, Player *p) {
    clear();  // Cancella lo schermo


    // Le slide richiedono 3 opzioni: vita, poteri e armi
    WINDOW *healthWin = newwin(10, 20, 5, 5);
    WINDOW *powerWin = newwin(10, 20, 5, 30);
    WINDOW *weaponWin = newwin(10, 20, 5, 55);

    // Inizializzazione attributi da comprare:

     //Inizializzazione prezzi.
    int healthPrice=0;
    int powerPrice=0;
    int weaponPrice=0;


    // Per la vita è semplice. Il player ha vita max di 100 quindi un numero casuale fra 1 e 50 va bene.
    int casualHealth=rand()%(50)+10;   //cosi non ho problemi nella divisione per 10
    healthPrice=healthPrice*roomID;

     // Per i poteri la probabilità che appaia come nome è equivalente
    int casualIndex=rand()%(3);
    std::string powerName;      // Qui metto due variabili per un motivo; la prima serve a far apparire il nome a schermo. La seconda a chiamare
    char powerName2='.';     // la variabile nelle funzioni dedicate nello switch finale, per questo sono solo lettere singole in power2.
    if(casualIndex==0){
        powerName="DamageUp";
        powerName2='d';
        powerPrice=20*roomID;
    } else if (casualIndex==1){
        powerName="Teleport";
        powerName2='t';
        powerPrice=30*roomID;
    } else if (casualIndex==2){
        powerName="Invincibility";
        powerName2='i';
        powerPrice=50*roomID;
    }

    // La pistola appare nel 50% dei casi, il fucile nel 40% ed il lanciarazzi nel 10% dei casi.
    int casualIndex2=rand()%(10)
    std::string weaponName;
    char weaponName2='.';
    if((casualIndex2>=0)&&(casualIndex2<=4)){
        weaponName="Pistol";
        weaponName2='p';
        weaponPrice=10*roomID;
    } else if ((casualIndex2>=5)&&(casualIndex2<=8)){
        weaponName="Firelock";
        weaponName2='f';
        weaponPrice=100*roomID;
    } else if (casualIndex2==9){
        weaponName="Rocket_Launcher";
        weaponName2='l';
        weaponPrice=200*roomID;
    }


    // Mostra il relativo pulsante da premere per acquistare qualcosa che corrisponde alla iniziale in inglese
    mvwprintw(healthWin, 1, 1, "Health: " +  std::to_string(casualHealth) + "," + std::to_string(healthPrice) + " press H ");
    mvwprintw(powerWin, 1, 1, "Power: " + std::to_string(powerName) + "," + std::to_string(powerPrice) + " press P ");
    mvwprintw(weaponWin, 1, 1, "Weapon: " + std::to_string(weaponName) + ","+ std::to_string(weaponPrice) + " press W ");

    // Aggiorna le finestre
    wrefresh(healthWin);
    wrefresh(powerWin);
    wrefresh(weaponWin);

    // Scelta
    char ch = getch();
    switch (ch) {
        case 'h':
                if(p->coins>=healthPrice){
        if(p->health<100){
              p->health=p->health+casualHealth;
              p->coins=p->coins-healthPrice;

              if(p->health>100){
                    p->health=100;
              }
           }
         }
            break;
        case 'p':                       // Compra il potere se non ne ha già uno
        if(p->coins>=powerPrice){
        p->coins=p->coins-powerPrice;
        Specialpowers::buyspecialpowers(powerName2);
        }
            break;
        case 'w':                       // Compra l'arma che va a sostituire il potere base del player
        if(p->coins>=weaponPrice){
        p->coins=p->coins-weaponPrice;
        Weapons::buyweapons(weaponName2);
            break;
        }
        default:
            break;
    }
}
