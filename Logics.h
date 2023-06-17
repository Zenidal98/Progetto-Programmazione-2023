#include <ncurses.h>
// includere tutto quello che serve
#include "player.h"
#include "enemy.h"
#include "elements.h"

class Logics {
    private:
        WINDOW* playwin;
        enemy* e;
        Player* p;
        elements* el;

    public:
        // setta i vari parametri -> capire cosa fare con enemy e elements
        Logics();

        // inizializza tutto
        void start();

        // controlla se player è finito su elements
        void check_upgrades();

        // controlla se player ha preso danno
        void check_damage();
};
