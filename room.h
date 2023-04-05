#ifndef room.h
#define room.h
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

Room::Room(Room *previous);

Room *currentRoom;

Room*  Room::goprev(r);

Room* Room::gonext(r);

void Room::initRooms();

void generateRoom();


}

#endif room.h



