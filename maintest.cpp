#include "player.h"
#include "room.h"
#include "bullet.h"
#include "easyenemy.h"
#include "elements.h"
#include "specialpowers.h"
#include "weapons.h"
#include <ncurses.h>

void teleport(){
	Player::xLoc = 1;
	Player::yLoc = 1;
	Player::display();
}


int main(){
WINDOW *win = new WINDOW;
room(win);
initRoomList();






return 0;
}
