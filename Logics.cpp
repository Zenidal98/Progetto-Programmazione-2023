#include <ncurses.h>
#include "Logics.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

bool isCollected = false;
bool gameover = false;
WINDOW *win = new WINDOW;
WINDOW *RoomWin = new WINDOW;
Room *R =new Room(RoomWin);
Player *P = new Player(win,1,1,'P',100,0,1,3,1,1,1,0,0,'\0');
Enemy *E;

void Logics::check_damage(Player *p, Enemy *e){
	if(p->getX() == e->getX() && p->getY()==e->getY()){
			p->minusHealth(e->getDamage());
			if(p->health<=0){
				gameover = true;
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
        powerName="Highjump";
        powerName2='j';
        powerPrice=30*roomID;
    } else if (casualIndex==2){
        powerName="FullHealth";
        powerName2='z';
        powerPrice=50*roomID;
    }
    Specialpowers s = Specialpowers(powerPrice, powerName2);

    // La pistola appare nel 50% dei casi, il fucile nel 40% ed il lanciarazzi nel 10% dei casi.
    int casualIndex2=rand()%(10);
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
    Weapons w = Weapons(weaponPrice, weaponName2);

    // Mostra il relativo pulsante da premere per acquistare qualcosa che corrisponde alla iniziale in inglese
    // std::to string trasforma gli interi in stringhe compatibili. c_str crea la stringa finale.
    mvwprintw(healthWin, 1, 1, ("Press H to buy " +  std::to_string(casualHealth) + " Health. Costs: " + std::to_string(healthPrice)).c_str());
    mvwprintw(powerWin, 1, 1, ("Press P to buy " + powerName + " Power. Costs: " + std::to_string(powerPrice)).c_str());
    mvwprintw(weaponWin, 1, 1, ("Press W to buy " + weaponName + " Weapon. Costs: " + std::to_string(weaponPrice)).c_str());

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
        s.buyspecialpowers(p, powerName2);
        }
            break;
        case 'w':                       // Compra l'arma che va a sostituire il potere base del player
        if(p->coins>=weaponPrice){
        p->coins=p->coins-weaponPrice;
        w.buyweapons(p, weaponName2);
            break;
        }
        default:
            break;
    }
}

void Logics::teleport(Player *P){
	P->yLoc = 30;
	P->xLoc = 1;
	P->display();
}

char Logics::randomizeElementType(){
	int i =rand()%3;
	char a;
	switch(i){
	case 0:
		a = 'd';
		break;
	case 1:
		a = 'c';
		break;		
	case 2:
		a = 'r';
		break;
	case 3:
	        a = 'g';
		break;
	}
    return a; 
}

void Logics::ElementsSpawn(Room::pRL stage){
	if(rand()%2==1){                             // probabilità del 33% che spawni qualcosa in un livello
		char a = randomizeElementType();
		int var1 = rand()%29+1;
		int var2 = rand()%29+1;
		Elements element(win,var1,var2,a);
		element.display_element();
		// L.RecognizeElementLocation(var1,var2);
	}	
}

Enemy *enemyarray[6];

void Logics::EnemySpawn(Room::pRL stage){
   int i = 0;
	if(stage->roomID>=2 && stage->roomID<=3){
		for(i=0; i<2; i++){
			Enemy *easyenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'E');
			easyenemy->display_enemy();
			enemyarray[i]=easyenemy;
		}	
	}
	if(stage->roomID>3 && stage->roomID<=5){
		for(int i=0; i<4; i++){
			Enemy *easyenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'E');
		        easyenemy->display_enemy();
			enemyarray[i]=easyenemy;
		}	
	}
	if(stage->roomID>5 && stage->roomID<=10){
		for(int i=0; i<2; i++){
			Enemy *easyenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'E');
			easyenemy->display_enemy();
			enemyarray[i]=easyenemy;
		}
		for(int j=0; j<2; j++){
			Enemy *mediumenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'M');
			mediumenemy->display_enemy();
			enemyarray[i]=mediumenemy;
		}	
	}
	if(stage->roomID>10 && stage->roomID<=15){
		for(int i=0; i<4; i++){
			Enemy *mediumenemy = new Enemy(rand()%29+1, rand()%29+1,'#',win,'M');
			mediumenemy->display_enemy();
			enemyarray[i]=mediumenemy;
		}
	}
	if(stage->roomID>15 && stage->roomID<=20){
		for(int i=0; i<2; i++){
			Enemy *mediumenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'M');
			mediumenemy->display_enemy();
			enemyarray[i]=mediumenemy;
		}
		        Enemy *hardenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'H');
		        hardenemy->display_enemy();
		        enemyarray[i]=hardenemy;
	}
	if(stage->roomID>20 && stage->roomID<=25){
		for(int i=0; i<2; i++){
			Enemy *hardenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'H');
			hardenemy->display_enemy();
			enemyarray[i]=hardenemy;
		}
	}
	if(stage->roomID>25 && stage->roomID<=30){
		for(int i=0; i<4; i++){
		        Enemy *hardenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'H');
			hardenemy->display_enemy();
			enemyarray[i]=hardenemy;
		}	
	}
	if(stage->roomID>30){
		                               //int m = (stage->roomID/10)*2;
		for(int i=0; i<6; i++){   
			Enemy *hardenemy = new Enemy(rand()%29+1,rand()%29+1,'#',win,'H');
			hardenemy->display_enemy();
			enemyarray[i]=hardenemy;
		}
	}
	     for(int i =0; i<6; i++){
	        delete enemyarray[i];          // cercare come si svuota 
  }
}

void Logics::goNextRoom(Room::pRL oldStage,Player *p){
	Room::pRL newStage = oldStage->next;
	Room::pRL pippo = R->generateRoomStruct(oldStage);
	R->generateRoom(newStage,p);
	teleport(p);
	EnemySpawn(newStage);	
	ElementsSpawn(newStage);
}

void Logics::goPreviousRoom(Room::pRL oldStage,Player *p){
	if(oldStage->roomID!=0){              // non il primo livello
		Room::pRL newStage = oldStage->prev;
		R->generateRoom(newStage,p);
		teleport(p);
		EnemySpawn(newStage);
		ElementsSpawn(newStage);
	}
}

void Logics::start(){
	Room::pRL pippo = R->initRoomList();
	P->display();
	do{
		P->display();
		wrefresh(RoomWin);
	}while(P->getinput()!='x');
	//R->generateRoom();
	do{
		P->getinput();
		if(P->getinput() == 's'){
			Bullet sh = Bullet(RoomWin, P->getX()+1, P->getY(), '-', 10, *enemyarray, 6);
			sh.Fire(sh.getX(), sh.getY());
		}
	}while(P->xLoc!=30 && P->yLoc!=1);
	goNextRoom(pippo, P);
}

/*
void Logics::init(){
	WINDOW *win = new WINDOW;
	WINDOW *RoomWin = new WINDOW;
	Room *R =new Room(RoomWin);
	Player *P = new Player(win,1,1,'P',100,0,1,3,1,1,1,0,0,'\0');
	Enemy *E;
}
*/

void Logics::gameOver(){
    wclear(win);
    mvprintw(7,20,"   ______ ___     __  ___ ______");
    mvprintw(8,20,"  / ____//   |   /  |/  // ____/");
    mvprintw(9,20," / / __ / /| |  / /|_/ // __/   ");
    mvprintw(10,20,"/ /_/ // ___ | / /  / // /___   ");
    mvprintw(11,20,"\\____//_/  |_|/_/  /_//_____/   ");
    mvprintw(12,20,"                                ");
    mvprintw(13,25,"   ____  _    __ ______ ____ ");
    mvprintw(14,25,"  / __ \\| |  / // ____// __ \\");
    mvprintw(15,25," / / / /| | / // __/  / /_/ /");
    mvprintw(16,25,"/ /_/ / | |/ // /___ / _, _/ ");
    mvprintw(17,25,"\\____/  |___//_____//_/ |_|  ");
}