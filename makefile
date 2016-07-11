# Sarah Walter's makefile
# To use: 
# make all = Make software.
#
# make clean = Clean out built project files.

CC = g++
RM = rm
DEBUG = -g
CFLAGS = $(DEBUG) -std=c++0x
RMFLAGS = -rf 
PROGS = simulation
MAKEFLAGS = -k

	
all: $(PROGS)
	
simulation:
	$(CC) $(CFLAGS) Ant.cpp Critter.cpp Doodlebug.cpp Grid.cpp main.cpp -o simulation
		
clean:
	$(RM) $(RMFLAGS) *.a *.o $(PROGS)