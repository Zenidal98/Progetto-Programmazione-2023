#ifndef SPECIALPOWERS_HPP
#define SPECIALPOWERS_HPP
#include "Player.hpp"

class Specialpowers{                // classe usata per definire i poteri speciali del player, il quale può comprarne uno nel market, può
                                    // tenerne solo uno e può attivarlo con un tasto dedicato ossia 'x'.
private:
   int cost;
   char type;

public:
   Specialpowers(int cost, char type);

   void touch();                   //funzione che si attiva sempre quando il player tocca un elemento.

   void poweractivation(WINDOW *curwin, Player *p);         //serve a dare l'effetto desiderato quando si preme 'x'. Si potrebbe togliere e mettere nel main ?

   void damageup(Player *p);                //aumenta il danno bonus

   void damagedown(Player *p);              //funzione che riporta il danno a prima di damageup. Serve per riportare le cose alla normalità dopo il bonus

   void fullhealth(Player *p);           //riporta la vita al massimo

   void teleport();                //teletrasporta in un'altra stanza

   void invincible();              //invulnerabilità per una stanza, il più raro   

   void buyspecialpowers(Player *p, char type);
};

#endif 
