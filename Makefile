TARGET  = juegovida

# Select Compiler and flags
CC=g++
CFLAGS=-std=c++14 -g -Wall   # Compiler options (C++14, preserve debug symbols and warn all)


SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

# Special include directories
INCLUDE = -I.

# Special libraries (none for now)
LIB =

$(TARGET): main.o Cell.o Grid.o
	$(CC) -o $@ $^ $(LIB)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

Cell.o: Cell.cpp Cell.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

Grid.o: Grid.cpp Grid.h State.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
	rm -f *~