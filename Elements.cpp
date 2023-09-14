#include "Elements.hpp"         

//i tipi sono d, c, r, g ossia drink, cherry, rock, gold
Elements::Elements(WINDOW *win, int x, int y, char type){       
    this->win = win;
    this->x=x;
    this->y=y;
    this->type=type;
    getmaxyx(win, yMax, xMax);
    keypad(win, true);
}

int Elements::getX(){
    return x;
}

int Elements::getY(){
    return y;
}

// Logics controlla se ho raccolto -> touch elimina l'elemento a schermo
void Elements::touch(){
    mvwaddch(win,y,x,' ');            
}


int Elements::health_up(){   //drink. Nel gioco è rappresentato con la lettera  D
    return 50;
}
   
//gold. Aumenta le monete di 1. Nel gioco è rappresentato con la lettera G.
int Elements::coins_up(){  
    return 1;
}

//cherry. Nel gioco è rappresentato con la lettera  C
int Elements::score_up(){           
    return 200;
}

//rock    R. Il punteggio può andare anche in negativo. Nel gioco è rappresentato con la lettera R
int Elements::score_down(){         
    return 200;
}
  
void Elements::display_element(){
    if(type=='c'){
        mvwaddch(win,y,x,'C');
    }
    else if(type=='r'){
        mvwaddch(win,y,x,'R');
    }
    else if(type=='d'){
        mvwaddch(win,y,x,'D');
    }
    else if(type=='g'){
        mvwaddch(win,y,x,'G');
    }
}
