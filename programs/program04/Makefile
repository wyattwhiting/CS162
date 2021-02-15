# Makefile for main.cpp
CC = g++ -std=c++11
exe_file = main

$(exe_file): Event.o Bats.o Gold.o Pit.o Wumpus.o Room.o Game.o main.o
	$(CC) Event.o Bats.o Gold.o Pit.o Wumpus.o Room.o Game.o main.o -o $(exe_file)
Event.o: Event.cpp
	$(CC) -c Event.cpp
Bats.o: Bats.cpp
	$(CC) -c Bats.cpp
Gold.o: Gold.cpp
	$(CC) -c Gold.cpp
Pit.o: Pit.cpp
	$(CC) -c Pit.cpp
Wumpus.o: Wumpus.cpp
	$(CC) -c Wumpus.cpp
Room.o: Room.cpp
	$(CC) -c Room.cpp
Game.o: Game.cpp
	$(CC) -c Game.cpp

clean:
	rm -f *.out *.o $(exe_file)
