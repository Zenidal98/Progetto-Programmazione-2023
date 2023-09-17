#include "Enemy.hpp"
#include "Player.hpp"
// per srand()
#include <cstdlib>
#include <ctime>
    
Enemy::Enemy(int x, int y, char c, WINDOW *win) {           //funzione di spawn ?
    this->x = x;
    this->y = y;
    this->c = c;
    this->win = win;
    getmaxyx(win, yMax, xMax);
    keypad(win, true);
}

Easyenemy::Enemy(x, y, c, *win) {
        this->enemyType='E';
        this->health=10;
        this->damage=3;
    }

Mediumenemy::Enemy(x, y, c, *win) {
        this->enemyType='M';
        this->health=20;
        this->damage=6;
    }

Hardenemy::Enemy(x, y, c, *win) {
        this->enemyType='H';
        this->health=30;
        this->damage=15;
    }

int Enemy::getDroppedScore(char enemyType) {
    int droppedscore = 0;                                      // crea un drop basato sul tipo di nemico in punti
    if(this->enemyType == 'E'){
        droppedscore = 2;
    } else if (this->enemyType == 'M'){
        droppedscore = 5;
    } else {
        droppedscore = 8;
    }
    return droppedscore;
}


int Enemy::getDroppedCoins(char enemyType) {
    int droppedcoins = 0;                                    // crea un drop basato sul tipo di nemico in monete
    if(this->enemyType == 'E'){
        droppedcoins = 3;
    } else if (this->enemyType == 'M'){
        droppedcoins = 6;
    } else {
        droppedcoins = 9;
    }
    return droppedcoins;
}
/*
void Enemy::takeDamage(int takenDamage) {
    
    health -= damage;
    if (this->health <= 0) {
        mvaddch(y, x, ' ');                     // cancella il nemico dalla posizione attuale quando viene sconfitto
        getDroppedScore(cr);                    // FORSE QUESTO VA MESSO NEL MAIN POICHE I DROP VANNO ATTRIBUITI AL PLAYER (player::plusmoney....
        getDroppedCoins(cr);
    }
}
*/
int Enemy::getX(){
    return this->x;
}

int Enemy::getY(){
    return this->y;
}

int Enemy::getHealth(){
int healthgive=0;
    if(this->enemyType=='E'){
          healthgive=10;
}   else if (this->enemyType=='M'){
          healthgive=20;
}   else {
          healthgive=30;
}
            return healthgive;
}

int Enemy::getDamage(){
int givedamage=0;
    if(this->enemyType=='E'){
           givedamage=3;
}   else if(this->enemyType=='M'){
           givedamage=6;
}   else {
           givedamage=15;
}
    return givedamage;
}

// Ripensare movement -> togli ciclo, altrimenti problema con main
// Farlo una sola volta, ed eseguire ciclo in main?

void Enemy::movement(){     
    srand(time(NULL));               //imposto il seed per la generazione di numeri casuali                
       
    // gravity
    while(mvwinch(win, y+1, x) == ' '){
        //mvdown
        mvwaddch(win, y, x, ' ');
        y++;
        if(y > yMax-2)
            y = yMax-2;
        display_enemy();
        wrefresh(win);
        napms(150);
    }

    napms(150);
    
    int direction = rand()%2+1;          
    switch(direction){
        case 1 :  //sinistra
            mvwaddch(win, y, x, ' ');
            x--;
            if(x<1)
                x = 1;
            display_enemy();
            break;
        case 2 :  //destra
            mvwaddch(win, y, x, ' ');
            x++;
            if(x>xMax)
                x = xMax-2;
            display_enemy();
            break;
    }
    
}
    
void Enemy::display_enemy(){
        mvwaddch(win, y, x, c);
        wrefresh(win);
}


