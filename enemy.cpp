    //devo trovare uno sprite per rappresentare i nemici
    #include enemy.h
       enemy::enemy(int x, int y, int speed, int health, int damage) {           //funzione di spawn ?
        this->x = x;
        this->y = y;
        this->speed = speed;
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
            int direction = rand() % 4 + 1;
            int new_y=this->y;           //ci serviranno come variabili per la prossima posizione
            int new_x=this->x;
            
            switch(direction){
                case 1:   //su
                new_y--;
                break;
                
                case 2 :   //giù
                new_y++;
                break;

                case 3 :  //sinistra
                new_x--;
                break;

                case 4 :  //destra
                new_x++;
                break;
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
