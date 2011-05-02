# This needs to be done much better

PWD = $(shell pwd)

CC = g++
OBJS = $(patsubst %.cpp,%.o,$(wildcard **/*.cpp *.cpp))

DEBUG = -g
PNAME = game
INCLUDES = -I$(PWD)/headers

CFLAGS = -Wall $(DEBUG)
LFLAGS = -Wall -lsfml-graphics -lsfml-window -lsfml-system $(DEBUG)

all: build

build: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PNAME)
	
clean:
	\rm *.o *~ $(PNAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

