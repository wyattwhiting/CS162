# Makefile for main.cpp
# Author: Wyatt Whiting
# Date: 2020-10-09
CC = g++ -std=c++11
exe_file = main
$(exe_file): helper.o main.o
	$(CC) helper.o main.o -o $(exe_file)
helper.o: helper.cpp
	$(CC) -c helper.cpp
main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.out *.o output.* $(exe_file)