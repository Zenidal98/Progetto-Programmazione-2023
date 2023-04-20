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
			roomList *next;
		};	
	WINDOW *currentWin;	
	public:
		room(WINDOW *win);
		typedef roomList *pRL;
		pRL initRoomList();
		pRL generateRoomStruct(pRL oldStage);
		pRL generateRoom();
		pRL getRoomList();
		void room::gameOver();
		pRL spawnMarket(pRL marketPosition);

};





