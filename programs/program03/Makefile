# Makefile for main.cpp
CC = g++ -std=c++11
exe_file = main
$(exe_file): Animal.o BlackBear.o SeaLion.o Tiger.o Zoo.o main.o
	$(CC) Animal.o BlackBear.o SeaLion.o Tiger.o Zoo.o main.o -o $(exe_file)
Animal.o: Animal.cpp
	$(CC) -c Animal.cpp
BlackBear.o: BlackBear.cpp
	$(CC) -c BlackBear.cpp
SeaLion.o: SeaLion.cpp
	$(CC) -c SeaLion.cpp
Tiger.o: Tiger.cpp
	$(CC) -c Tiger.cpp
Zoo.o: Zoo.cpp
	$(CC) -c Zoo.cpp

clean:
	rm -f *.out *.o $(exe_file)
