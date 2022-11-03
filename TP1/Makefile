APP = ./app
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
TEST = ./test

all:
	gcc ./src/main.c ./src/menu.c ./src/map.c -o ./dist/main

libed:
	gcc -c $(SRC)/sorting.c -I $(INCLUDE) -o $(OBJ)/sorting.o

test_way:
	gcc ./test/main_test.c ./src/map.c ./test/test_way.c -o ./dist/test
testFib:
	gcc $(TEST)/testFib.c -I $(INCLUDE) -o $(BIN)/testFib
	$(BIN)/testFib
run_test:
	dist/test 2
run:
	dist/main 1
clean:
	rm dist/main
clean_exec:
	rm dist/main.exe