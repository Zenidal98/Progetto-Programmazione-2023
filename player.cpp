#include "player.hpp"

Player::Player(WINDOW *win, int y, int x, char c, int h=100, int s=0, int d=1, int p=1){
    curwin = win;
    yLoc = y;
    xLoc = x;
    character = c;
    distance = d;
    power = p;
    getmaxyx(curwin, yMax, xMax);       //prende i due valori per creare il box successivamente
    keypad(curwin, true);               //cattura input da tastiera
    health = h;
    score = s;
}

void Player::plusScore(int points){
    score += points;
}

void Player::plusHealth(int hp){
    health += hp;
}

/* Gestire gameOver prima di implementare
void Player::minusHealth(int hp){
    health -= hp;
    if(health = 0)
        gameOver = true;
}*/

void Player::mvup(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < 1)
        yLoc = 1;
}

void Player::mvdown(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax-2)
        yLoc = yMax-2;
}

void Player::mvleft(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
}

void Player::mvright(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;
}

int Player::getmv(){
    int choice = wgetch(curwin);
    switch(choice){
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display(){
    mvwaddch(curwin, yLoc, xLoc, character);
}

void Player::distanceUp(int plusD){
    distance += plusD;
}

void Player::powerUp(int plusP){
    power += plusP;
}

/*
// gestire insieme ad enemy
void Player::hitEnemy(){
    Enemy.registerHit(power);
}*/

void Player::plusMoney(int plusM){
    coins += plusM;
}    

void Player::minusMoney(int minusM){
    coins -= minusM;
}