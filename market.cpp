void showmarket() {
    clear();  // Cancella lo schermo
  
    // Le slide richiedono 3 opzioni: vita, poteri e armi
    WINDOW *healthWin = newwin(10, 20, 5, 5);  
    WINDOW *powerWin = newwin(10, 20, 5, 30); 
    WINDOW *weaponWin = newwin(10, 20, 5, 55);

    // Inizializzazione attributi da comprare:
    int casualhealth=rand%(10);
    
  
    // Mostra il relativo pulsante da premere per acquistare qualcosa che corrisponde alla iniziale in inglese
    mvwprintw(healthWin, 1, 1, "Health: " casualhealth );
    mvwprintw(powerWin, 1, 1, "Power: " casualpower);
    mvwprintw(weaponWin, 1, 1, "Weapon: " casualweapon);
    
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
