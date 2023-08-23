#include weapons.hpp
     weapons::weapons(int cost, int plus, char type){     //similmente agli elementi a schermo, o fatto 3 tipi di armi
        this->cost=cost;
        this->plus=plus;
        this->type=type;
     }

void weapons::buyweapons(char type){
    if(player.gold >= this->cost){                    //se si ha abbastanza gold si può comprare
        if(this->type=='p'){                          //comprare la pistola
          player.basedamage=5;
        } else if(this->type=='f'){                   //comprare il fucile
          player.basedamage=10;
        } else if(this->type=='l'){                   //comprare il lanciarazzi
          player.basedamage=20;
        }                  
    }
}
