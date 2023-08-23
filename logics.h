#include <ncurses.h>
// includere tutto quello che serve
#include "player.h"
#include "enemy.h"
#include "elements.h"

#include "bullet.h"

class logics {
    private:
        bool isCollected;
        WINDOW* playwin;
        WINDOW* statwin;
        enemy* e;
        Player* p;
        Bullet* sh;
        bool end = false;

    public:
        // setta i vari parametri -> capire cosa fare con enemy e elements
        logics();

        // inizializza tutto
        void start();

        // controlla se player ha preso danno
        void check_damage();

        // controlla se player ha fatto danno
        void check_melee();

        void gameOver();


        // se premo tasto sparo
        void check_shoot();
};
