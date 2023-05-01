  #include elements.h         //servono 4 sprite

elements::elements(int value, int x, int y, char type){       //i tipi sono d, h, c, r, ossia drink,hole,cherry,rock
    this->value=value;
    this->x=x;
    this->y=y;
    this->type=type;
}

void touch(){
    if((player.x==elements.x)&&(player.y==elements.y)){
        if(elements.char=='d'){                               //check sul tipo di collezionabile raccolto
            elements::health_up(value); 
        } else if(elements.char=='h'){
            elements::health_down(value);
        } else if(elements.char=='c'){
            elements::score_up(value)
        } else if(elements.char=='r'){
            elements::score_down(value);
        }
        mvaddch(WINDOW*map,y,x,' ');             //libero quel pezzetto. Forse non basta o crea problemi, da tenere in considerazione
    }

void elements::health_up(int value){           //drink. Questo va messo anche nel market.    D
    player.hp = player.hp + value;
}

void elements::health_down(int value){        //hole    H
    player.hp = player.hp - value;
}

void elements::score_up(int value){           //cherry   C
    player.hp = player.score + value;
}

void elements::score_down(int value){         //rock    R. Il punteggio può andare anche in negativo
    player.hp = player.score - value;
}
  
void elements::display(){
  if(elements.type=='c'){
  mvwaddch(curwin,y,x,'C')
    }
   else if(elements.type=='r'){
  mvwaddch(curwin,y,x,'R')
     }
   else if(elements.type=='h'){
  mvwaddch(curwin,y,x,'H')
     }
   else if(elements.type=='d'){
  mvwaddch(curwin,y,x,'D')
     }
}
