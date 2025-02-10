all:
	yacc -d calculator.y
	lex calculator.l

	gcc -o calc lex.yy.c y.tab.c

run:
	./calc
