APP = ./app
DIST = ./dist
HEADERS = ./headers
OBJ = ./obj
SRC = ./src
TEST = ./test

all:
	gcc ./src/main.c ./src/menu.c ./src/map.c -o ./dist/main

libed:
	gcc -c $(SRC)/fibonnaci.c -I $(HEADERS) -o $(OBJ)/fibonnaci.o

test_way:
	gcc ./test/main_test.c ./src/map.c ./test/test_way.c -o ./dist/test
testFib: libed
	gcc $(TEST)/testFib.c $(OBJ)/fibonnaci.o -I $(HEADERS) -o $(DIST)/testFib
	$(DIST)/testFib


run_test:
	dist/test 2
run:
	dist/main 1
clean:
	rm dist/main
clean_exec:
	rm dist/main.exe