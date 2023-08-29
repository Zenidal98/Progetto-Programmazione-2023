#ifndef WEAPONS_HPP                               //sono le armi da inserire nel livello market
#define WEAPONS_HPP

class weapons {
private:
       int cost;
       int plus;
       char type;

public:
    weapons(int cost, int plus, char type);   //oltre al costo e al buff che danno si potrebbe mettere un diverso modo di sparare

    void buyweapons(char type);

};
#endif
