CC=g++

program: print.o main.o iof.o coins.o
	$(CC) -o program print.o main.o iof.o coins.o

print.o: print.h print.cpp
	$(CC) -c print.h print.cpp

iof.o: iof.h iof.cpp
	$(CC) -c iof.h iof.cpp

coins.o: coins.h coins.cpp
	$(CC) -c coins.h coins.cpp

main.o: main.h main.cpp
	$(CC) -c main.h main.cpp

clean:
	DEL *.o
	DEL *.h.gch