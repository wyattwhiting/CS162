# Makefile for driver.cpp
CC = g++ -std=c++11
exe_file = driver
$(exe_file): Card.o Deck.o driver.o
	$(CC) Card.o Deck.o driver.o -o $(exe_file)
Card.o: Card.cpp
	$(CC) -c Card.cpp
Deck.o: Deck.cpp
	$(CC) -c Deck.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o output.* $(exe_file)


