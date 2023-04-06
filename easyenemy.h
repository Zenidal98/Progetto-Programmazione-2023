#ifndef easyenemy.h
#define easyenemy.h

class easyenemy: public enemy {
private:
int health=10;
int damage=3;

public:
easyenemy(int x, int y, int speed)::enemy(x,y,speed);  //dubbio sul come si strutturino le sottoclassi e i loro metodi im n .h e .cpp

};
#endif
