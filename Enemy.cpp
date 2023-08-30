#include "enemy.hpp"
// per srand()
#include <cstdlib>
#include <ctime>
    
Enemy::Enemy(WINDOW *win, int x, int y, char c) {           //funzione di spawn ?
    this->x = x;
    this->y = y;
    this->c = c;
    this->win = win;
    getmaxyx(win, yMax, xMax);
    keypad(win, true);
}

Easyenemy:Enemy(x, y, c, *win) {
        this->x = x;
        this->y = y;
        this->c = c;
        this->WINDOW=*win;
        this->health=10;
        this->damage=3;
    }

Mediumenemy::Enemy(x, y, c, *win) {
        this->x = x;
        this->y = y;
        this->c = c;
        this->WINDOW=*win;
        this->health=20;
        this->damage=6;
    }

Hardenemy::Enemy(x, y, c, *win) {
        this->x = x;
        this->y = y;
        this->c = c;
        this->WINDOW=*win;
        this->health=30;
        this->damage=15;
    }

void Enemy::drop_gold(){
    int droppedscore=0;                                      //crea un drop basato sulla vita del nemico in punti e monete
    int droppedcoins=0;
    if(damage==3){
        droppedscore=2;
        droppedcoins=3;
    } else if (damage==6){
        droppedscore=5;
        droppecoins=6;
    } else {
        droppedscore=8;
        droppedcoins=9;
    }
    Player::plusMoney(droppedcoins);
    Player::plusScore(droppedscore);
}


void enemy::takeDamage(int damage) {
    health -= damage;
    if (this->health <= 0) {
        mvaddch(y, x, ' ');                     // cancella il nemico dalla posizione attuale quando viene sconfitto
        drop_gold();
    }
}

int enemy::getX(){
    return this->x;
}

int enemy::getY(){
    return this->y;
}

int enemy::getHealth(){
    return this->health;
}

int enemy::getDamage(){
    return this->damage;
}

// Ripensare movement -> togli ciclo, altrimenti problema con main
// Farlo una sola volta, ed eseguire ciclo in main?

void enemy::movement(){     
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
    
void enemy::display_enemy(){
        mvwaddch(win, y, x, c);
        wrefresh(win);
}


