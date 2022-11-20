DIST = ./dist
HEADERS = ./headers
OBJ = ./obj
SRC = ./src
TEST = ./test

all: libed
	gcc $(SRC)/main.c $(OBJ)/menu.o $(OBJ)/map.o $(OBJ)/fibonnaci.o -o ./dist/main
	$(DIST)/main

libed:
	gcc -c $(SRC)/map.c -I $(HEADERS) -o $(OBJ)/map.o
	gcc -c $(SRC)/menu.c -I $(HEADERS) -o $(OBJ)/menu.o
	gcc -c $(SRC)/fibonnaci.c -I $(HEADERS) -o $(OBJ)/fibonnaci.o

testFib: libed
	gcc $(TEST)/testFib.c $(OBJ)/fibonnaci.o -I $(HEADERS) -o $(DIST)/testFib
	$(DIST)/testFib

testMap: libed
	gcc $(TEST)/testMap.c $(OBJ)/map.o $(OBJ)/fibonnaci.o -I $(HEADERS) -o $(DIST)/testMap
	$(DIST)/testMap

clean:
	rm $(DIST)/* $(OBJ)/*