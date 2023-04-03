#ifndef weapons.h                               //sono le armi da inserire nel livello market
#define weapons.h

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
