#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cmath>
#define floor '='
class room{

	private:
		struct roomList{
			roomList *prev;
			int roomID;
			int roomType;
			bool alreadyBuilt = false;
			roomList *next;
		};	
	WINDOW *currentWin;	
	public:
		room(WINDOW *win);
		typedef roomList *pRL;
		pRL initRoomList();
		pRL generateRoomStruct(pRL oldStage);
		void generateRoom();
		pRL getRoomList();
		void room::gameOver();
		pRL spawnMarket(pRL marketPosition);
		void teleportpowerRoom();
};





