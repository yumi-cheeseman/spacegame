# This needs to be done much better
# Use: **/*.o for any depth using GNUMake 3.81+
OBJS = *.o #*/*.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -Iincludes
LFLAGS = -Wall -lsfml-graphics -lsfml-window -lsfml-system $(DEBUG)
PNAME = game

all: build

build: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PNAME)
	
clean:
	\rm *.o *~ $(PNAME)

.cpp:
	$(CC) $(CFLAGS) -c $(.SOURCE)

