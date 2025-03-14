CFLAGS= -std=c++11 -Wall

all: eVTOL_Sim

eVTOL_Sim: eVTOL_Sim.cpp
	g++ $(CFLAGS) -o run eVTOL_Sim.cpp

.PHONY: all clean