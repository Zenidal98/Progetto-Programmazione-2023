#ifndef PLAYER_H
#define PLAYER_H

// dove mettere gameover?
#pragma once
#include <ncurses.h>

class Player{
    private:
        int xLoc, yLoc, xMax, yMax;
        int score;
        char character;
        WINDOW *curwin;
        // opzioni per salto
        int jumpForce;
        int jumpHeight;
        // distanza di attacco
        int distance;
        // potenza di attacco
        int power; // da togliere?
        // soldi
        int coins;
        // aggiunta
        int baseDamage;
        int plusDamage;
    public:
        // spostata in public per testing
        int health;
        Player(WINDOW *win, int x, int y, char c, int h, int s, int jf, int jh, int d, int p, int bd, int pd, int m);
        // Player(WINDOW *win, int x, int y, char c);
        //get x e y
        int getX();
        int getY();
        // colpo subito
        void registerHit();
        void plusScore(int points);
        void plusHealth(int hp);
        void minusHealth(int hp);
        void jump();
        //il personaggio cade se non è su un blocco
        void gravity();
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
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