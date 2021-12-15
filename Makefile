CC=g++
CFLAGS=-Wall -std=c++17 -O0
OUTFILE=cg
DEPS=tbm.h
SOURCE=main.cpp tbm.cpp
OBJ=main.o tbm.o

all: cg

cg: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(OUTFILE)

tbm.o: tbm.cpp $(DEPS)
	$(CC) $(CFLAGS) -c tbm.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(OUTFILE)
