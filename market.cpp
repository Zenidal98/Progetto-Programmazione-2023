Note: -Bisogna capire dove va visto che usa un sacco di attributi di classi diverse.
      -Testare se il mvprintw cosi funziona

void showmarket() {
    clear();  // Cancella lo schermo
  
    // Le slide richiedono 3 opzioni: vita, poteri e armi
    WINDOW *healthWin = newwin(10, 20, 5, 5);  
    WINDOW *powerWin = newwin(10, 20, 5, 30); 
    WINDOW *weaponWin = newwin(10, 20, 5, 55);

    // Inizializzazione attributi da comprare:

    // Per la vita è semplice. Il player ha vita max di 100 quindi un numero casuale fra 1 e 50 va bene.
    int casualhealth=rand%(50)+1;

     // Per i poteri la probabilità è equivalente quindi torna ad essere un pò più semplice
    int casualindex=rand%(3);
    char powername='.';
    if(casualindex==0){
        powername="Bomb";      
    } else if (casualindex==1){
        powername="DamageUp";    
    } else if (casualindex==2){
        powername="........";   
    }
    
    // Per le armi è leggermente più complicato. Ho messo che nel market la pistola appare nel 50% dei casi, il fucile nel 25% ed il
    // lanciarazzi nel 10% dei casi essendo il più forte.
    char weapons

    // Mostra il relativo pulsante da premere per acquistare qualcosa che corrisponde alla iniziale in inglese
    mvwprintw(healthWin, 1, 1, "Health: " casualhealth " H ");
    mvwprintw(powerWin, 1, 1, "Power: " powername " P ");
    mvwprintw(weaponWin, 1, 1, "Weapon: " casualweapon " W ");
    
    // Aggiorna le finestre
    wrefresh(healthWin);
    wrefresh(powerWin);
    wrefresh(weaponWin);
 
    // Scelta
    char ch = getch();
    switch (ch) {
        case 'h':                       // Compra la vita. Se non è al massimo la fa comprare altrimenti niente.
   
          
            break;
        case 'p':                       // Compra il potere se non ne ha già uno.

          
            break;
        case 'w':                       // Compra l'arma che va a sostituire il potere base del player
                               
           
            break;
        default:
            break;
    }
}
