
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

void teleport(){
	Player::xLoc = 1;
	Player::yLoc = 30;
	Player::display();
}

void goNextRoom(Room::pRL oldStage){
Room::pRL newStage = oldStage->next;
Room::pRL pippo=Room::generateRoomStruct(pRL oldStage);
Room::generateRoom(newStage);
teleport();
Specialpowers::inv = false;
enemySpawn(newStage);	
elementSpawn(newStage);
}

void goPreviousRoom(Room::pRL oldStage){
if(oldStage->roomID!=0){              // non il primo livello
Room::pRL newStage = oldStage->prev;
Room::generateRoom(newStage);
teleport();
enemySpawn(newStage);
elementSpawn(newStage);
   }
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

void elementSpawn(pRL stage){
	if(rand()%2==1){                             // probabilità del 33% che spawni qualcosa in un livello
		char a = randomizeElementType;
		elements::elements(rand()%29+1,rand()%29+1,a);
		elements::display();
	}	
}

void enemySpawn(pRL stage){
	if(stage->roomID>=2 && stage->roomID<=3){
		for(int i=0; i<2; i++){
			easyenemy::easyenemy(rand()%29+1,rand()%29+1);
			easyenemy::display();
		}	
	}
	if(stage->roomID>3 && stage->roomID<=5){
		for(int i=0; i<4; i++){
			easyenemy::easyenemy(rand()%29+1,rand()%29+1);
			easyenemy::display();
		}	
	}
	if(stage->roomID>5 && stage->roomID<=10){
		for(int i=0; i<2; i++){
			easyenemy::easyenemy(rand()%29+1,rand()%29+1);
			easyenemy::display();
		}
		for(int j=0; j<2; j++){
			mediumenemy::mediumenemy(rand()%29+1,rand()%29+1);
			mediumenemy::display();
		}	
	}
	if(stage->roomID>10 && stage->roomID<=15){
		for(int i=0; i<4; i++){
			mediumenemy::mediumenemy(rand()%29+1, rand()%29+1);
			mediumenemy::display();
		}
	}
	if(stage->roomID>15 && stage->roomID<=20){
		for(int i=0; i<2; i++){
			mediumenemy::mediumenemy(rand()%29+1,rand()%29+1);
			mediumenemy::display();
		}
		hardenemy::hardenemy(rand()%29+1,rand()%29+1);
		hardenemy::hardenemy(rand()%29+1,rand()%29+1);
	}
	if(stage->roomID>20 && stage->roomID<=25){
		for(int i=0; i<2; i++){
			hardenemy::hardenemy(rand()%29+1,rand()%29+1);
			hardenemy::display();
		}
	}
	if(stage->roomID>25 && stage->roomID<=30){
		for(int i=0; i<4; i++){
			hardenemy::hardenemy(rand()%29+1,rand()%29+1);
			hardenemy::display();			
		}	
	}
	if(stage->roomID>30){
		int m = (stage->roomId/10)*2;
		for(int i=0; i<m; i++){   
			hardenemy::hardenemy(rand()%29+1,rand()%29+1);
			hardenemy::display();
		}
	}
}

int main(){
srand(time(NULL));
initscr();
noecho();
refresh();
WINDOW *win = new WINDOW;
room(win);
pippo = initRoomList();
Player::Player(win,1,1,'P',100,0,1,3,1,1,1,0,0);
Player::display();

do{
	p->display();
	wrefresh(win);
}while(p->getmv()!='x');
room::generateRoom(pippo);
do{
	Player::getmv();
}while(Player::xLoc!=30 && Player::yLoc!=1);
goNextRoom(pippo);

	
	
	
	
	
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
