all:
	yacc -d ./src/calculator.y
	mv y.tab.h ./include
	mv y.tab.c ./src

	lex ./src/calculator.l
	mv lex.yy.c ./src

	gcc -o ./bin/calculator ./src/lex.yy.c ./src/y.tab.c

run:
	./bin/calculator
