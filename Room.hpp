#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cmath>
#define floor '='
/**
struct RoomList{
	int RoomID;
	int RoomType;
	bool alreadyBuit = false;
	RoomList(int RoomID, int Roomtype);
};

class RoomListClass{
private:
	struct Node{
		RoomList data;
		Node* prev;
		Node* next;
		
		Node(const RoomList& roomData);
	};
	
	Node* head;
	Node* tail;
public:
	//Constructor to initialize an empty list
	RoomListClass();
	
	//Function to add a new node at the end of the list
	void append(const RoomList& roomData);
	


	//Destructor to clean up memory
	~RoomListClass();
};









**/
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





