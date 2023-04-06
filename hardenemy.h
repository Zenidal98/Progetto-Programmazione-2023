#ifndef hardenemy.h
#define hardenemy.h

class hardenemy: public enemy {
private:
int health=30;
int damage=15;

public:
hardenemy(int x, int y, int speed)::enemy(x,y,speed);

};
#endif
