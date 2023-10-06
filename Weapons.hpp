#ifndef WEAPONS_HPP                               //sono le armi da inserire nel livello market
#define WEAPONS_HPP
#include "Player.hpp"

class Weapons {
private:
       int cost;
       int plus;
       char type;

public:
    Weapons(int cost, char type);   //oltre al costo e al buff che danno si potrebbe mettere un diverso modo di sparare

    void buyweapons(Player *p, char type);

};
#endif
