  #include "specialpowers.hpp"
  #include "enemy.hpp"            //serve per takedamage
  #include "logics.hpp"
  #include "player.hpp"
Specialpowers::Specialpowers(int cost, char type){       //i tipi sono d,t,i
    this->cost=cost
    this->type=type;
}

void Specialpowers::buyspecialpowers(char type){
    if(Player::coins >= this->cost){                    //se si ha abbastanza gold si può comprare
        if(this->type=='d'){                          //comprare la pistola
          Player::specialpower='d';
        } else if(this->type=='t'){                   //comprare il fucile
          Player::specialpower='t';
        } else if(this->type=='i'){                   //comprare il lanciarazzi
          Player::specialpower='i';
        }                  
    }
}

void Specialpowers::poweractivation(){                          //funzione che attiva gli specialpowers. Forse va messa nel main e basta.
	if (wgetch(curwin)=='x'){
		if (Player::specialpower='d'){
        	Specialpowers::damageup();
		}
        	if (Player::sp='t'){ 
        	Specialpowers::teleport();
		}
        	if (Player::sp='i'){
        	Specialpowers::invincible();
		}
	}
}

void Specialpowers::damageup(){
    Player::plusDamage=Player::plusDamage*1,5;  //aumenta il danno bonus del player. Questo sommato al danno arma è il danno totale.
      }

void Specialpowers::damagedown(){                //legata a damagedown
    Player::plusDamage=Player::plusDamage/1,5;
      }

void Specialpowers::teleport(){                   //teletrasporta il giocatore in una nuova stanza
	Logics::teleportpower();
}

void Specialpowers::invincible(){                //Idea: salvo gli hp che ho al momento di invincible e l'id della stanza
              //dell'attivazione del potere. Probabile errore su roomID. 
//	while(invincibleroomID==roomID){
//            player.hp=invinciblehp;
//	}
	
	Logics::isInvincible = true;
}
       
 


  
