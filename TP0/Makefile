all:
	gcc ./src/main.c ./src/menu.c ./src/frame.c -o ./dist/main
run:
	./dist/main
clean:
	rm dist/main
test:
	gcc ./__test__/main_test.c ./src/frame.c -o ./dist/main_test
run_test:
	dist/main_test
clean_test:
	rm dist/main_test