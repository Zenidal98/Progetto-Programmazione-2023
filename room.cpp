#include "room.h"
#include <iostream>
#include <cmath>
#include "market.h"
srand(time(NULL));

room::room(WINDOW *win){
	currentWin = win;
}
room::pRL room::initRoomList(){
	pRL s = new roomList;
	pRL t = new roomListl;
	pRL head = new roomList;
	head->roomID = 0;
	head->roomType = 0;        //Codice 0 Starting Level
	head->next = s;
	head->prev = head;         //testa circolare
	s->prev = head;
	s->roomID = 1;
	s->roomType = 1;           //Codice 1 Market
	s->next = t;
	t->prev = s;
	t->roomID = 2;
	t->roomType =((rand()%10)+2);
       	t->next = NULL;
	return head;
}
room::pRL room::generateRoomStruct(pRL oldStage){
	if( oldStage->next==NULL){
		pRL p = new roomList;
		stage->next = p;
		p->prev = oldStage;
		p->roomID = (oldStage->roomID)+1;
		p->roomType = (rand()%10+1);
		p->next = NULL;
		p->isMarked = true;
		return p;
	}else if (oldStage->next->isMarked==true){
		return p;
	}//esiste nella realta' il terzo caso?
}
room::pRL room::generateRoom(pRL newStage ){
//10 stanze + 1 market + 1 starting level
// qui devo capire come salvare e caricare le stanze
	if((roomID%5)==0){showmarket()}
	else{
	switch(stage->roomType){
		case 0:      //starting level
		{
		}
		break;
		case 1:      //Market (uso funzione esterna per espandere
		{showmarket();
		}
		break;
		case 2:
		{	
			mvwhline(currentWin, 8, 8, floor, 10);
			mvwhline(currentWin, 4, 22, floor, 5);

		}
		break;
		case 3:
		{
			mvwhline(currentWin, 6, 9, floor, 6);
			mvwhline(currentWin, 4, 17, floor, 4);
			mvwhline(currentWin, 8, 5, floor, 10);	
		}
		break;
		case 4:
		{
			mvwhline(currentWin, 5, 9, floor, 3);
		        mvwhline(currentWin, 2, 19, floor, 7);		
		}
		break;
		case 5:
		{
			mvwhline(currentWin, 6, 13, floor, 10);
			mvwhline(currentWin, 5, 18, floor, 2);
			mvwhline(currentWin, 3, 7, floor, 7);	
		}
		break;
		case 6:
		{
			mvwhline(currentWin, 4, 6, floor, 20);
			mvwhline(currentWin, 8, 6, floor, 16);

		}
		break;
		case 7:
		{
			mvwhline(currentWin, 7, 20, floor, 6);
			mvwhline(currentWin, 5, 8, floor, 13);
			mvwhline(currentWin, 10, 10, floor, 4);
		}
		break;
		case 8:
		{
			mvwhline(currentWin, 5, 8, floor, 5);
		       	mvwhline(currentWin, 3, 15, floor, 9);
			mvwhline(currentWin, 7, 20, floor, 2);
		}
		break;
		case 9:
		{
			mvwhline(currentWin, 4, 10, floor, 20);  
		}
		break;
		case 10:
		{
			mvwhline(currentWin, 2, 7, floor, 5);
			mvwhline(currentWin, 4, 12, floor, 5);
			mvwhline(currentWin, 6, 17, floor, 5);
			mvwhline(currentWin, 8, 22, floor,5);
		}
		break;
		case 11:
		{
			mvwhline(currentWin, 3, 9, floor, 13);
			mvwhline(currentWin, 6, 17, floor, 3);
		}
		break;
		case 12:
		{
			mvwhline(currentWin, 7, 10, floor, 8);
			mvwhline(currentWin, 8, 20, floor, 4);
		}
		break;
	}
	}

			
}

room::pRL room::getRoomList(){
	return head;
}

void room::gameOver(){
    mvprintw(7,20,"   ______ ___     __  ___ ______");
    mvprintw(8,20,"  / ____//   |   /  |/  // ____/");
    mvprintw(9,20," / / __ / /| |  / /|_/ // __/   ");
    mvprintw(10,20,"/ /_/ // ___ | / /  / // /___   ");
    mvprintw(11,20,"\\____//_/  |_|/_/  /_//_____/   ");
    mvprintw(12,20,"                                ");
    mvprintw(13,25,"   ____  _    __ ______ ____ ");
    mvprintw(14,25,"  / __ \\| |  / // ____// __ \\");
    mvprintw(15,25," / / / /| | / // __/  / /_/ /");
    mvprintw(16,25,"/ /_/ / | |/ // /___ / _, _/ ");
    mvprintw(17,25,"\\____/  |___//_____//_/ |_|  ");
}
   
room::pRL room::spawnMarket(pRL marketPosition){
	//da capire come fare un tasto per interactare
        

}


