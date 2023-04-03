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

int elements::health_up(int value){           //drink
    player.hp = player.hp + value;
}

int elements::health_down(int value){        //hole
    player.hp = player.hp - value;
}

int elements::score_up(int value){           //cherry
    player.hp = player.score + value;
}

int elements::score_down(int value){         //rock
    player.hp = player.score - value;
}
