#ifndef elements.h
#define elements.h

class elements{                     // classe usata per definire 2 buff del gioco (ciliegia, bibita) e 2 debuff (sasso, buco)
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
       
                             //manca un'ultima funzione per evitare che i buff/debuff spawnino sui bordi della finestra o sulle piattaforme. O forse non serve ?
   void elements_display();

}

#endif elements.h
