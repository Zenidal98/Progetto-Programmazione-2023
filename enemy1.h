#ifndef enemy1.h
#define enemy1.h

class enemy1: public enemy {
private:
int health=10;
int damage=3;

public:
enemy1(int x, int y, int speed)::enemy(x,y,speed);  //dubbio sul come si strutturino le sottoclassi e i loro metodi im n .h e .cpp

};
#endif
