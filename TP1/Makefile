all:
	gcc ./src/main.c ./src/menu.c ./src/map.c -o ./dist/main
test_way:
	gcc ./test/main_test.c ./src/map.c ./test/test_way.c -o ./dist/test
run_test:
	dist/test 2
run:
	dist/main 1
clean:
	rm dist/main
clean_exec:
	rm dist/main.exe