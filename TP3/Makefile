all:
	gcc ./src/main.c ./src/menu.c ./src/pattern.c -o ./dist/main -lm
run:
	dist/main
test:
	gcc ./__test__/testPattern.c ./src/pattern.c -o ./dist/main_test -lm
result:
	gcc ./src/results.c ./src/simulationResults.c ./src/pattern.c -o ./dist/results -lm
	./dist/results
run_test:
	dist/main_test
clean_test:
	rm dist/main_test
clean:
	rm dist/*