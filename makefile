# This needs to be done much better

CC = g++
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

DEBUG = -g
PNAME = game
INCLUDES = -Iheaders

CFLAGS = -Wall $(DEBUG)
LFLAGS = -Wall -lsfml-graphics -lsfml-window -lsfml-system $(DEBUG)

all: build

build: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PNAME)
	
clean:
	\rm *.o *~ $(PNAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

