#include "Player.hpp"
#include "Logics.hpp"
#include "Room.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Elements.hpp"
#include "Specialpowers.hpp"
#include "Weapons.hpp"
#include <ncurses.h>
#include <cmath>
#include <ctime>

using namespace std;

WINDOW *win = new WINDOW;
WINDOW *RoomWin = new WINDOW;
Room *R =new Room(RoomWin);
Player *P = new Player(win,1,1,'P',100,0,1,3,1,1,1,0,0,'\0');
Logics L;

Enemy *enemyarray[6];

void teleport(){
	P->yLoc = 30;
	P->xLoc = 1;
	P->display();
}

char randomizeElementType(){
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

void ElementsSpawn(Room::pRL stage){
	if(rand()%2==1){                             // probabilità del 33% che spawni qualcosa in un livello
		char a = randomizeElementType();
		int var1 = rand()%29+1;
		int var2 = rand()%29+1;
		Elements element(win,var1,var2,a);
		element.display_element();
		// L.RecognizeElementLocation(var1,var2);
	}	
}

void EnemySpawn(Room::pRL stage){
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
void goNextRoom(Room::pRL oldStage,Player *p){
	Room::pRL newStage = oldStage->next;
	Room::pRL pippo = R->generateRoomStruct(oldStage);
	R->generateRoom(newStage,p);
	teleport();
	EnemySpawn(newStage);	
	ElementsSpawn(newStage);
}

void goPreviousRoom(Room::pRL oldStage,Player *p){
	if(oldStage->roomID!=0){              // non il primo livello
		Room::pRL newStage = oldStage->prev;
		R->generateRoom(newStage,p);
		teleport();
		EnemySpawn(newStage);
		ElementsSpawn(newStage);
	}
}


void gameOver(){
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


int main(){
srand(time(NULL));
initscr();
noecho();
refresh();
Room::pRL pippo = R->initRoomList();
//Player *P = new Player(win,1,1,'P',100,0,1,3,1,1,1,0,0,'\0');
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

	
	
	
	
	
/*	
//bool rightDoor = Player::xLoc!=30 && Player::yLoc!=1;	
//bool leftDoor = Player::xLoc!=1 && Player::yLoc!=1;
//bool escape = p->getmv()=='x'
//bool gameOver = Player::health<=0

//do{
//	p->display();
//	wrefresh(win);
	if(rightDoor==true){
		goNextRoom(pRL oldstage);
	 } else if(leftDoor==true){
		goPreviousRoom(pRL oldstage);
	}
	Player::getmv();
//}while(rightDoor==true && leftDoor==true && escape==false && gameOver==false);
//if(escape==true || gameOver==true){
//	gameOver();
//}
//------------------qui andra' messo il salvataggio su file----------------------------------------
*/



return 0;
 }

