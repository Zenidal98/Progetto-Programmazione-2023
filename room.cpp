#include "room.h"
#include <iostream>
#include <cmath>
class Room{
        public:
                Room(Room *prev);  //nel costruttore next non serve perche' creo le stanze serve in fondo alla lista
                Room *goprev(Room *r);
                Room *gonext(Room *r);
                void initRooms();
                void generateRoom();
        private:
                Room *prev;
                Room *next;
};

Room::Room(Room *previous){
previous->next = this;
prev = previous;
next = NULL;
}

Room *currentRoom;

Room*  Room::goprev(r){
if (r->prev != NULL) currentRoom = r->prev;
return currentRoom; 
}

Room* Room::gonext(r){
if (r->next != NULL) currentRoom = r->next;
return currentRoom;
}

void Room::initRooms(){
        Room* head_room = new Room();
        head_room->prev = NULL; 
        currentRoom = head_room;                //probabile che la prima stanza sia speciale (market)
}

void generateRoom(){
srand(time(NULL));
rand()%20+1;          //19 stanze + 1 market per ora;
// qui devo capire come salvare e caricare le stanze
}




