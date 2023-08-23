Note: -Bisogna capire dove va visto che usa un sacco di attributi di classi diverse.
      -Testare se il mvprintw cosi funziona
      - Manca andare avanti dopo che si esegue azione associata a tasto
      - Ho messo dei prezzi iniziali. In futuro se vogliamo, se possiamo, ci metteremo un moltiplicatore di velocità.
#include<elements.hpp>
#include<weapons.hpp>
#include<player.hpp>
#define floor '='
void showmarket(int roomID) {
    clear();  // Cancella lo schermo


    // Le slide richiedono 3 opzioni: vita, poteri e armi
    WINDOW *healthWin = newwin(10, 20, 5, 5);  
    WINDOW *powerWin = newwin(10, 20, 5, 30); 
    WINDOW *weaponWin = newwin(10, 20, 5, 55);

    // Inizializzazione attributi da comprare:

     //Inizializzazione prezzi.
    int healthprice=0;
    int powerprice=0;
    int weaponprice=0;

    
    // Per la vita è semplice. Il player ha vita max di 100 quindi un numero casuale fra 1 e 50 va bene.
    int casualhealth=rand%(50)+10;   //cosi non ho problemi nella divisione per 10
    healthprice=healthprice*roomID;

     // Per i poteri la probabilità che appaia come nome è equivalente 
    int casualindex=rand%(3);
    char powername='.';      // Qui metto due variabili per un motivo; la prima serve a far apparire il nome a schermo. La seconda a chiamare
    char powername2='.';     // la variabile nelle funzioni dedicate nello switch finale, per questo sono solo lettere singole in power2.
    if(casualindex==0){
        powername="DamageUp";      
        powername2='d';
        powerprice=20*roomID;
    } else if (casualindex==1){
        powername="Teleport";
        powername2='t';
        powerprice=30*roomID;
    } else if (casualindex==2){
        powername="Invincibility";
        powername2='i'
        poweprice=50*roomID;
    }
    
    // La pistola appare nel 50% dei casi, il fucile nel 40% ed il lanciarazzi nel 10% dei casi.
    int casualindex2=rand%(10)
    char weaponname='.';
    char weaponname2='.'
    if((casualindex2>=0)&&(casualindex2<=4)){
        weaponname="Pistol";
        weaponname2='p';
        weaponprice=10*roomID;
    } else if ((casualindex2>=5)&&(casualindex2<=8)){
        weaponname="Firelock";
        weaponname2='f';
        weaponprice=100*roomID;
    } else if (casualindex2==9){
        weaponname="Rocket_Launcher";
        weaponname2='l';
        weaponprice=200*roomID;
    }
  

    // Mostra il relativo pulsante da premere per acquistare qualcosa che corrisponde alla iniziale in inglese
    mvwprintw(healthWin, 1, 1, "Health: " +  casualhealth + "," + healthprice + " press H ");
    mvwprintw(powerWin, 1, 1, "Power: " + powername + "," + powerprice + " press P ");
    mvwprintw(weaponWin, 1, 1, "Weapon: " + weaponname + ","+ weaponprice + " press W ");
    
    // Aggiorna le finestre
    wrefresh(healthWin);
    wrefresh(powerWin);
    wrefresh(weaponWin);
 
    // Scelta
    char ch = getch();
    switch (ch) {
        case 'h':                       // Compra la vita. Se non è al massimo la fa comprare e se è più di 100 torna a 100 (il massimo)
        if(player.coins>=healthprice){
        if(player.health<100){
              player.health=player.health+casualhealth;
              player.coins=player.coins-healthprice;

              if(player.health>100){
                    player.health=100;
              }
           }
        }
            break;
        case 'p':                       // Compra il potere se non ne ha già uno
        if(player.coins>=powerprice){
        player.coins=player.coins-powerprice;
        specialpowers::buyspecialpowers(powername2);
          
            break;
        case 'w':                       // Compra l'arma che va a sostituire il potere base del player
        if(player.coins>=weaponprice){
        player.coins=player.coins-weaponprice;
        weapons::buyweapons(weaponname2);                  
            break;
        default:
            break;
    }
}
