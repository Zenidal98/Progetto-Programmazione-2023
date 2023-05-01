#include "player.h"
#include "room.h"
#include "bullet.h"
#include "easyenemy.h"
#include "elements.h"
#include "specialpowers.h"
#include "weapons.h"
#include <ncurses.h>
#include <cmath>

using namespace std;

srand(time(NULL));

void teleport(){
	Player::xLoc = 1;
	Player::yLoc = 1;
	Player::display();
}

void goNextRoom(pRL oldStage){
pRL newStage = oldStage->next;
room::generateRoom(newStage);
teleport();
enemySpawn(newStage);	
elementSpawn(newStage);
}

char randomizeElementType(){
	int i =rand()%2;
	char a;
	switch(i){
	case 0:
		a = 'd';
		break;
	case 1:
		a = 'c';
		break;		
	case 2:
		a = 'd';
		break;
	}
}


void elementSpawn(pRL stage){
	if(rand()%2==1){
		char a = randomizeElementType;
		elements::elements(rand()%29+1,rand()%29+1,a);
		elements::display();
	}	
}


void enemySpawn(pRL stage){
	if(stage->roomID>=2 && stage->roomID<=3){
		for(int i=0, i<2,i++){
			easyenemy::easyenemy(rand()%29+1,rand()%29+1);
			easyenemy::display();
		}	
	}
	if(stage->roomID>3 && stage->roomID<=5){
		for(int i=0, i<4,i++){
			easyenemy::easyenemy(rand()%29+1,rand()%29+1);
			easyenemy::display();
		}	
	}
	if(stage->roomID>5 && stage->roomID<=10){
		for(int i=0, i<2,i++){
			easyenemy::easyenemy(rand()%29+1,rand()%29+1);
			easyenemy::display();
		}
		for(int j=0, j<2, j++){
			mediumenemy::mediumenemy(rand()%29+1,rand()%29+1);
			mediumenemy::display();
		}	
	}
	if(stage->roomID>10 && stage->roomID<=15){
		for(int i=0, i<4, i++){
			mediumenemy::mediumenemy(rand()%29+1, rand()%29+1);
			mediumenemy::display();
		}
	}
	if(stage->roomID>15 && stage->roomID<=20){
		for(int i=0, i<2, i++){
			mediumenemy::mediumenemy(rand()%29+1,rand()%29+1);
			mediumenemy::display();
		}
		hardenemy::hardenemy(rand()%29+1,rand()%29+1);
		hardenemy::hardenemy(rand()%29+1,rand()%29+1);
	}
	if(stage->roomID>20 && stage->roomID<=25){
		for(int i=0, i<2, i++){
			hardenemy::hardenemy(rand()%29+1,rand()%29+1);
			hardenemy::display();
		}
	}
	if(stage->roomID>25 && stage->roomID<=30){
		for(int i=0, i<4, i++){
			hardenemy::hardenemy(rand()%29+1,rand()%29+1);
			hardenemy::display();			
		}	
	}
	if(stage->roomID>30){
		int m = (stage->roomId/10)*2;
		for(int i=0,i<m,i++){   
			hardenemy::hardenemy(rand()%29+1,rand()%29+1);
			hardenemy::display();
		}
	}
}

















int main(){
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
}while(Player::xLoc!=30 && Player::yLoc!=1)
goNextRoom(pippo);
	
	
	

return 0;
}
