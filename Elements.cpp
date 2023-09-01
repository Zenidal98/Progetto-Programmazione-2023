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

void Elements::touch(){
    /* Non saprei come far funzionare di qua touch    
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
<<<<<<< HEAD
    */
    //libero quel pezzetto. Forse non basta o crea problemi, da tenere in considerazione
    // mvaddch(WINDOW*map,y,x,' ');            
    
    //}
=======
    mvaddch(WINDOW*map,y,x,' ');            
>>>>>>> 228f6f1823ad99af3e28ded9a8f4e5c9875e057c
}


// NON SI PUO' FARE QUI per Player --> creare una variabile che ritorna vita da aggiungere?
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
