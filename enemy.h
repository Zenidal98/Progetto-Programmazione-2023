#ifndef enemy.h
#define enemy.h

class enemy {
private:
        int x;
        int y;
        int speed;
        int health;
        int damage;

public:
    enemy(int x, int y, int speed, int health, int damage);

    int getX();

    int getY();

    int getHealth();

    void takeDamage(int damage);

    void increasehealth(int plush);

    void increasedamage(int plusd);

    void movement();
     
    void dropgold();

};
#endif
