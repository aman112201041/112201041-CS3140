all:
	yacc -d ./src/compiler.y
	mv y.tab.h ./include
	mv y.tab.c ./src

	lex ./src/compiler.l
	mv lex.yy.c ./src

	g++ -o ./bin/compiler ./src/lex.yy.c ./src/y.tab.c -Wno-c++11-compat-deprecated-writable-strings -Wno-deprecated


