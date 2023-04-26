  #include specialpowers.h
  #include enemy.h              //serve per takedamage

specialpowers::specialpowers(int x, int y, char type){       //i tipi sono b,d,
    this->x=x;
    this->y=y;
    this->type=type;
}

void touch(){
    if((player.x==specialpowers.x)&&(player.y==specialpowers.y)){
        if(specialpowers.char=='b'){                               //check sul tipo di collezionabile raccolto
            specialpowers::bomb(); 
        } else if(specialpowers.char=='d'){
            specialpowers::damageup();
        }
        mvaddch(WINDOW*map,y,x,' ');             //libero quel pezzetto. Forse non basta o crea problemi, da tenere in considerazione
    }

void specialpowers::bomb(){
    for //each enemy in a room
        {                                        //fa come takedamage ma con un danno altissimo, in modo da ucciderli tutti sicuro 
         takedamage(10000000);
    }
}

void specialpowers::damageup(){
    player.bonusdamage=player.bonusdamage*1,5;  //aumenta il danno bonus del player. Questo sommato al danno arma è il danno totale.
}
