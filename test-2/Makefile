OLD=g++ -o ./bin/compiler ./src/lex.yy.c ./src/y.tab.c -Wno-c++11-compat-deprecated-writable-strings -Wno-deprecated

all:
	yacc -d ./src/compiler.y
	mv y.tab.h ./include
	mv y.tab.c ./src

	lex ./src/compiler.l
	mv lex.yy.c ./src

	# clang++ -fsanitize=address -g -o ./bin/compiler ./src/lex.yy.c ./src/y.tab.c -Wno-c++11-compat-deprecated-writable-strings -Wno-deprecated
	g++ -o ./bin/compiler ./src/lex.yy.c ./src/y.tab.c -Wno-c++11-compat-deprecated-writable-strings -Wno-deprecated



clean:
	rm -f ./include/y.tab.h ./src/y.tab.c ./src/lex.yy.c ./bin/compiler