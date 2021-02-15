# Makefile for main.cpp
CC = g++ -std=c++11
exe_file = main
$(exe_file): Heading.o main.o
	$(CC) Heading.o main.o -o $(exe_file)
Card.o: Heading.cpp
	$(CC) -c Heading.cpp
clean:
	rm -f *.out *.o output.* $(exe_file)


