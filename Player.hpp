#ifndef PLAYER_HPP
#define PLAYER_HPP

// dove mettere gameover?
#pragma once
#include <ncurses.h>

class Player{
    protected:
        int score;
        char character;
        WINDOW *curwin;
        // distanza di attacco
        int distance;
        // potenza di attacco
        int power; // da togliere?
        // aggiunta
    public:
        // spostata in public per testing
        int xLoc, yLoc, xMax, yMax;
        int health;
        int coins;
        int jumpHeight;
	int plusDamage;
        int baseDamage;
        char specialpower;
        Player(WINDOW *win, int x, int y, char c, int h, int s, int jf, int jh, int d, int p, int bd, int pd, int m, char sp);
        // Player(WINDOW *win, int x, int y, char c);
        //get x e y
        int getX();
        int getY();
        // get Damage
        int getDamage();
        // get coins
        int getCoins();
        // colpo subito
        void registerHit();
        void plusScore(int points);
	void minusScore(int points);
        void plusHealth(int hp);
        void minusHealth(int hp);
        void jump();
        //il personaggio cade se non è su un blocco
        void gravity();
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getinput();
        void display();
        // aumenta distanza di attacco 
        void distanceUp(int plusD);
        // aumenta potenza di attacco
        void powerUp(int plusP);
        // nemico colpito
        void hitEnemy();
        // gestione soldi
        void plusMoney(int plusM);
        void minusMoney(int minusM);
};

#endif
