  #include elements.h         

elements::elements(int x, int y, char type){       //i tipi sono d, c, r, ossia drink, cherry, rock
    this->x=x;
    this->y=y;
    this->type=type;
}

void touch(){
    if((player.x==elements.x)&&(player.y==elements.y)){
        if(elements.char=='d'){                               //check sul tipo di collezionabile raccolto
            elements::health_up(value); 
        } else if(elements.char=='c'){
            elements::score_up(value)
        } else if(elements.char=='r'){
            elements::score_down(value);
        }
        mvaddch(WINDOW*map,y,x,' ');             //libero quel pezzetto. Forse non basta o crea problemi, da tenere in considerazione
    }

void elements::health_up(){   //drink. Questo va messo anche nel market.  Nel gioco è rappresentato con la lettera  D
  if(player.hp<//max){
    player.hp = player.hp + 1;
     }
}


void elements::score_up(){           //cherry. Nel gioco è rappresentato con la lettera  C
    player.score = player.score + 200 ;
}

void elements::score_down(){         //rock    R. Il punteggio può andare anche in negativo. Nel gioco è rappresentato con la lettera R.
    player.score = player.score - 200;
}
  
void elements::display(){
  if(elements.type=='c'){
  mvwaddch(curwin,y,x,'C')
    }
   else if(elements.type=='r'){
  mvwaddch(curwin,y,x,'R')
     }
   else if(elements.type=='d'){
  mvwaddch(curwin,y,x,'D')
     }
}
