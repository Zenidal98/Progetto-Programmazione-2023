#ifndef specialpowers.hpp
#define specialpowers.hpp

class specialpowers{                // classe usata per definire i poteri speciali del player, il quale può comprarne uno nel market, può
                                    // tenerne solo uno e può attivarlo con un tasto dedicato ossia 'x'.
private:
   int x;
   int y;
   char type;

public:
   specialpowers(int x, int y, char type);

   void touch();                   //funzione che si attiva sempre quando il player tocca un elemento.

   void poweractivation();         //serve a dare l'effetto desiderato quando si preme 'x'. Si potrebbe togliere e mettere nel main ?

   void damageup();                //aumenta il danno bonus

   void damagedown();              //funzione che riporta il danno a prima di damageup. Serve per riportare le cose alla normalità dopo il bonus

   void teleport();                //teletrasporta in un'altra stanza

   void invincible();              //invulnerabilità per una stanza, il più raro   

   void buyspecialpowers(char type);
}

#endif specialpowers.h
