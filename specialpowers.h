#ifndef specialpowers.h
#define specialpowers.h

class specialpowers{                     // classe usata per definire poteri speciali. Il player può comprarne uno nel market, può
                                         // tenerne solo uno e può attivarlo con un tasto dedicato.
private:
   int x;
   int y;
   char type;

public:
   specialpowers(int x, int y, char type);

   void touch();                   //funzione che si attiva sempre quando il player tocca un elemento.
   
   void bomb();                    //uccide tutti i nemici in una stanza

   void damageup();                //aumenta il danno bonus

   void damagedown();              //funzione che riporta il danno a prima di damageup. Serve per riportare le cose alla normalità dopo il bonus

   void invincible();              //invulnerabilità per una stanza, il più raro        
}

#endif specialpowers.h
