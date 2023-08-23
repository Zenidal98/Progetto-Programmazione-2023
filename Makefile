Un Makefile è un file di configurazione utilizzato per automatizzare il processo di compilazione e creazione di progetti software. È particolarmente utile quando un progetto diventa più complesso e coinvolge più file sorgente, librerie esterne e altre risorse. In sostanza, un Makefile definisce le regole e le dipendenze per generare l'eseguibile o le librerie desiderate.

Ecco come puoi creare un Makefile per il tuo progetto C++ utilizzando le librerie ncurses e curses:

Apri un editor di testo o un IDE e crea un nuovo file di testo vuoto chiamato "Makefile" (senza estensione).

Inserisci le regole nel file Makefile seguendo la sintassi specifica. Ogni regola è composta da un target, le dipendenze e i comandi per compilarle. Ecco un esempio di Makefile semplificato:
////////////
make 

CC = g++

CPPFLAGS = -std=c++11 -g -Wall -Wextra

LIBS = -lncurses

NOMEGIOCO: maintest.o Logics.o bullet.o elements.o enemy.o gravity.o market.o player.o room.o specialpowers.o weapons.o
g++ ${CPPFLAGS} -o ${NOMEGIOCO} main.o menu.o controller.o box.o initNcurses.o map.o collision.o enemy.o shot.o pippo.o ${LDFLAGS}

bullet.o: bullet.cpp bullet.hpp enemy.hpp
g++ ${CPPFLAGS} -c bullet.cpp

elements.o: elements.cpp elements.hpp
g++ ${CPPFLAGS} -c elements.cpp

enemy.o: enemy.cpp enemy.hpp
g++ ${CPPFLAGS} -c enemy.cpp

gravity.o: gravity.cpp gravity.hpp
g++ ${CPPFLAGS} -c gravity.cpp

Logics.o: Logics.cpp Logics.hpp player.hpp enemy.hpp elements.hpp bullet.hpp
g++ ${CPPFLAGS} -c Logics.cpp

maintest.o: maintest.cpp player.hpp room.hpp enemy.hpp bullet.hpp elements.hpp specialpowers.hpp weapons.hpp
g++ ${CPPFLAGS} -c maintest.cpp

market.o: market.cpp market.hpp elements.hpp weapons.hpp player.hpp
g++ ${CPPFLAGS} -c market.cpp

player.o: player.cpp player.hpp
g++ ${CPPFLAGS} -c player.cpp

room.o: room.cpp room.hpp
g++ ${CPPFLAGS} -c room.cpp

specialpowers.o: specialpowers.cpp specialpowers.hpp enemy.hpp Logics.hpp
g++ ${CPPFLAGS} -c specialpowers.cpp

weapons.o: weapons.cpp weapons.hpp 
g++ ${CPPFLAGS} -c weapons.cpp

clean: rm *.o $(NOMEGIOCO)

//////////////////////////////////////
Nel Makefile sopra, sostituisci nome_del_tuo_programma con il nome desiderato per il tuo eseguibile e assicurati di elencare tutti i file sorgente nella variabile SRCS.

Modifica eventuali opzioni di compilazione o librerie necessarie secondo le tue esigenze.

Salva il file Makefile.

Apri una finestra del terminale nella stessa directory in cui si trova il Makefile e esegui i seguenti comandi:

make: Compila il programma. Verrà creato l'eseguibile con il nome specificato.
make clean: Rimuove i file oggetto e l'eseguibile generato.
Ricorda di sostituire i nomi dei file e le opzioni di compilazione secondo le tue esigenze. Un Makefile ben configurato semplifica notevolmente il processo di compilazione e manutenzione del tuo progetto C++ con ncurses e curses.
