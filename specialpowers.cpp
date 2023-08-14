  #include "specialpowers.h"
  #include "enemy.h"            //serve per takedamage
  #include "Logics.h"
specialpowers::specialpowers(int x, int y, char type){       //i tipi sono d,t,i
    this->x=x;
    this->y=y;
    this->type=type;
}

void touch(){
    if((player.x==specialpowers.x)&&(player.y==specialpowers.y)){
        if(specialpowers.char=='d'){                               //il potere va nello slot carattere singolo di player
            player.sp='d';
        } else if(specialpowers.char=='t'){
            player.sp='t'
        } else if(specialpowers.char=='i'){
            player.sp='i';
        }
        mvaddch(WINDOW*map,y,x,' ');             //libero quel pezzetto. Forse non basta o crea problemi, da tenere in considerazione
    }

void poweractivation(){                          //funzione che attiva gli specialpowers. Forse va messa nel main e basta.
     char getinput = getch();
     if (getinput=='x'){
         if (player.sp='d'){
         specialpowers::damageup();
	 }
         if (player.sp='t'){ 
         specialpowers::teleport();
	 }
         if (player.sp='i'){
         specialpowers::invincible();
	 }


void specialpowers::damageup(){
    player.bonusdamage=player.bonusdamage*1,5;  //aumenta il danno bonus del player. Questo sommato al danno arma è il danno totale.
      }

void specialpowers::damagedown(){                //legata a damagedown
    player.bonusdamage=player.bonusdamage/1,5;
      }

void specialpowers::teleport(){                   //teletrasporta il giocatore in una nuova stanza
	Logics::teleportpower();
}

void specialpowers::invincible(){
       //check sulla stanza
	if(isinvincible==true){
            player.hp=
       
       
       
	

 

    

