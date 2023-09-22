#include "Enemy.hpp"
#include "Player.hpp"
// per srand()
#include <cstdlib>
#include <ctime>
    
Enemy::Enemy(int x, int y, char c, WINDOW *win, char enemyType) {           //funzione spawn nel main
    this->x = x;
    this->y = y;
    this->c = c;
    this->win = win;
    getmaxyx(win, yMax, xMax);
    keypad(win, true);
    switch(enemyType){
       case 'E':
            this->health = 10;
            this->damage = 3;
            this->scoreDropped=2;
            this->coinsDropped=3;
            break;
        case 'M':
            this->health = 20;
            this->damage = 6;
            this->scoreDropped=5;
            this->coinsDropped=6;
            break;
        case 'H':
            this->health = 30;
            this->damage = 15;
            this->scoreDropped=8;
            this->coinsDropped=9;
            break;
    }
}

int Enemy::getDroppedScore() {
         return this->scoreDropped;                               // punti che ottieni sconfiggendo quel tipo di nemico
}


int Enemy::getDroppedCoins() {
         return this->coinsDropped;                               //monete che ottieni sconfiggendo il nemico
}

int Enemy::getX(){
    return this->x;
}

int Enemy::getY(){
    return this->y;
}

int Enemy::getHealth(){
    return this->health;
}

int Enemy::getDamage(){
    return this->damage;
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


