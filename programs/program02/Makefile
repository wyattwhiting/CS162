# Makefile for main.cpp
CC = g++ -std=c++11
exe_file = main
$(exe_file): Card.o Deck.o Hand.o Player.o Game.o main.o
	$(CC) Card.o Deck.o Hand.o Player.o Game.o main.o -o $(exe_file)
Card.o: Card.cpp
	$(CC) -c Card.cpp
Deck.o: Deck.cpp
	$(CC) -c Deck.cpp
Hand.o: Hand.cpp
	$(CC) -c Hand.cpp
Player.o: Player.cpp
	$(CC) -c Player.cpp
Game.o: Game.cpp
	$(CC) -c Game.cpp

clean:
	rm -f *.out *.o output.* $(exe_file)


