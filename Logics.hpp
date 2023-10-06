#include <ncurses.h>
// includere tutto quello che serve
#include "Player.hpp"
#include "Enemy.hpp"
#include "Elements.hpp"
#include <string>
class Logics {

    public:
        // setta i vari parametri -> capire cosa fare con enemy e elements
        // Logics();

        static bool isInvincible;
        // inizializza tutto
        // void start();

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
};
