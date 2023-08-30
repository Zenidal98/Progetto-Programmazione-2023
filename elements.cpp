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

// Spostare in Logics la parte di contatto (qui non vedo Player) --> Qui CONSIDERO GIA' TOCCATO
void Elements::touch(){
    // non qua -> dentro Logics
    //if((player.x==elements.x)&&(player.y==elements.y)){
    
    //check sul tipo di collezionabile raccolto
    if(type=='d'){                               
        hp = health_up(); 
    } else if(type=='c'){
        points = score_up();
    } else if(type=='r'){
        points = score_down();
    } else if(type=='g'){
        coins = coins_up();
    }

    //libero quel pezzetto. Forse non basta o crea problemi, da tenere in considerazione
    // mvaddch(WINDOW*map,y,x,' ');            
    
    //}
}


// NON SI PUO' FARE QUI per Player --> creare una variabile che ritorna vita da aggiungere?
int Elements::health_up(){   //drink. Questo va messo anche nel market.  Nel gioco è rappresentato con la lettera  D
    return 50;
}


// uguale a health_up     
//gold. Aumenta le monete di 1. Nel gioco è rappresentato con la lettera G.
int Elements::coins_up(){  
    return 1;
}

// uguale
//cherry. Nel gioco è rappresentato con la lettera  C
int Elements::score_up(){           
    return 200;
}

//  uguale --> DECIDERE SE DARE E TOGLIERE STESSI PUNTI
//rock    R. Il punteggio può andare anche in negativo. Nel gioco è rappresentato con la lettera R
int Elements::score_down(){         
    return 200;
}
  
void Elements::display(){
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
