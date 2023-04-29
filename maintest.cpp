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
