CC = g++

CFLAGS = -std=c++11 -g -Wall -Wextra

LIBS = -lncurses

NOMEGIOCO: maintest.o Logics.o Bullet.o Elements.o Enemy.o Player.o Room.o Specialpowers.o Weapons.o
	g++ maintest.o Logics.o Bullet.o Elements.o Enemy.o Player.o Room.o Specialpowers.o Weapons.o -o NOMEGIOCO $(LIBS)

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

Player.o: Player.cpp
	g++ -c Player.cpp

Room.o: Room.cpp
	g++ -c Room.cpp

Specialpowers.o: Specialpowers.cpp
	g++ -c Specialpowers.cpp

Weapons.o: Weapons.cpp
	g++ -c Weapons.cpp

clean: rm *.o NOMEGIOCO
