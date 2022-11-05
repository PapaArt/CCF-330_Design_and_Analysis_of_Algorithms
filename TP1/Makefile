APP = ./app
DIST = ./dist
HEADERS = ./headers
OBJ = ./obj
SRC = ./src
TEST = ./test

all: libed
	gcc $(APP)/main.c $(OBJ)/menu.o $(OBJ)/map.o -o ./dist/main

libed:
	gcc -c $(SRC)/map.c -I $(HEADERS) -o $(OBJ)/map.o
	gcc -c $(SRC)/menu.c -I $(HEADERS) -o $(OBJ)/menu.o
	gcc -c $(SRC)/fibonnaci.c -I $(HEADERS) -o $(OBJ)/fibonnaci.o

testFib: libed
	gcc $(TEST)/testFib.c $(OBJ)/fibonnaci.o -I $(HEADERS) -o $(DIST)/testFib
	$(DIST)/testFib

clean:
	rm $(DIST)/* $(OBJ)/*