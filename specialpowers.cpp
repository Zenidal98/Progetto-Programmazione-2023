  #include "specialpowers.h"
  #include "enemy.h"            //serve per takedamage
  #include "Logics.h"
specialpowers::specialpowers(int cost, char type){       //i tipi sono d,t,i
    this->cost=cost
    this->type=type;
}

void specialpowers::buyspecialpowers(char type){
    if(player.gold >= this->cost){                    //se si ha abbastanza gold si può comprare
        if(this->type=='d'){                          //comprare la pistola
          player.sp='d';
        } else if(this->type=='t'){                   //comprare il fucile
          player.sp='t';
        } else if(this->type=='i'){                   //comprare il lanciarazzi
          player.sp='i';
        }                  
    }
}

void poweractivation(){                          //funzione che attiva gli specialpowers. Forse va messa nel main e basta.
	if (wgetch(curwin)=='x'){
		if (player.sp='d'){
        	specialpowers::damageup();
		}
        	if (player.sp='t'){ 
        	specialpowers::teleport();
		}
        	if (player.sp='i'){
        	specialpowers::invincible();
		}
	}
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

void specialpowers::invincible(){                //Idea: salvo gli hp che ho al momento di invincible e l'id della stanza
              //dell'attivazione del potere. Probabile errore su roomID. 
//	while(invincibleroomID==roomID){
//            player.hp=invinciblehp;
//	}
	inv = true;
	Logics::invPower();
}
       
 
bool inv = false;

  
