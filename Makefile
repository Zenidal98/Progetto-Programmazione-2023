CC = g++

CFLAGS = -std=c++11 -g -Wall -Wextra

LIBS = -lncurses

NOMEGIOCO: maintest.o Logics.o Bullet.o Elements.o Enemy.o market.o player.o room.o specialpowers.o weapons.o
	g++ maintest.o Logics.o Bullet.o Elements.o Enemy.o market.o player.o room.o specialpowers.o weapons.o -o NOMEGIOCO

maintest.o: maintest.cpp
	g++ -c maintest.cpp

Logics.o: Logics.cpp
	g++ -c Logics.cpp

Bullet.o: Bullet.cpp
	g++ -c Bullet.cpp

Elements.o: Elements.cpp
	g++ -c Elements.cpp

Enemy.o: Enemy.cpp
	g++ -c Enemy.cpp
	
market.o: market.cpp
	g++ -c market.cpp
	
player.o: player.cpp
	g++ -c market.cpp

room.o: room.cpp
	g++ -c room.cpp

specialpowers.o: specialpowers.cpp
	g++ -c specialpowers.cpp

weapons.o: weapons.cpp
	g++ -c weapons.cpp
	
clean: rm *.o NOMEGIOCO
