# Makefile for driver.cpp
CC = g++
exe_file = driver
$(exe_file): student_db.o driver.o
	$(CC) student_db.o driver.o -o $(exe_file)
mult_div.o: student_db.cpp
	$(CC) -c student_db.cpp
prog.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o output.* $(exe_file)


