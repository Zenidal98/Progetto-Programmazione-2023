  #include elements.h         //servono 4 sprite

elements::elements(int value){
    this->value=value;
}



int elements::health_up(int value){
    player.hp = player.hp + value;
}

int elements::health_down(int value){
    player.hp = player.hp - value;
}

int elements::score_up(int value){
    player.hp = player.score + value;
}

int elements::score_down(int value){
    player.hp = player.score - value;
}
