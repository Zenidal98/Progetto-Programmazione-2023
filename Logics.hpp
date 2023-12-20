#include <ncurses.h>
// includere tutto quello che serve
#include "Player.hpp"
#include "Enemy.hpp"
#include "Elements.hpp"
#include "Weapons.hpp"
#include "Specialpowers.hpp"
#include "Bullet.hpp"
#include <string>

#include "Room.hpp"

class Logics {

    public:
        // setta i vari parametri -> capire cosa fare con enemy e elements
        // Logics();

        //void init();

        // main di maintest
        void start();

        void gameOver();

        // controlla se player ha preso danno
        void check_damage(Player *p, Enemy *e);

        // controlla se player ha fatto danno
        void check_melee(Player *p, Enemy *e);

        // se premo tasto sparo
        // void check_shoot();

    	// controlla se Player raccoglie Elements
	    void check_upgrades(Player *p, Elements e);

        void showmarket(int roomID, Player *p);

       // prende le x e le y dell'element singolo e le passa a logics
//       void RecognizeElementLocation(int var1,int var2);

        void teleportpower();

        //da maintest:
        void teleport(Player *P);
        char randomizeElementType();
        void ElementsSpawn(Room::pRL stage);
        void EnemySpawn(Room::pRL stage);
        void goNextRoom(Room::pRL oldStage,Player *p);
        void goPreviousRoom(Room::pRL oldStage,Player *p);
};
        extern Enemy *enemyarray[6];  // Dichiarazione esterna della variabile
