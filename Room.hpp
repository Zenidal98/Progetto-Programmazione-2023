#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cmath>
#define floor '='
class Room{

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
		Room(WINDOW *win);
		typedef roomList *pRL;
		pRL initRoomList();
		pRL generateRoomStruct(pRL oldStage);
		void generateRoom();
		pRL getRoomList();
		void gameOver();        //prima era room::gameover(); l'ho tolto da errore del make
		pRL spawnMarket(pRL marketPosition);
		void teleportpowerRoom();
};





