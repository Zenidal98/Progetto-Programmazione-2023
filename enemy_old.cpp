    //devo trovare uno sprite per rappresentare i nemici
    #include enemy.h
       enemy::enemy(int x, int y, char #, int health, int damage) {           //funzione di spawn ?
        this->x = x;
        this->y = y;
        this->char = #;
        this->health = health;
        this->damage = damage;
    }
   
    void enemy::increasehealth(int plush){      //vuol dire plus health
        if(map.level%3==0){                   //da cambiare .........    //forse da togliere
           this->health++;
        }
    }

    void enemy::increasedamage(int plusd){      //plus damage
        if(map.level%3==0){                     //da cambiare .........
           this->damage++;
        }
    }
    
    
   void enemy::drop_gold(){
     int drop=0;                                      //crea un drop basato sulla vita del nemico
     if(enemy.health==1){
        drop=1;
     } else if (enemy.health==2){
        drop=2;
     } else {
        drop=3;
     }
     player.gold = player.gold + drop; 
    }

   void enemy::drop_points(){                      //da punti in base al nemico ucciso
    int points=0;
    if(enemy.health==1){                                      
        points=1;
     } else if (enemy.health==2){
        points=2;
     } else {
        points=3;
     }
     player.points = player.points + points; 
    }


    void enemy::takeDamage(int damage) {
        this->health -= damage;
        if (this->health <= 0) {
            mvaddch(y, x, ' ');                     // cancella il nemico dalla posizione attuale quando viene sconfitto
            drop_gold();
        }
    }
        int enemy::getX(){
        return this->x;
    }

    int enemy::getY(){
        return this->y;
    }

    int enemy::getHealth(){
        return this->health;
    }

    void enemy::movement(){     
        srand(time(NULL));               //imposto il seed per la generazione di numeri casuali                
        while(true){
            int direction = rand() % 2 + 1;  
            int new_x=this->x;  //ci serviranno come variabili per la prossima posizione
            
            switch(direction){
                case 1 :  //sinistra
                new_x--;
                break;

                case 2 :  //destra
                new_x++;
                break;
            }
     
       void enemy::display_enemy(){
           mvwaddch(curwin,y,x,c);
           }
                                                                 //check collisioni
                                                                 
            if (new_y >= 1 && new_y < map.y-1 && new_x >= 1 && new_x < map.x -1) {       //da cambiare
            mvwaddch(win, enemy_y, enemy_x, ' '); // Cancello il nemico dalla vecchia posizione
            enemy_y = new_y;
            enemy_x = new_x;
            mvwaddch(win, enemy_y, enemy_x, '@'); // Disegno il nemico nella nuova posizione
            wrefresh(win);
        }

        // Attendo per un breve periodo di tempo prima di eseguire un nuovo ciclo
        napms(100);
    }
}
