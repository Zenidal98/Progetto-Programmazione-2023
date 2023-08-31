#include <ncurses.h>
// includere tutto quello che serve
#include "Player.hpp"
#include "Enemy.hpp"
#include "Elements.hpp"

#include "Bullet.hpp"

class Logics {
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
        Logics();

        // inizializza tutto
        void start();

        // controlla se player ha preso danno
        void check_damage();

        // controlla se player ha fatto danno
        void check_melee();

        // se premo tasto sparo
        void check_shoot();
};
