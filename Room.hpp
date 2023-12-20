#ifndef ROOM_HPP
#define ROOM_HPP
 

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cmath>
//#include "Logics.hpp"
#define floor '='
class Player;
class Logics;
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
		void generateRoom(pRL newStage, Player *p);
//		pRL getRoomList();
		void gameOver();        //prima era room::gameover(); l'ho tolto da errore del make
		pRL spawnMarket(pRL marketPosition);
		void teleportpowerRoom(pRL stage);
};


#endif


