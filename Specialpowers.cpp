  #include "Specialpowers.hpp"
  #include "Enemy.hpp"            //serve per takedamage
  #include "Logics.hpp"
Specialpowers::Specialpowers(int cost, char type){       //i tipi sono d,t,i
    this->cost=cost;
    this->type=type;
}

void Specialpowers::buyspecialpowers(Player *p, char type){
    if(p->coins >= this->cost){                    //se si ha abbastanza gold si può comprare
        if(this->type=='d'){                          //comprare la pistola
          p->specialpower='d';
        } else if(this->type=='t'){                   //comprare il fucile
          p->specialpower='t';
        } else if(this->type=='i'){                   //comprare il lanciarazzi
          p->specialpower='i';
        }                  
    }
}

void Specialpowers::poweractivation(WINDOW *curwin, Player *p){                          //funzione che attiva gli specialpowers. Forse va messa nel main e basta.
	if (wgetch(curwin)=='x'){
		if (p->specialpower='d'){
        		damageup(p);
		}
        	if (p->specialpower='t'){ 
        		teleport();
		}
        	if (p->specialpower='i'){
        		invincible();
		}
	}
}

void Specialpowers::damageup(Player *p){
    p->plusDamage=p->plusDamage*1,5;  //aumenta il danno bonus del player. Questo sommato al danno arma è il danno totale.
}

void Specialpowers::damagedown(Player *p){                //legata a damagedown
    p->plusDamage=p->plusDamage/1,5;
}
/*
void Specialpowers::teleport(){                   //teletrasporta il giocatore in una nuova stanza
	Logics::teleportpower();
}
*/
void Specialpowers::invincible(){                //Idea: salvo gli hp che ho al momento di invincible e l'id della stanza
              //dell'attivazione del potere. Probabile errore su roomID. 
//	while(invincibleroomID==roomID){
//            player.hp=invinciblehp;
//	}
	
	Logics::isInvincible = true;
}
       
 


  
