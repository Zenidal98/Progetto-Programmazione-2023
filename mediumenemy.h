#ifndef mediumenemy.h
#define mediumenemy.h

class mediumenemy: public enemy {
private:
int health=20;
int damage=6;

public:
mediumenemy(int x, int y, int speed)::enemy(x,y,speed);

};
#endif
