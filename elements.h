#ifndef elements.h
#define elements.h

class elements{                     // classe usata per definire 3 buff del gioco (ciliegia, bibita, oro) e un debuff (sasso)
private:
   int x;
   int y;
   char type;

public:
   elements(int x, int y, char type);

   void touch();             //funzione che si attiva sempre quando il player tocca un elemento.
   
   void health_up();          //bibita. Va messa anche nel livello market per potersi curare.

   void score_up();           //ciliegia

   void score_down();         //sasso
     
   void coins_up();           //oro
                            
   void elements_display();

}

#endif elements.h
