#include "Weapons.hpp"
     Weapons::Weapons(int cost, int plus, char type){     //similmente agli elementi a schermo, o fatto 3 tipi di armi
        this->cost=cost;
        this->plus=plus;
        this->type=type;
     }

void Weapons::buyweapons(Player *p, char type){
    if(p->gold >= this->cost){                    //se si ha abbastanza gold si può comprare
        if(this->type=='p'){                          //comprare la pistola
          p->basedamage=5;
        } else if(this->type=='f'){                   //comprare il fucile
          p->basedamage=10;
        } else if(this->type=='l'){                   //comprare il lanciarazzi
          p->basedamage=20;
        }                  
    }
}
