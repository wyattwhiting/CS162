# Makefile for main.cpp
CC = g++ -std=c++11
exe_file = main

$(exe_file): Node.o LinkedList.o main.o
	$(CC) Node.o LinkedList.o main.o -o $(exe_file)
Node.o: Node.cpp
	$(CC) -c Node.cpp
LinkedList.o: LinkedList.cpp
	$(CC) -c LinkedList.cpp

clean:
	rm -f *.out *.o $(exe_file)
