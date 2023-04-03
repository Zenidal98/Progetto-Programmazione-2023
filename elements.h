#ifndef elements.h
#define elements.h

class elements{                     // classe usata per definire 2 buff del gioco (ciliegia, bibita) e 2 debuff (sasso, buco)
private:
   int value;

public:
   elements(int value);

   void touch();                   //funzione che si attiva sempre quando il player tocca un elemento.
   
   void health_up(value);          //bibita

   void health_down(value);        //buco

   void score_up(value);           //ciliegia

   void score_down(value);         //sasso

}

#endif elements.h
