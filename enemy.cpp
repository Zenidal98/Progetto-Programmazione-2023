#include "enemy.hpp"
// per srand()
#include <cstdlib>
#include <ctime>
    
enemy::enemy(WINDOW *win, int x, int y, char c, int health, int damage, bool hard) {           //funzione di spawn ?
    this->x = x;
    this->y = y;
    this->c = c;
    this->health = health;
    this->damage = damage;
    this->win = win;
    getmaxyx(win, yMax, xMax);
    keypad(win, true);
    if(hard){
        health += 100;
        damage += 1;
    }
}

easyenemy::enemy(int x, int y, char c) {
        this->x = x;
        this->y = y;
        this->c = c
    }

mediumenemy::enemy(int x, int y, char c) {
        this->x = x;
        this->y = y;
        this->c = c
    }

hardenemy::enemy(int x, int y, char c) {
        this->x = x;
        this->y = y;
        this->c = c
    }

// inserire in Controller?
/*
void enemy::increasehealth(int plush){      //vuol dire plus health
    if(map.level%3==0){                   //da cambiare .........    //forse da togliere
        this->health++;
    }
}

void enemy::increasedamage(int plusd){      //plus damage
    if(map.level%3==0){                     //da cambiare .........
        this->damage++;
    }
}*/


void enemy::drop_gold(){
    int drop=0;                                      //crea un drop basato sulla vita del nemico
    if(health==1){
        drop=1;
    } else if (health==2){
        drop=2;
    } else {
        drop=3;
    }
    // inserire in Controller?
    // player.gold = player.gold + drop; 
}

void enemy::drop_points(){                      //da punti in base al nemico ucciso
    int points=0;
    if(health==1){                                      
        points=1;
    } else if (health==2){
        points=2;
    } else {
        points=3;
    }
    // inserire in Controller?
    // player.points = player.points + points; 
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
    
    // per ora Gravity in Enemy -> poi implementa class Gravity    
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
    /*
    // check collisioni                                                        
    if (new_y >= 1 && new_y < map.y-1 && new_x >= 1 && new_x < map.x -1) {       //da cambiare
        mvwaddch(win, enemy_y, enemy_x, ' '); // Cancello il nemico dalla vecchia posizione
        enemy_y = new_y;
        enemy_x = new_x;
        mvwaddch(win, enemy_y, enemy_x, '@'); // Disegno il nemico nella nuova posizione
        wrefresh(win);
    }
    // Attendo per un breve periodo di tempo prima di eseguire un nuovo ciclo
    napms(100); */

