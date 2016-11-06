CC=g++
CFLAGS=-Wall -o

LSRCS=LinkedList.hpp LinkedList.cpp 
HSRCS=HashTable.hpp HashTable.cpp

all:LLobject prog

LLobject:$(LSRCS)
	g++ -c $(LSRCS)

prog: $(HSRCS) LinkedList.o
	$(CC) $(CFLAGS) prog $(HSRCS) LinkedList.o

