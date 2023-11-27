#include "Weapons.hpp"
     Weapons::Weapons(int cost, char type){     //similmente agli elementi a schermo, ho fatto 3 tipi di armi
        this->cost=cost;
        this->type=type;
     }

void Weapons::buyweapons(Player *p, char type){
    if(p->coins >= this->cost){                    //se si ha abbastanza gold si può comprare
        if(this->type=='p'){                          //comprare la pistola
          p->baseDamage=5;
        } else if(this->type=='f'){                   //comprare il fucile
          p->baseDamage=10;
        } else if(this->type=='l'){                   //comprare il lanciarazzi
          p->baseDamage=20;
        }                  
    }
}
