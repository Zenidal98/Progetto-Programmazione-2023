#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <ncurses.h>
#pragma once

// classe usata per definire 3 buff del gioco (ciliegia, bibita, oro) e un debuff (sasso)

class Elements{                     
    private:
        WINDOW *win;
        int x, xMax;
        int y, yMax;
        char type;

        // variabili per aggiornamento player
        int hp;
        int coins;
        int points;

    public:
        Elements(WINDOW *win, int x, int y, char type);

        int getX();

        int getY();

        //funzione che si attiva sempre quando il player tocca un elemento.
        void touch();             
   
        // d - bibita. Va messa anche nel livello market per potersi curare.
        int health_up();          

        // c - ciliegia
        int score_up();           

        // r - sasso
        int score_down();         
     
        // g - oro
        int coins_up();           
                            
        void display_element();

};   

#endif
