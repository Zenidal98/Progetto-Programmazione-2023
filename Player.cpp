#include "player.hpp"

player::layer(WINDOW *win, int y, int x, char c, int h=100, int s=0, int jf=1, int jh=1, int d=1, int p=1, int bd=1, int pd=0, int m=0, char sp='\0'){
// Player::Player(WINDOW *win, int y, int x, char c){
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
    jumpForce = jf;
    jumpHeight = jh;
    baseDamage = bd;
    plusDamage = pd;
    coins = m;
    specialpower = sp;
}

int player::getX(){
    return xLoc;
}

int player::getY(){
    return yLoc;
}

int player::getDamage(){
    return baseDamage + plusDamage;
}

int player::getCoins(){
    return coins;
}

void player::plusScore(int points){
    score += points;
}

void player::plusHealth(int hp){
    health += hp;
}

// Gestire gameOver prima di implementare
void player::minusHealth(int hp){
    health -= hp;

    // if(health = 0)
    //    gameOver = true;
}

void player::gravity(){
    // ChatGPT code
    while(mvwinch(curwin, yLoc + 1, xLoc) == ' ') {
        mvdown();
        display();
        wrefresh(curwin);
        napms(150);
    }
    //nodelay(curwin, true);
    /* while(mvwinch(curwin, yLoc+1, xLoc) == ' '){
        mvdown();
        display();
        wrefresh(curwin);
        napms(150);
    }*/
}

void player::jump(){
    int i, direction;
    // evitare che wgetch blocchi il salto --> modo di saltare diverso?
    nodelay(curwin, true);
    for(i=0; i<jumpHeight; i++){
        mvup();
        display();
        wrefresh(curwin);
        napms(150);
        // spostarsi in volo
        direction = wgetch(curwin);
        if(direction == KEY_RIGHT){
            mvright();
            display();
            wrefresh(curwin);
        }
        else if(direction == KEY_LEFT){
            mvleft();
            display();
            wrefresh(curwin);
        } 
    }
    gravity();
    /*for(i=0; i<jumpHeight; i++){
        mvdown();
        display();
        wrefresh(curwin);
        napms(150);
    }*/
}

void player::mvup(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < 1)
        yLoc = 1;
}

void player::mvdown(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax-2)
        yLoc = yMax-2;
}

void player::mvleft(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
}

void player::mvright(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;
}

int player::getinput(){
    gravity();
    int choice = wgetch(curwin);
    switch(choice){
        case KEY_UP:
            jump();
            break;
        //case KEY_DOWN:
        //    mvdown();
        //    break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        case 'd':
            break;
        default:
            break;
    }
    return choice;
}

void player::display(){
    mvwaddch(curwin, yLoc, xLoc, character);
    wrefresh(curwin);
}

void player::distanceUp(int plusD){
    distance += plusD;
}

void player::powerUp(int plusP){
    power += plusP;
}

/*
// gestire insieme ad enemy
void player::hitEnemy(){
    enemy.registerHit(power);
}*/

void player::plusMoney(int plusM){
    coins += plusM;
}    

void player::minusMoney(int minusM){
    coins -= minusM;
}
