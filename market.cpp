/*
Note: -Bisogna capire dove va visto che usa un sacco di attributi di classi diverse.
      -Testare se il mvprintw cosi funziona
      - Manca andare avanti dopo che si esegue azione associata a tasto
      - Ho messo dei prezzi iniziali. In futuro se vogliamo, se possiamo, ci metteremo un moltiplicatore di velocità.
*/
#include "Elements.hpp"
#include "Weapons.hpp"
#include "Player.hpp"
#include<cstdlib>
#define floor '='
void showmarket(int roomID) {
    clear();  // Cancella lo schermo


    // Le slide richiedono 3 opzioni: vita, poteri e armi
    WINDOW *healthWin = newwin(10, 20, 5, 5);  
    WINDOW *powerWin = newwin(10, 20, 5, 30); 
    WINDOW *weaponWin = newwin(10, 20, 5, 55);

    // Inizializzazione attributi da comprare:

     //Inizializzazione prezzi.
    int healthPrice=0;
    int powerPrice=0;
    int weaponPrice=0;

    
    // Per la vita è semplice. Il player ha vita max di 100 quindi un numero casuale fra 1 e 50 va bene.
    int casualHealth=rand()%(50)+10;   //cosi non ho problemi nella divisione per 10
    healthPrice=healthPrice*roomID;

     // Per i poteri la probabilità che appaia come nome è equivalente 
    int casualIndex=rand()%(3);
    char powerName='.';      // Qui metto due variabili per un motivo; la prima serve a far apparire il nome a schermo. La seconda a chiamare
    char powerName2='.';     // la variabile nelle funzioni dedicate nello switch finale, per questo sono solo lettere singole in power2.
    if(casualIndex==0){
        powerName="DamageUp";
        powerName2='d';
        powerPrice=20*roomID;
    } else if (casualIndex==1){
        powerName="Teleport";
        powerName2='t';
        powerPrice=30*roomID;
    } else if (casualIndex==2){
        powerName="Invincibility";
        powerName2='i';
        powerPrice=50*roomID;
    }

    // La pistola appare nel 50% dei casi, il fucile nel 40% ed il lanciarazzi nel 10% dei casi.
    int casualIndex2=rand()%(10)
    char weaponName='.';
    char weaponName2='.';
    if((casualindex2>=0)&&(casualindex2<=4)){
        weaponName="Pistol";
        weaponName2='p';
        weaponPrice=10*roomID;
    } else if ((casualindex2>=5)&&(casualindex2<=8)){
        weaponName="Firelock";
        weaponName2='f';
        weaponPrice=100*roomID;
    } else if (casualindex2==9){
        weaponName="Rocket_Launcher";
        weaponName2='l';
        weaponPrice=200*roomID;
    }
  

    // Mostra il relativo pulsante da premere per acquistare qualcosa che corrisponde alla iniziale in inglese
    mvwprintw(healthWin, 1, 1, "Health: " +  casualHealth + "," + healthPrice + " press H ");
    mvwprintw(powerWin, 1, 1, "Power: " + powerName + "," + powerPrice + " press P ");
    mvwprintw(weaponWin, 1, 1, "Weapon: " + weaponName + ","+ weaponPrice + " press W ");
    
    // Aggiorna le finestre
    wrefresh(healthWin);
    wrefresh(powerWin);
    wrefresh(weaponWin);
 
    // Scelta
    char ch = getch();
    switch (ch) {
        case 'h':                       // Compra la vita. Se non è al massimo la fa comprare e se è più di 100 torna a 100 (il massimo)
        if(Player->coins>=healthPrice){
        if(Player->health<100){
              Player->health=Player->health+casualHealth;
              Player->coins=Player->coins-healthPrice;

              if(Player->health>100){
                    Player->health=100;
              }
           }
        }
            break;
        case 'p':                       // Compra il potere se non ne ha già uno
        if(Player->coins>=powerPrice){
        Player->coins=Player->coins-powerPrice;
        specialpowers::buyspecialpowers(powerName2);
        }
            break;
        case 'w':                       // Compra l'arma che va a sostituire il potere base del player
        if(Player->coins>=weaponPrice){
        Player->coins=Player->coins-weaponPrice;
        weapons::buyweapons(weaponName2);
            break;
        }
        default:
            break;
    }

