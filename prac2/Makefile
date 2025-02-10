all:
	yacc -d c.y
	lex c.l

	gcc -o calc lex.yy.c y.tab.c

run:
	./calc
